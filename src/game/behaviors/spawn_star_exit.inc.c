// spawn_star_exit.inc.c

void bhv_touched_star_spawn_loop(void) {
    /*
    * There's probably a more efficient way to achieve this,
    * but this allows for individual axis offsets, range [-128,127]
    * NOTE: Vanilla uses a Z offset of +141 units, but 14 units is a
    * worthy sacrifice. This visual difference is almost imperceptible.
    */
    s8 offsetX = GET_BPARAM2(o->oBehParams);
    s8 offsetY = GET_BPARAM3(o->oBehParams);
    s8 offsetZ = GET_BPARAM4(o->oBehParams);
    if (gEnteredArea2 & 1) {
        o->oPosX = o->oPosX + (f32)offsetX;
        o->oPosY += (f32)offsetY;
        o->oPosZ = o->oPosZ + (f32)offsetZ;
        spawn_default_star();
        obj_mark_for_deletion(o);
    }
}
