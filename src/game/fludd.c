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

u8 isWearingFludd = TRUE;

u8 wearing_fludd(struct MarioState *m) {
    ModelID32 modelID = 0;
    if(m->heldObj != NULL)modelID = obj_get_model_id(m->heldObj);

    if(modelID == MODEL_FLUDD){
        return TRUE;
    } else {
        return FALSE;
    }
}

void fludd_hover(struct MarioState *m){
    struct Object *hoverJet = NULL;
    if (m->controller->buttonPressed & L_TRIG){
        set_mario_action(m, ACT_HOLD_FREEFALL, 0);
        spawn_mist_particles();
        play_sound(SOUND_ACTION_WATER_JUMP, m->pos);
        if(hoverJet == NULL)hoverJet = spawn_object_relative(0,0,0,0,m->marioObj, MODEL_HOVER_JET, bhvHoverJet);
    }
    if (m->controller->buttonDown & L_TRIG){
        if(m->vel[1] < 2.0f)m->vel[1] += 3.9f; 
    }
}