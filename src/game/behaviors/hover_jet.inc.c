void bhv_hover_jet_loop(void) {

    if(o->oTimer >= 10){
        play_sound(SOUND_ACTION_WATER_JUMP, gMarioState->pos);
        o->oTimer = 0;
    }


    f32 offset = 50.0f;

    // Compute the offset based on Mario's intended yaw
    f32 offsetX = sins(gMarioState->faceAngle[1]) * offset;
    f32 offsetZ = coss(gMarioState->faceAngle[1]) * offset;

    o->oPosX = gMarioState->pos[0] + offsetX;
    o->oPosY = gMarioState->pos[1] + 60.0f;
    o->oPosZ = gMarioState->pos[2] + offsetZ;

    o->oFaceAngleYaw = gMarioState->faceAngle[1];

    // Delete the object if Mario is no longer in an air action
    if (!(gMarioState->controller->buttonDown & L_TRIG)){
        o->header.gfx.node.flags &= ~GRAPH_RENDER_ACTIVE;
        mark_obj_for_deletion(o);
    }

    if (!(gMarioState->action & ACT_FLAG_AIR))mark_obj_for_deletion(o);
}