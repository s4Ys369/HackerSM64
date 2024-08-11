//title.inc.c

void bhv_ufo_title_init(void) {
    o->oFaceAngleYaw = 0;
}

void bhv_ufo_title_update(void) {
    cur_obj_scale(2.0f);
    o->oFaceAngleYaw += 0xB00;
    o->oPosY += coss(0x400 * o->oTimer) * 3.0f;
    if (o->oTimer >= 50 && o->oTimer < 72) {
        o->oPosX += 100.0f;
    } else if (o->oTimer >= 72 && o->oTimer < 90) {
        o->oVelX = 0.0f;
    } else if (o->oTimer == 90) {
        cur_obj_play_sound_2(SOUND_OBJ2_BOWSER_TELEPORT);
    } else if (o->oTimer >= 110) {
        o->oPosX += 40.0f;
    } else if (o->oTimer > 300) {
        obj_mark_for_deletion(o);
    }
}

void bhv_subtitle_init(void) {
    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    cur_obj_scale(4.0f);
}

void bhv_subtitle_update(void) {

    switch (o->oTimer) {
        case 40:
            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            cur_obj_play_sound_2(SOUND_MENU_CAMERA_BUZZ);
            break;
        case 42:
            o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            break;
        case 44:
            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            cur_obj_play_sound_2(SOUND_MOVING_SHOCKED);
            break;
        case 45:
            o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            break;
        case 50:
            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            cur_obj_play_sound_2(SOUND_AIR_AMP_BUZZ);
            break;
        case 90:
            o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            break;
        case 92:
            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            cur_obj_play_sound_2(SOUND_AIR_AMP_BUZZ);
            break;
        case 94:
            o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            break;
        case 96:
            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            cur_obj_play_sound_2(SOUND_AIR_AMP_BUZZ);
            break;
        case 110:
            o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            cur_obj_play_sound_2(SOUND_MOVING_SHOCKED);
            break;
        case 300:
            obj_mark_for_deletion(o);
            break;
    }
}