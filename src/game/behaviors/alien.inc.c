void bhv_alien_init(void) {
    cur_obj_scale(0.75f);
    o->oGravity = 2.5f;
    o->oFriction = 0.8f;
    o->oBuoyancy = 1.3f;
    o->oInteractionSubtype = INT_SUBTYPE_NPC;
}

void alien_act_idle(void) {
    cur_obj_init_animation(0);

    object_step();

    if (o->oDistanceToMario < 1000.0f) {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);
    }

    if (o->oInteractStatus == INT_STATUS_INTERACTED) {
        o->oAction = BOBOMB_BUDDY_ACT_TURN_TO_TALK;
    }
}

void alien_act_talk(void) {
    if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_SPEAK) {
        o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        o->header.gfx.animInfo.curAnim = NULL;
        if (cutscene_object_with_dialog(CUTSCENE_DIALOG, o, o->oBehParams2ndByte) != BOBOMB_BUDDY_BP_STYPE_GENERIC) {
            set_mario_npc_dialog(MARIO_DIALOG_STOP);
            o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
            o->oBobombBuddyHasTalkedToMario = BOBOMB_BUDDY_HAS_TALKED;
            o->oInteractStatus = INT_STATUS_NONE;
            o->oAction = BOBOMB_BUDDY_ACT_IDLE;
        }
    }
}

void alien_turn_to_talk(void) {
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);

    if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
        o->oAction = BOBOMB_BUDDY_ACT_TALK;
    }

    cur_obj_play_sound_2(SOUND_ACTION_READ_SIGN);
}

void alien_actions(void) {
    switch (o->oAction) {
        case BOBOMB_BUDDY_ACT_IDLE:
            alien_act_idle();
            break;

        case BOBOMB_BUDDY_ACT_TURN_TO_TALK:
            alien_turn_to_talk();
            break;

        case BOBOMB_BUDDY_ACT_TALK:
            alien_act_talk();
            break;
    }

    set_object_visibility(o, 3000);
}

void bhv_alien_loop(void) {
    alien_actions();

    curr_obj_random_blink(&o->oBobombBuddyBlinkTimer);

    o->oInteractStatus = INT_STATUS_NONE;
}