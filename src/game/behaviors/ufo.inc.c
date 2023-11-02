void bhv_ufo_warp_init(void) {
    cur_obj_scale(2.0f);
    o->oFaceAngleYaw = 0;
    set_object_respawn_info_bits(o, RESPAWN_INFO_DONT_RESPAWN);
}

void bhv_ufo_warp_update(void) {
    o->oFaceAngleYaw += 0xB00;
    o->oPosY += coss(0x400 * o->oTimer) * 3.0f;
    if (o->oTimer % 15 == 0) {
        if (o->oTimer < 100) {
            cur_obj_play_sound_2(SOUND_OBJ_WIGGLER_LOW_PITCH);  
        }
    }
    if (o->oTimer >= 75) {
        o->oPosY += 100.0f;
    } else if (o->oTimer > 90) {
        obj_mark_for_deletion(o);
    }
}