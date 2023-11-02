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

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/hmc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_hmc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _hmc_segment_7SegmentRomStart, _hmc_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _cave_yay0SegmentRomStart, _cave_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group5_yay0SegmentRomStart, _group5_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xa, _ssl_skybox_yay0SegmentRomStart, _ssl_skybox_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PALM_TREE, palm_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, hmc_area_1),
		WARP_NODE(0x0A, LEVEL_HMC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_HMC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_HMC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0, 2, 0, 0, -450),
		PAINTING_WARP_NODE(0x12, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x13, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x14, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_RED_FLAME, -470, 600, 1324, 0, -180, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 470, 600, 1324, 0, -180, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 400, 400, -1176, 0, -180, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -400, 400, -1176, 0, -180, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_NONE, 0, 200, 2400, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(hmc_area_1_collision),
		MACRO_OBJECTS(hmc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC_WITH_REVERB(0x0001, SEQ_LEVEL_HOT, 1, 2),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, hmc_area_2),
		WARP_NODE(0x0A, LEVEL_HMC, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_HMC, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_HMC, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0, 1, 0, 0, 400),
		OBJECT(MODEL_NONE, 28, 2100, 676, -33, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 28, 3700, -524, -33, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1500, 0, 3476, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 2100, 0, 3476, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 300, 100, 2976, 0, 0, 0, 0x00000000, bhvPokey),
		OBJECT(MODEL_NONE, -2500, 100, 2976, 0, 0, 0, 0x00000000, bhvPokey),
		OBJECT(MODEL_NONE, 2800, 100, 2976, 0, 0, 0, 0x00000000, bhvPokey),
		OBJECT(MODEL_STAR, 0, 6200, -2259, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_SSL_PALM_TREE, -1300, 0, 4576, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -3000, 0, 4576, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -4000, 0, 2776, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 1300, 0, 4576, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 3000, 0, 4576, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 4000, 0, 2776, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -4000, 0, 4076, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 4000, 0, 4076, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_UFO, 0, 400, 4576, 0, 0, 0, 0x00000000, bhvUFOWarp),
		OBJECT(MODEL_NONE, 0, 200, 4576, 0, -180, 0, 0x000A0000, bhvHardAirKnockBackWarp),
		MARIO_POS(0x02, -180, 0, 200, 4576),
		TERRAIN(hmc_area_2_collision),
		MACRO_OBJECTS(hmc_area_2_macro_objs),
		SET_BACKGROUND_MUSIC_WITH_REVERB(0x00, SEQ_LEVEL_HOT, 0, 0),
		TERRAIN_TYPE(TERRAIN_SAND),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x02, -180, 0, 200, 4576),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
