#include <string.h>
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

struct Object *hurtObj = NULL;
struct Object *sawArm = NULL;
s8 speed = 0;
void bhv_saw_blade_init(void){
    speed = (s8)GET_BPARAM2(o->oBehParams);

    cur_obj_enable_rendering();

    // Hitbox for the front edge of the blade
    hurtObj = spawn_object_relative(0, -500, -450, 0, o, MODEL_NONE, bhvSawBladeHitbox);
    sawArm = spawn_object(o, MODEL_SAW_ARM, bhvSawArm);
    hurtObj->oBehParams = o->oBehParams;

}

void bhv_saw_blade_hitbox_loop(void){
    f32 dist = 50.0f;
    struct Object *goomba = cur_obj_find_nearest_object_with_behavior(bhvGoomba,&dist);
    obj_set_hitbox(o,&sSawHitbox);
    if(goomba != NULL && detect_object_hitbox_overlap(o,goomba)) {
        gCurrentObject = goomba;
        obj_die_if_health_non_positive();
        gCurrentObject = hurtObj;
        goomba = NULL;
    }
    o->oPosX += speed;
    if(o->oPosX <= -3000.0f)mark_obj_for_deletion(o);
}

void bhv_saw_arm_loop(void){
    o->oPosX += speed;
    if(o->oPosX <= -3000.0f)mark_obj_for_deletion(o);
}


void bhv_saw_blade_loop(void){

    o->oPosX += speed;

    if(o->oPosX <= -3000.0f){
        create_respawner(MODEL_SAW_BLADE, bhvSawBlade, 0);
        mark_obj_for_deletion(o);  
    }

    cur_obj_play_sound_1(SOUND_GENERAL_ROLLING_LOG);

    // Floor check
    struct Surface *floor = cur_obj_update_floor_height_and_get_floor();
    if (floor != NULL && floor->type == SURFACE_DEFAULT){
        f32 dist = o->oFloorHeight - o->oPosY;
        if (dist >= -450.0f){
            cur_obj_spawn_particles_offset(&sSawSparks, -300.0f, -450.0f, 0.0f);
            cur_obj_play_sound_2(SOUND_GENERAL2_SPINDEL_ROLL);
        }
    }
}