void hover_jet_set_offset(f32 offset){

    // Compute the offset based on Mario's forward
    f32 offsetX = sins(gMarioState->faceAngle[1]) * offset;
    f32 offsetZ = coss(gMarioState->faceAngle[1]) * offset;

    o->oPosX = gMarioState->pos[0] + offsetX;
    o->oPosZ = gMarioState->pos[2] + offsetZ;
}

void bhv_hover_jet_init(void){
    cur_obj_play_sound_2(SOUND_GENERAL_MOVING_WATER);

    o->oPosY = gMarioState->pos[1] + 80.0f;
    hover_jet_set_offset(50.0f);

    o->oDrawingDistance = 500.0f;
}

void bhv_hover_jet_loop(void) {

    cur_obj_play_sound_2(SOUND_ENV_WATER_DRAIN);

    cur_obj_update_floor_and_walls();
    if(o->header.gfx.scale[1] < 5.0f)o->header.gfx.scale[1] += 1.0f;
    o->oPosY -= 60.0f;

    // Delete the object if outside draw distance or grounded
    s16 collisionFlags = object_step();
    if (o->oPosY <= -499.0f || collisionFlags & OBJ_COL_FLAG_GROUNDED) {
        cur_obj_play_sound_1(SOUND_OBJ_JUMP_WALK_WATER);
        spawn_mist_particles_variable(5,0,10.0f);
        o->header.gfx.node.flags &= ~GRAPH_RENDER_ACTIVE;
        mark_obj_for_deletion(o);
    }
}