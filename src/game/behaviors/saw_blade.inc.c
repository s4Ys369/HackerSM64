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
    /* hurtboxRadius:     */ 50,
    /* hurtboxHeight:     */ 900,
};

enum sSawWayPointModes {
    OBJ_MODE,
    SPLINE_MODE,
    NUM_WP_MODES
};

struct Object *hurtObj = NULL;
struct Object *sawArm = NULL;

const f32 sawRadiusX = 500.0f;
const f32 sawRadiusY = 450.0f;
const f32 hurtObjOffestX = 300.0f;
static u8 wayPointMode;
static s8 speed;

void bhv_saw_blade_init(void){
    wayPointMode = GET_BPARAM1(o->oBehParams);
    speed = (s8)GET_BPARAM2(o->oBehParams);

    cur_obj_enable_rendering();

    hurtObj = spawn_object_relative(0, -sawRadiusX, -sawRadiusY, 0, o, MODEL_BLUE_COIN, bhvSawBladeHitbox);
    hurtObj->oBehParams = o->oBehParams;
    vec3f_copy(&hurtObj->oHomeVec, &o->oHomeVec);
    hurtObj->oHomeX = hurtObj->oHomeX + sawRadiusX;
    hurtObj->oHomeY = hurtObj->oHomeY + sawRadiusY;

    sawArm = spawn_object(o, MODEL_SAW_ARM, bhvSawArm);
    sawArm->oBehParams = o->oBehParams;
    vec3f_copy(&sawArm->oHomeVec, &o->oHomeVec);

}

void bhv_saw_path_finding(void) {
    struct Object *wayPoint = cur_obj_nearest_object_with_behavior(bhvSawBladeWayPoint);
    switch(wayPointMode){
        case OBJ_MODE:
            o->oPosX += speed;
            if(wayPoint != NULL) {
                if(o->oPosX <= wayPoint->oPosX){
                    vec3f_copy(&o->oPosVec, &o->oHomeVec);
                }
            }
            break;
        case SPLINE_MODE:
            o->oForwardVel = speed;
            if (cur_obj_follow_path() == PATH_REACHED_END){
                vec3f_copy(&o->oPosVec, &o->oHomeVec);
            }
            break;
    }
}

void bhv_saw_blade_hitbox_loop(void){
    obj_set_hitbox(o,&sSawHitbox);
    f32 dist = o->hitboxRadius;

    struct Object *goomba = cur_obj_find_nearest_object_with_behavior(bhvGoomba,&dist);
    if(goomba != NULL && detect_object_hitbox_overlap(o,goomba)) {
        gCurrentObject = goomba;
        obj_die_if_health_non_positive();
        gCurrentObject = hurtObj;
        goomba = NULL;
    }

    bhv_saw_path_finding();
    if(o->oPosX > o->parentObj->oPosX - sawRadiusX)o->oPosX = o->parentObj->oPosX - sawRadiusX;

}

void bhv_saw_arm_loop(void){
    bhv_saw_path_finding();
}


void bhv_saw_blade_loop(void){

    bhv_saw_path_finding();
    print_text_fmt_int(5,40,"%d", wayPointMode);
    print_text_fmt_int(5,60,"%d", speed);

    cur_obj_play_sound_1(SOUND_GENERAL_ROLLING_LOG);

    // Floor check
    struct Surface *floor = cur_obj_update_floor_height_and_get_floor();
    if (floor != NULL && floor->type == SURFACE_DEFAULT){
        f32 dist = o->oFloorHeight - o->oPosY;
        if (dist >= -sawRadiusY){
            cur_obj_spawn_particles_offset(&sSawSparks, -hurtObjOffestX, -sawRadiusY, 0.0f);
            cur_obj_play_sound_2(SOUND_GENERAL2_SPINDEL_ROLL);
        }
    }
}