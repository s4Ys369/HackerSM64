#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"
#include "make_const_nonconst.h"
#include "levels/tutorial/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_tutorial_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x7, _tutorial_segment_7SegmentRomStart, _tutorial_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO_SHELL, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, tutorial_area_1),
		WARP_NODE(0x0A, LEVEL_TUTORIAL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE_GROUNDS, 0x01, 0x04, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_TUTORIAL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, -180, 0, 280, 7400),
		OBJECT(MODEL_NONE, 0, 280, 7400, 0, -180, 0, (0x0A << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_BLACK_BOBOMB, -214, 251, 7109, 0, 0, 0, (DIALOG_170 << 16), bhvBobombBuddy),
		OBJECT(MODEL_BLACK_BOBOMB, -214, 251, 5270, 0, 0, 0, (DIALOG_171 << 16), bhvBobombBuddy),
		OBJECT(MODEL_BLACK_BOBOMB, -2190, 2813, 2515, 0, 0, 0, (DIALOG_172 << 16), bhvBobombBuddy),
		OBJECT(MODEL_STAR, -4188, 6860, 6831, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(tutorial_area_1_collision),
		MACRO_OBJECTS(tutorial_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_EVENT_CUTSCENE_CREDITS),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 0, 280, 7400),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};