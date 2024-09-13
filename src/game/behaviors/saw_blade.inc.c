static struct SpawnParticlesInfo sSawSparks = {
    /* behParam:        */ 3,
    /* count:           */ 20,
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
    /* height:            */ 1100,
    /* hurtboxRadius:     */ 50,
    /* hurtboxHeight:     */ 1200,
};

struct Object *hurtObj = NULL;
void bhv_saw_blade_init(void){
    hurtObj = spawn_object_relative(0, -500, 0, 0, o, MODEL_NONE, bhvSawBladeHitbox);
}

void bhv_saw_blade_hitbox_loop(void){
    obj_set_hitbox(o,&sSawHitbox);
    o->hitboxDownOffset = o->parentObj->header.gfx.scale[1] * 500.0f;
    o->oPosX -= 20.0f;
}


void bhv_saw_blade_loop(void){
    o->oPosX -= 20.0f;
    cur_obj_spawn_particles_offset(&sSawSparks, -300.0f, -450.0f, 0.0f);
}