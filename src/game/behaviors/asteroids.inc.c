static struct ObjectHitbox sAsteroidBigHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 200,
    /* height:            */ 360,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};
static struct ObjectHitbox sAsteroidMediumHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 360,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};
static struct ObjectHitbox sAsteroidSmallHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 50,
    /* height:            */ 360,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_asteroid_spawner_update(void) {
    struct Object *ast;
    if (o->oAction < 3) {
        s16 dx = ((s16) random_sign() * random_u16()) % 1500;
        s16 dz = ((s16) random_sign() * random_u16()) % 1250;
        ast = spawn_object_relative(2, dx, 200, dz, o, MODEL_ASTEROID, bhvAsteroid);
        ast->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
        o->oAction++;
    }
}

void bhv_asteroid_init(void) {
    f32 scale = 1.0f;

    switch(o->oBehParams2ndByte) {
        case 0:
            scale = 0.25f;
            obj_set_hitbox(o, &sAsteroidSmallHitbox);
            break;
        case 1:
            scale = 0.5f;
            obj_set_hitbox(o, &sAsteroidMediumHitbox);
            break;
        case 2:
            scale = 1.0f;
            obj_set_hitbox(o, &sAsteroidBigHitbox);
            break;
    }

    cur_obj_scale(scale);
    cur_obj_become_intangible();

    o->oForwardVel = random_float() * 20.0f;
    o->oFaceAngleYaw = (s16)random_sign() * random_u16();
    o->oMoveAngleYaw = (s16)random_sign() * random_u16();
    
}
void bhv_asteroid_update(void) {
    if (o->oTimer < 10) {
        cur_obj_unhide();
        cur_obj_become_tangible();
    }
    
    if (o->oPosX < -1200.0f) {
        o->oPosX = 1200.0f;
    }
    if (o->oPosX > 1200.0f) {
        o->oPosX = -1200.0f;
    }
    if (o->oPosZ < -1000.0f) {
        o->oPosZ = 800.0f;
    }
    if (o->oPosZ > 800.0f) {
        o->oPosZ = -1000.0f;
    }

    if(o->oInteractStatus & (INT_STATUS_TOUCHED_BOB_OMB | INT_STATUS_TOUCHED_MARIO)) {
        switch(o->oBehParams2ndByte) {
        case 0:
            //spawn_object(o, MODEL_BLUE_COIN, bhvMrIBlueCoin);
            obj_mark_for_deletion(o);
            break;
        case 1:
            spawn_object_relative(0, 50, 0, 0, o, MODEL_ASTEROID, bhvAsteroid);
            spawn_object_relative(0, -50, 0, 0, o, MODEL_ASTEROID, bhvAsteroid);
            obj_mark_for_deletion(o);
            break;
        case 2:
            o->parentObj->oAction -= 1;
            spawn_object_relative(1, 100, 0, 0, o, MODEL_ASTEROID, bhvAsteroid);
            spawn_object_relative(1, -100, 0, 0, o, MODEL_ASTEROID, bhvAsteroid);
            obj_mark_for_deletion(o);
            break;
        }
    }

    cur_obj_move_standard(78);
}