// treasure_chest.inc.c

/**
 * Hitbox for treasure chest bottom.
 */
static struct ObjectHitbox sTreasureChestBottomHitbox = {
    /* interactType:      */ INTERACT_SHOCK,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 300,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 310,
    /* hurtboxHeight:     */ 310,
};

void bhv_treasure_chest_top_loop(void) {
    struct Object *parent = o->parentObj->parentObj;

    switch (o->oAction) {
        case TREASURE_CHEST_TOP_ACT_CLOSED:
            if (o->parentObj->oAction == TREASURE_CHEST_BOTTOM_ACT_OPENING) {
                o->oAction = TREASURE_CHEST_TOP_ACT_OPENING;
            }
            break;

        case TREASURE_CHEST_TOP_ACT_OPENING:
            if (o->oTimer == 0) {
                if (parent->oTreasureChestAboveWater) {
                    play_sound(SOUND_GENERAL_OPEN_CHEST, o->header.gfx.cameraToObject);
                } else {
                    spawn_object_relative(0, 0, -80, 120, o, MODEL_BUBBLE, bhvWaterAirBubble);
                    play_sound(SOUND_GENERAL_OPEN_CHEST_WATER, o->header.gfx.cameraToObject);
                }
            }

            o->oFaceAnglePitch -= 0x200;
            if (o->oFaceAnglePitch < -0x4000) {
                o->oFaceAnglePitch = -0x4000;
                o->oAction = TREASURE_CHEST_TOP_ACT_OPENED;
                if (o->parentObj->oBehParams2ndByte != TREASURE_CHEST_BP_4) {
                    spawn_orange_number(o->parentObj->oBehParams2ndByte, 0, -40, 0);
                }
            }
            break;

        case TREASURE_CHEST_TOP_ACT_OPENED:
            if (o->parentObj->oAction == TREASURE_CHEST_BOTTOM_ACT_CLOSE) {
                o->oAction = TREASURE_CHEST_TOP_ACT_CLOSING;
            }
            break;

        case TREASURE_CHEST_TOP_ACT_CLOSING:
            o->oFaceAnglePitch += 0x800;
            if (o->oFaceAnglePitch > 0x0) {
                o->oFaceAnglePitch = 0x0;
                o->oAction = TREASURE_CHEST_TOP_ACT_CLOSED;
            }
    }
}

void bhv_treasure_chest_bottom_init(void) {
    spawn_object_relative(0, 0, 102, -77, o, MODEL_TREASURE_CHEST_LID, bhvTreasureChestTop);
    obj_set_hitbox(o, &sTreasureChestBottomHitbox);
}

void bhv_treasure_chest_bottom_loop(void) {
    switch (o->oAction) {
        case TREASURE_CHEST_BOTTOM_ACT_CLOSE:
            if ((!o->parentObj->oTreasureChestDoCloseChests)
                && is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 150)
                && obj_check_if_facing_toward_angle(o->oMoveAngleYaw, gMarioObject->header.gfx.angle[1] + 0x8000, 0x3000)) {
                if (o->parentObj->oTreasureChestNumOpenedChests == o->oBehParams2ndByte) {
                    play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                    o->parentObj->oTreasureChestNumOpenedChests++;
                    o->oAction = TREASURE_CHEST_BOTTOM_ACT_OPENING;
                } else {
                    o->parentObj->oTreasureChestNumOpenedChests = 1;
                    o->parentObj->oTreasureChestDoCloseChests = TRUE;
                    o->oAction = TREASURE_CHEST_BOTTOM_ACT_OPENED;
                    cur_obj_become_tangible();
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                }
            }
            break;

        case TREASURE_CHEST_BOTTOM_ACT_OPENING:
            if (o->parentObj->oTreasureChestDoCloseChests) {
                o->oAction = TREASURE_CHEST_BOTTOM_ACT_CLOSE;
            }
            break;

        case TREASURE_CHEST_BOTTOM_ACT_OPENED:
            cur_obj_become_intangible();
            if (!is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 500)) {
                o->parentObj->oTreasureChestDoCloseChests = FALSE;
                o->oAction = TREASURE_CHEST_BOTTOM_ACT_CLOSE;
            }
    }

    cur_obj_push_mario_away_from_cylinder(150.0f, 150.0f);
    o->oInteractStatus = INT_STATUS_NONE;
}

void bhv_treasure_chest_star_marker_init(void) {
    u8 starID = GET_BPARAM1(o->oBehParams);
    u8 lowerWater = GET_BPARAM2(o->oBehParams);

    if(lowerWater == FALSE){
        struct Object *starMarker = spawn_object_abs_with_rot(o, 0, MODEL_NONE, bhvDefaultStarMarker, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
        SET_BPARAM1(starMarker->oBehParams, starID);
    }
    o->oTreasureChestNumOpenedChests = 1;
}

void bhv_treasure_chest_init(void) {

    bhv_treasure_chest_bottom_init();
    cur_obj_become_intangible();

    // Copy of red coin function //

    // Find marker
    struct Object *treasureStar = cur_obj_nearest_object_with_behavior(bhvTreasureChestsStarMarker);

    // If there is a marker ...
    if (treasureStar != NULL) {

        // check BPARAM2 is 1 through 4
        if(o->oBehParams2ndByte > 0 && o->oBehParams2ndByte < 5){
            o->parentObj = treasureStar;
        } else {
            // Until N number of chests are allowed, just delete anything past 4
            mark_obj_for_deletion(o);
        }
    }

    // find_water_level re-implementation //
    s32 waterLevel, val, loX, hiX, loZ, hiZ;
    TerrainData *p = gEnvironmentRegions;

    waterLevel = 0;

    if (p != NULL) {
        s32 numRegions = *p++;

        // Calculate the AABB
        for (s32 i = 0; i < numRegions; i++) {
            val = *p++;
            loX = *p++;
            loZ = *p++;
            hiX = *p++;
            hiZ = *p++;

            // If the location is within a water box and it is a water box.
            // Water is less than 50 val only, while above is gas and such.
            if (loX < o->oPosX && o->oPosX < hiX && loZ < o->oPosZ && o->oPosZ < hiZ && val < 50) {
                // Set the water height. Since this breaks, only return the first height.
                waterLevel = *p;
                break;
            }
            p++;
        }

        if(o->oPosY < waterLevel){
            o->parentObj->oTreasureChestAboveWater = FALSE;
        } else {
            o->parentObj->oTreasureChestAboveWater = TRUE;
        }

    }
    
}

void bhv_treasure_chest_loop(void) {
    u8 lowerWater = GET_BPARAM2(o->oBehParams);
    s32 val = 0;
    TerrainData *p = gEnvironmentRegions;
    s32 *waterRegion = NULL;

    switch (o->oAction) {
        case TREASURE_CHEST_ACT_SUCCESS_SOUND:
            if (o->oTreasureChestNumOpenedChests == 5) {
                play_puzzle_jingle();
                if(lowerWater)fade_volume_scale(0, 127, 1000);
                o->oAction = TREASURE_CHEST_ACT_REWARD;
            }
            break;

        case TREASURE_CHEST_ACT_REWARD:
            if(lowerWater){
                s16 targetWaterLevel = GET_BPARAM34(o->oBehParams);
                if (p != NULL) {
                    s32 numRegions = *p++;

                    // Find the water region with val < 50
                    for (s32 i = 0; i < numRegions; i++) {
                        val = *p++; // Get the value of the region (height identifier)
                        p += 4;     // Skip loX, loZ, hiX, hiZ

                        // If this is a water region (val < 50), store the pointer
                        if (val < 50) {
                            waterRegion = (s32 *)p; // Point to the water height (next element)
                            break;                  // Exit the loop after finding the first water region
                        }
                        p++; // Skip water level (height value)
                    }

                    // If we found a water region, decrement its height
                    if (waterRegion != NULL) {
                        *waterRegion -= 5;
                        play_sound(SOUND_ENV_WATER_DRAIN, gGlobalSoundSource);
                        set_environmental_camera_shake(SHAKE_ENV_JRB_SHIP_DRAIN);

                        // Clamp the water level to the target level
                        if (*waterRegion < targetWaterLevel) {
                            *waterRegion = targetWaterLevel;
                            o->oTreasureChestDoCloseChests = FALSE;
                            o->oAction = TREASURE_CHEST_ACT_END;
                        }
                    }
#if ENABLE_RUMBLE
                    reset_rumble_timers_vibrate(2);
#endif
                }
            } else {
                if (o->oTimer == 60) {
                    spawn_mist_particles();
                    spawn_default_star();
                    o->oAction = TREASURE_CHEST_ACT_END;
                }
            }
            break;

        case TREASURE_CHEST_ACT_END:
            break;
    }
}
