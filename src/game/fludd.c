#include <PR/ultratypes.h>

#include "sm64.h"
#include "behavior_data.h"
#include "mario_actions_airborne.h"
#include "area.h"
#include "audio/external.h"
#include "camera.h"
#include "engine/graph_node.h"
#include "engine/math_util.h"
#include "game_init.h"
#include "interaction.h"
#include "level_update.h"
#include "mario.h"
#include "mario_step.h"
#include "save_file.h"
#include "rumble_init.h"

#include "config.h"

#include "fludd.h"

static u8 isWearingFludd = FALSE;
u32 waterLevel = 160;

u8 wearing_fludd(struct MarioState *m) {
    ModelID32 modelID = 0;
    if(m->heldObj != NULL){
        modelID = obj_get_model_id(m->heldObj);
    } else {
        return FALSE;
    }

    if(modelID == MODEL_FLUDD){
        isWearingFludd = TRUE;
        return TRUE;
    } else {
        isWearingFludd = FALSE;
        return FALSE;
    }
}

void fludd_reset_water_level(struct MarioState *m){
    waterLevel = 160;
    m->breath = 0x880;
}

void fludd_refill_water_level(struct MarioState *m){
    if(m->input & INPUT_IN_WATER){
        waterLevel = 160;
        m->breath = 0x880;
    }
}

void fludd_hover(struct MarioState *m) {

    if(waterLevel <= 1){
        return;
    }


    if (m->controller->buttonPressed & B_BUTTON) {
        spawn_mist_particles_variable(10, -10, 7.0f);
        set_mario_action(m, ACT_HOLD_FREEFALL, 0);
        spawn_object_relative(0, 0, 0, 0, m->marioObj, MODEL_HOVER_JET, bhvHoverJet);
    }

    if ((m->controller->buttonDown & B_BUTTON)) {
        waterLevel--;

        if (waterLevel % 2 == 0) {
            spawn_object_relative(0, 0, 0, 0, m->marioObj, MODEL_HOVER_JET, bhvHoverJet);
        }

        if (m->breath >= 0x100 && (waterLevel % 20 == 0)) {
            m->breath -= 0x100;
        }
        if (m->breath < 0x100) {
            // If breath is "zero", set health to "zero"
            m->breath =  0xFF;
        }

        if (m->vel[1] < -37.5f) {
            m->vel[1] = -37.5f;
        } else {
            m->vel[1] += 3.9f;
        }

    }
}