// snowman.inc.c

static struct ObjectHitbox sRollingSphereHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 210,
    /* height:            */ 350,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

static const f32 sSnowmanHeadOffsetY = 175.0f;

// TODO: Move object trajectories to generalized location
static Trajectory sSnowmanPath[] = {
    TRAJECTORY_POS(0, /*pos*/  2501,  2662,  -975),
    TRAJECTORY_POS(1, /*pos*/  2533,  2560,  -800),
    TRAJECTORY_POS(2, /*pos*/  2566,  2300,  -500),
    TRAJECTORY_POS(3, /*pos*/  2600,  1884,   733),
    TRAJECTORY_POS(4, /*pos*/  2466,  1647,  1835),
    TRAJECTORY_POS(5, /*pos*/  2000,  1483,  2233),
    TRAJECTORY_POS(6, /*pos*/   766,  1321,  2400),
    TRAJECTORY_POS(7, /*pos*/  -872,  1190,  2033),
    TRAJECTORY_POS(8, /*pos*/ -3072,  1097,  1300),
    TRAJECTORY_POS(9, /*pos*/ -3805,   882,  -366),
    TRAJECTORY_POS(10, /*pos*/ -3758,   819, -1513),
    TRAJECTORY_POS(11, /*pos*/ -3145,   786, -2426),
    TRAJECTORY_POS(12, /*pos*/ -1658,   546, -2853),
    TRAJECTORY_POS(13, /*pos*/  -138,   300, -3000),
    TRAJECTORY_POS(14, /*pos*/  1966,  -192, -2800),
    TRAJECTORY_POS(15, /*pos*/  3066,  -456, -2800),
    TRAJECTORY_POS(16, /*pos*/  3933,  -461, -2999),
    TRAJECTORY_POS(17, /*pos*/  4266,  -188, -3433),
    TRAJECTORY_POS(18, /*pos*/  3901,  -402, -3800),
    TRAJECTORY_POS(19, /*pos*/  3133,  -579, -3866),
    TRAJECTORY_POS(20, /*pos*/  2033,  -855, -3800),
    TRAJECTORY_POS(21, /*pos*/   766, -1073, -3633),
    TRAJECTORY_POS(22, /*pos*/ -1100, -1142, -3744),
    TRAJECTORY_POS(23, /*pos*/ -2318, -1188, -3658),
    TRAJECTORY_POS(24, /*pos*/ -3318, -1228, -3375),
    TRAJECTORY_POS(25, /*pos*/ -4010, -1267, -2802),
    TRAJECTORY_POS(26, /*pos*/ -4470, -1368, -2151),
    TRAJECTORY_POS(27, /*pos*/ -4679, -1358, -1321),
    TRAJECTORY_POS(28, /*pos*/ -4770, -1333,  -648),
    TRAJECTORY_POS(29, /*pos*/ -4847, -1351,    40),
    TRAJECTORY_END(),
};

void bhv_snowmans_bottom_init(void) {
    vec3f_copy(&o->oHomeVec, &o->oPosVec);

    o->oGravity = 10.0f;
    o->oFriction = 0.999f;
    o->oBuoyancy = 2.0f;

    o->oVelY = 0;
    o->oForwardVel = 0;
    o->oSnowmansBottomScale = 0.4f;

    struct Object *snowmansHead = cur_obj_nearest_object_with_behavior(bhvSnowmansHead);
    if (snowmansHead != NULL) {
        o->parentObj = snowmansHead;
    }

    struct Object *midpoint = cur_obj_nearest_object_with_behavior(bhvSnowmanMidpoint);
    spawn_object_abs_with_rot(o, 0, MODEL_NONE, bhvSnowmansBodyCheckpoint, midpoint->oPosX, midpoint->oPosY, midpoint->oPosZ, 0, 0, 0);
}

void set_rolling_sphere_hitbox(void) {
    obj_set_hitbox(o, &sRollingSphereHitbox);

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }
}

void adjust_rolling_face_pitch(f32 f12) {
    o->oFaceAnglePitch += (s16)(o->oForwardVel * (100.0f / f12));
    o->oSnowmansBottomScale += o->oForwardVel * 0.0001f;

    if (o->oSnowmansBottomScale > 1.0f) {
        o->oSnowmansBottomScale = 1.0f;
    }
}

void snowmans_bottom_act_follow_path(void) {
    o->oPathedStartWaypoint = (struct Waypoint *) sSnowmanPath;
    object_step_without_floor_orient();
    s32 followStatus = cur_obj_follow_path();
    o->oSnowmansBottomTargetYaw = o->oPathedTargetYaw;
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oSnowmansBottomTargetYaw, 0x400);

    if (o->oForwardVel > 70.0f) {
        o->oForwardVel = 70.0f;
    }

    if (followStatus == PATH_REACHED_END) {
        if (obj_check_if_facing_toward_angle(o->oMoveAngleYaw, o->oAngleToMario, 0x2000)
         && o->oSnowmansBottomHitCheckpointNearMario) {
            o->oSnowmansBottomTargetYaw = o->oAngleToMario;
        } else {
            o->oSnowmansBottomTargetYaw = o->oMoveAngleYaw;
        }
        o->oAction = SNOWMANS_BOTTOM_ACT_FINAL_STRETCH;
    }
}

void snowmans_bottom_act_final_stretch(void) { // act 2
    object_step_without_floor_orient();

    if (o->oForwardVel > 70.0f) {
        o->oForwardVel = 70.0f;
    }

    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oSnowmansBottomTargetYaw, 0x400);
    if (is_point_close_to_object(o, 
        o->parentObj->oPosX, o->parentObj->oPosY-sSnowmanHeadOffsetY, o->parentObj->oPosZ, 300)) {
        spawn_mist_particles_variable(0, 0, 70.0f);
        o->oMoveAngleYaw = atan2s((o->parentObj->oPosZ - o->oPosZ), (o->parentObj->oPosX - o->oPosX));
        o->oVelY = 80.0f;
        o->oForwardVel = 15.0f;
        o->oAction = SNOWMANS_BOTTOM_ACT_REACH_END;

        o->parentObj->oAction = SNOWMANS_HEAD_ACT_JUMPING;
        o->parentObj->oVelY = 100.0f;
        cur_obj_play_sound_2(SOUND_OBJ_SNOWMAN_BOUNCE);
    }

    if (o->oTimer == 200) {
        create_respawner(MODEL_CCM_SNOWMAN_BASE, bhvSnowmansBottom, 3000);
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}

void snowmans_bottom_act_reach_end(void) { // act 3
    s16 collisionFlags = object_step_without_floor_orient();

    if ((collisionFlags & OBJ_COL_FLAGS_LANDED) == OBJ_COL_FLAGS_LANDED) {
        o->oAction = 4;
        cur_obj_become_intangible();
    }

    if (collisionFlags & OBJ_COL_FLAG_GROUNDED) {
        spawn_mist_particles_variable(0, 0, 70.0f);
        o->oPosX = o->parentObj->oPosX;
        o->oPosZ = o->parentObj->oPosZ;
        o->oForwardVel = 0.0f;
    }
}

void bhv_snowmans_bottom_loop(void) {
    switch (o->oAction) {
        case SNOWMANS_BOTTOM_ACT_WAITING:
            if (is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 400)
             && set_mario_npc_dialog(MARIO_DIALOG_LOOK_FRONT) == MARIO_DIALOG_STATUS_SPEAK) {
                if (cutscene_object_with_dialog(CUTSCENE_DIALOG, o, DIALOG_110)) {
                    o->oForwardVel = 10.0f;
                    o->oAction = SNOWMANS_BOTTOM_ACT_FOLLOW_PATH;
                    set_mario_npc_dialog(MARIO_DIALOG_STOP);
                }
            }
            break;

        case SNOWMANS_BOTTOM_ACT_FOLLOW_PATH:
            snowmans_bottom_act_follow_path();
            adjust_rolling_face_pitch(o->oSnowmansBottomScale);
            cur_obj_play_sound_1(SOUND_ENV_BOWLING_BALL_ROLL);
            break;

        case SNOWMANS_BOTTOM_ACT_FINAL_STRETCH:
            snowmans_bottom_act_final_stretch();
            adjust_rolling_face_pitch(o->oSnowmansBottomScale);
            cur_obj_play_sound_1(SOUND_ENV_BOWLING_BALL_ROLL);
            break;

        case SNOWMANS_BOTTOM_ACT_REACH_END:
            snowmans_bottom_act_reach_end();
            break;

        case SNOWMANS_BOTTOM_ACT_COLLISION:
            cur_obj_push_mario_away_from_cylinder(o->hitboxRadius, 550);
            break;
    }

    set_rolling_sphere_hitbox();
    set_object_visibility(o, 8000);
    cur_obj_scale(o->oSnowmansBottomScale);
    o->oGraphYOffset = o->oSnowmansBottomScale * 180.0f;
}

void bhv_snowmans_head_init(void) {
    u8 starFlags = save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum));
    u8 behParams = GET_BPARAM1(o->oBehParams);

    cur_obj_scale(0.7f);

    o->oGravity = 5.0f;
    o->oFriction = 0.999f;
    o->oBuoyancy = 2.0f;

    if ((starFlags & (1 << behParams)) && gCurrActNum != behParams + 1) {
        spawn_object_abs_with_rot(o, 0, MODEL_CCM_SNOWMAN_BASE, bhvBigSnowmanWhole, o->parentObj->oPosX, o->parentObj->oPosY, o->parentObj->oPosZ, 0, 0, 0);
        o->oPosX = o->parentObj->oPosX;
        o->oPosY = o->parentObj->oPosY + (sSnowmanHeadOffsetY*2.0f);
        o->oPosZ = o->parentObj->oPosZ;

        o->oAction = SNOWMANS_HEAD_ACT_NONE;
    }
}

void bhv_snowmans_head_loop(void) {
    s16 collisionFlags;

    switch (o->oAction) {
        case SNOWMANS_HEAD_ACT_ASK:
            if (trigger_obj_dialog_when_facing(&o->oSnowmansHeadDialogActive, DIALOG_109, 400.0f, MARIO_DIALOG_LOOK_FRONT)) {
                o->oAction = SNOWMANS_HEAD_ACT_NONE;
            }
            break;

        case SNOWMANS_HEAD_ACT_NONE:
            break;

        case SNOWMANS_HEAD_ACT_JUMPING:
            collisionFlags = object_step_without_floor_orient();
            if (collisionFlags & OBJ_COL_FLAG_NO_Y_VEL) {
                o->oAction = SNOWMANS_HEAD_ACT_LAND;
            }
            break;

        case SNOWMANS_HEAD_ACT_LAND:
            object_step_without_floor_orient();
            if (o->oPosY < -994.0f) {
                o->oPosY = -994.0f;
                o->oAction = SNOWMANS_HEAD_ACT_THANK;
                cur_obj_play_sound_2(SOUND_OBJ_SNOWMAN_EXPLODE);
                play_puzzle_jingle();
            }
            break;

        case SNOWMANS_HEAD_ACT_THANK:
            if (trigger_obj_dialog_when_facing(&o->oSnowmansHeadDialogActive, DIALOG_111, 700.0f, MARIO_DIALOG_LOOK_UP)) {
                spawn_mist_particles();
                spawn_default_star();
                o->oAction = SNOWMANS_HEAD_ACT_NONE;
            }
            break;
    }

    cur_obj_push_mario_away_from_cylinder(180.0f, 150.0f);
}

void bhv_snowmans_body_checkpoint_loop(void) {
    if (is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 800)) {
        o->parentObj->oSnowmansBottomHitCheckpointNearMario = TRUE;
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }

    if (o->parentObj->activeFlags == ACTIVE_FLAG_DEACTIVATED) {
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}
