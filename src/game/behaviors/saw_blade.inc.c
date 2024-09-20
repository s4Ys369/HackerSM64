#include "../object_collision.h"

static struct SpawnParticlesInfo sSawSparks = {
    /* behParam:        */ 3,
    /* count:           */ 3,
    /* model:           */ MODEL_SPARKLES,
    /* offsetY:         */ 0,
    /* forwardVelBase:  */ 10,
    /* forwardVelRange: */ 10,
    /* velYBase:        */ 0,
    /* velYRange:       */ 0,
    /* gravity:         */ 0,
    /* dragStrength:    */ 30,
    /* sizeBase:        */ 30.0f,
    /* sizeRange:       */ 1.5f,
};

struct ObjectHitbox sSawHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 4,
    /* health:            */ 1,
    /* numLootCoins:      */ 3,
    /* radius:            */ 50,
    /* height:            */ 900,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 900,
};

enum sSawWayPointModes {
    OBJ_MODE,
    SPLINE_MODE,
    NUM_WP_MODES
};

enum sSawWayPointBP {
    END_POINT,
    TRIGGER_POINT,
};

struct Object *hurtObj = NULL;
struct Object *sawArm = NULL;

const f32 sawRadiusX = 500.0f;
const f32 sawRadiusY = 450.0f;
const f32 hurtObjOffestX = 300.0f;

void bhv_saw_blade_init(void){
    o->oSawWayPointID = (s32)GET_BPARAM1(o->oBehParams);
    o->oForwardVel = (s8)o->oBehParams2ndByte;
    o->oSawPastEndPoint = 0;
    o->oSawPastTriggerPoint = 0;

    cur_obj_enable_rendering();

    // Determine the offset based on the direction of movement (positive or negative)
    f32 offsetX = (o->oForwardVel >= 0) ? sawRadiusX : -sawRadiusX;

    // Spawn the hurt object with the calculated offset
    hurtObj = spawn_object_relative(0, -offsetX, -sawRadiusY, 0, o, MODEL_NONE, bhvSawBladeHitbox);
    hurtObj->oBehParams = o->oBehParams;

    // Set hurtObj's home position relative to the saw's home position
    vec3f_copy(&hurtObj->oHomeVec, &o->oHomeVec);
    hurtObj->oHomeX = hurtObj->oHomeX + offsetX; // Apply calculated offset based on movement direction
    hurtObj->oHomeY = hurtObj->oHomeY + sawRadiusY;

    // Set the other relevant parameters for hurtObj
    hurtObj->oForwardVel = o->oForwardVel;
    hurtObj->oSawWayPointID = o->oSawWayPointID;
    hurtObj->oSawPastEndPoint = o->oSawPastEndPoint;
    hurtObj->oSawPastTriggerPoint = o->oSawPastTriggerPoint;

    sawArm = spawn_object(o, MODEL_SAW_ARM, bhvSawArm);
    sawArm->oBehParams = o->oBehParams;
    sawArm->oForwardVel = o->oForwardVel;
    sawArm->oSawWayPointID = o->oSawWayPointID;
    sawArm->oSawPastEndPoint = o->oSawPastEndPoint;
    sawArm->oSawPastTriggerPoint = o->oSawPastTriggerPoint;
    vec3f_copy(&sawArm->oHomeVec, &o->oHomeVec); //

}

void bhv_saw_path_finding(void) {
    struct Object *wayPoint = cur_obj_nearest_object_with_behavior(bhvSawBladeWayPoint);
    if(o->oSawPastTriggerPoint == 1 && o->oPosY < o->oHomeY + 600.0f) {
        approach_f32_ptr(&o->oPosY, o->oPosY + 1000.0f, 10.0f);
    }
    if(o->oSawPastEndPoint == 1) {
        vec3f_copy(&o->oPosVec, &o->oHomeVec);
        o->oSawPastEndPoint = 0;
    }

    o->oPosX += o->oForwardVel;
    if((wayPoint != NULL) && ((s32)GET_BPARAM1(wayPoint->oBehParams) == o->oSawWayPointID)) {
        if(absf(o->oPosX - wayPoint->oPosX) <= 50.0f) {
            if(wayPoint->oBehParams2ndByte == END_POINT) {
                vec3f_copy(&o->oPosVec, &o->oHomeVec);
                o->oSawPastTriggerPoint = 0;
                o->oSawPastEndPoint = 1;
            }
            if(wayPoint->oBehParams2ndByte == TRIGGER_POINT) {
                o->oSawPastTriggerPoint = 1;
            }
        }
        
    }

}

void bhv_saw_blade_hitbox_loop(void){
    obj_set_hitbox(o,&sSawHitbox);
    f32 dist = o->hitboxRadius;

    struct Object *goomba = cur_obj_find_nearest_object_with_behavior(bhvGoomba,&dist);
    if(goomba != NULL && detect_object_hitbox_overlap(o,goomba)) {
        obj_die(goomba);
    }

    bhv_saw_path_finding();
    // Calculate offset based on forward velocity (positive for forward, negative for backward)
    f32 offsetX = (o->oForwardVel >= 0) ? sawRadiusX : -sawRadiusX;

    // Adjust position based on the parent object's position and the offset.
    if (absf(o->oPosX - o->parentObj->oPosX) > 10.0f) {
        o->oPosX = o->parentObj->oPosX + offsetX;
    }

}

void bhv_saw_arm_loop(void){
    bhv_saw_path_finding();
}


void bhv_saw_blade_loop(void){

    bhv_saw_path_finding();

    cur_obj_play_sound_1(SOUND_GENERAL_ROLLING_LOG);

    // Floor check
    struct Surface *floor = cur_obj_update_floor_height_and_get_floor();
    f32 sparkOffsetX = (o->oForwardVel >= 0) ? hurtObjOffestX : -hurtObjOffestX;
    if (floor != NULL && floor->type == SURFACE_DEFAULT){
        f32 dist = o->oFloorHeight - o->oPosY;
        if (dist >= -sawRadiusY){
            cur_obj_spawn_particles_offset(&sSawSparks, sparkOffsetX, -sawRadiusY, 0.0f);
            cur_obj_play_sound_2(SOUND_GENERAL2_SPINDEL_ROLL);
        }
    }
}