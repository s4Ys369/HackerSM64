// kamek.inc.c
static struct ObjectHitbox sKamekHitbox = {
    /* interactType:      */ INTERACT_BREAKABLE,
    /* downOffset:        */ 175,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 10,
    /* numLootCoins:      */ 0,
    /* radius:            */ 125,
    /* height:            */ 400,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void kamek_init(void) {
    cur_obj_set_pos_to_home();
    obj_set_hitbox(o, &sKamekHitbox);
    o->oInteractStatus = INT_STATUS_NONE;

    if (o->oSubAction == 0) {
        if (o->oDistanceToMario < 4000.0f) {
            o->oSubAction++;
            gSecondCameraFocus = o;
        }
    } else if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, 
        DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_116)) {
        o->oAction = 1;
    }
}

void kamek_chase(void) {
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x200);

    if (o->oTimer > 120) {
        s16 marioAngle = abs_angle_diff(o->oAngleToMario, o->oMoveAngleYaw);
        if (marioAngle < 0x2000) {
            if (o->oDistanceToMario < 2500.0f) {
                o->oAction = 2;
            }
        }
    }

    if (cur_obj_was_attacked_or_ground_pounded()) {
        o->oHealth--;
        cur_obj_play_sound_2(SOUND_OBJ_KOOPA_DAMAGE);
        if (o->oHealth == 0) {
            o->oAction = 4;
        } else {
            spawn_mist_particles_variable(0, 0, 100.0f);
            spawn_triangle_break_particles(20, MODEL_DIRT_ANIMATION, 3.0f, 4);
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            cur_obj_push_mario_away(150.0f);
            o->oAction = 3;
        }
    }
}

void kamek_attack(void) {
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x200);
    if (o->oHealth < 6) {
    	spawn_object_relative(2, -150, 100, 350, o, MODEL_BULLET_BILL, bhvBulletBill);
    	spawn_object_relative(0, 0, 0, 350,o, MODEL_BLUE_FLAME, bhvFlameMovingForwardGrowing);
    }
    if (o->oTimer >= 20) {
        spawn_object_relative(0, 0, 0, 350,o, MODEL_RED_FLAME, bhvFlameMovingForwardGrowing);
        o->oAction = 1;
    }
}

void kamek_cooldown(void) {
    cur_obj_wait_then_blink(10,30);
    cur_obj_become_intangible();
    if (o->oTimer >= 60) {
    	if (o->oHealth < 4) {
    		spawn_object_relative(0, 0, 0, 350,o, MODEL_AMP, bhvHomingAmp);
    	}
        o->oInteractStatus = INT_STATUS_NONE;
        cur_obj_become_tangible();
        o->oAction = 1;
    }
}


void kamek_die(void) {
    obj_set_angle(o, 0, 0, 0);
    cur_obj_hide();
    cur_obj_become_intangible();
    spawn_mist_particles_variable(0, 0, 200.0f);
    spawn_triangle_break_particles(20, MODEL_DIRT_ANIMATION, 3.0f, 4);
    cur_obj_shake_screen(SHAKE_POS_SMALL);
    o->oPosY += 100.0f;
    struct Object *wand = spawn_object_abs_with_rot(o, 0, MODEL_WAND, bhvGrandStar, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
    wand->oBehParams = o->oBehParams;
    wand->oFaceAnglePitch = 0;
    wand->oFaceAngleRoll = 0;
    cur_obj_play_sound_2(SOUND_OBJ_KING_WHOMP_DEATH);
    o->oAction = 5;
}

void kamek_stop_music(void) {
    if (o->oTimer == 60) {
        obj_mark_for_deletion(o);
    }
}

ObjActionFunc sKamekActions[] = {
    kamek_init,
    kamek_chase,
    kamek_attack,
    kamek_cooldown,
    kamek_die,
    kamek_stop_music,
};

void bhv_kamek_loop(void) {
    cur_obj_update_floor_and_walls();
    cur_obj_call_action_function(sKamekActions);
    cur_obj_move_standard(-20);
    o->oInteractStatus = INT_STATUS_NONE;
    if(o->oHealth == 0) {
        cur_obj_hide();
        cur_obj_become_intangible();
    }

    if (o->oAction < 4) {
    	if (o->oDistanceToMario < 3000.0f) {
			print_text_fmt_int(22, 10, "KAMEK %d", o->oHealth);
		}
        cur_obj_hide_if_mario_far_away_y(6000.0f);
    }
}
