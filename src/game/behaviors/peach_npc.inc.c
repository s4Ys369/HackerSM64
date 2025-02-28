void bhv_peach_npc_init(void) {
    o->oGravity = 2.5f;
    o->oOpacity = 255.0f; 
    o->oFriction = 0.8f;
    o->oBuoyancy = 1.3f;
    o->oInteractionSubtype = INT_SUBTYPE_NPC;
}

void peach_npc_act_idle(void) {
    if (o->oBobombBuddyHasTalkedToMario != BOBOMB_BUDDY_HAS_TALKED) {
        cur_obj_init_animation(PEACH_ANIM_WAVING);
    } else {
        cur_obj_init_animation(PEACH_ANIM_DIALOG_1_PART_3);
    }

    object_step();

    if (o->oDistanceToMario < 1000.0f && o->oBobombBuddyHasTalkedToMario != BOBOMB_BUDDY_HAS_TALKED) {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);
    }

    if (o->oInteractStatus == INT_STATUS_INTERACTED) {
        o->oAction = BOBOMB_BUDDY_ACT_TURN_TO_TALK;
    }
}

void peach_npc_act_talk(void) {
    if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_SPEAK) {
        o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        if (cutscene_object_with_dialog(CUTSCENE_DIALOG, o, o->oBehParams2ndByte) != BOBOMB_BUDDY_BP_STYPE_GENERIC) {
            set_mario_npc_dialog(MARIO_DIALOG_STOP);
            o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
            o->oBobombBuddyHasTalkedToMario = BOBOMB_BUDDY_HAS_TALKED;
            cur_obj_init_animation(PEACH_ANIM_DIALOG_1_PART_2);
            o->oInteractStatus = INT_STATUS_NONE;
            o->oAction = BOBOMB_BUDDY_ACT_IDLE;
        }
    }
}

void peach_npc_act_turn_to_talk(void) {
    cur_obj_init_animation(PEACH_ANIM_DIALOG_1_PART_2);

    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);

    if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
        o->oAction = BOBOMB_BUDDY_ACT_TALK;
    }

    cur_obj_play_sound_2(SOUND_ACTION_READ_SIGN);
}

void peach_npc_actions(void) {
    switch (o->oAction) {
        case BOBOMB_BUDDY_ACT_IDLE:
            peach_npc_act_idle();
            break;

        case BOBOMB_BUDDY_ACT_TURN_TO_TALK:
            peach_npc_act_turn_to_talk();
            break;

        case BOBOMB_BUDDY_ACT_TALK:
            peach_npc_act_talk();
            break;
    }

    set_object_visibility(o, 3000);
}

void bhv_peach_npc_loop(void) {
    peach_npc_actions();

    curr_obj_random_blink(&o->oBobombBuddyBlinkTimer);

    o->oInteractStatus = INT_STATUS_NONE;
}