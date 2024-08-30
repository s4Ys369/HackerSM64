// spawn_star_exit.inc.c

void bhv_touched_star_spawn_loop(void) {
    f32 offsetX = (f32)GET_BPARAM2(o->oBehParams);
    f32 offsetY = (f32)GET_BPARAM3(o->oBehParams);
    f32 offsetZ = (f32)GET_BPARAM4(o->oBehParams);
    if (gEnteredArea2 & 1) {
        o->oPosX = o->oPosX + offsetX;
        o->oPosY += offsetY;
        o->oPosZ = o->oPosZ + offsetZ;
        spawn_default_star();
        obj_mark_for_deletion(o);
    }
}
