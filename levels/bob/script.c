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
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript fast64_bob_loads[] = {
	LOAD_MODEL_FROM_GEO(MODEL_SAW_ARM, saw_arm_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SAW_BLADE, saw_blade_geo), 
	RETURN(), 
};

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO_SHELL, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_14), 
	JUMP_LINK(fast64_bob_loads), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 0, 5030, 0),
		OBJECT(MODEL_NONE, 0, 5030, 0, 0, 0, 0, (0x0A << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_SAW_BLADE, 2300, 5200, -475, 0, 0, 0, (0x00 << 24) | (0xEC << 16), bhvSawBlade),
		OBJECT(MODEL_SAW_BLADE, 2550, 5200, 475, 0, 0, 0, (0x01 << 24) | (0xEC << 16), bhvSawBlade),
		OBJECT(MODEL_SAW_BLADE, 4800, 5200, -475, 0, 0, 0, (0x00 << 24) | (0xEC << 16), bhvSawBlade),
		OBJECT(MODEL_SAW_BLADE, 5050, 5200, 475, 0, 0, 0, (0x01 << 24) | (0xEC << 16), bhvSawBlade),
		OBJECT(MODEL_SAW_BLADE, -7700, 5950, 0, 0, 180, 0, (0x02 << 24) | (0x36 << 16), bhvSawBlade),
		OBJECT(MODEL_STAR, -7800, 5800, 0, 0, 0, 0, (0x00 << 24), bhvStar),
		OBJECT(MODEL_NONE, -8400, 5200, -475, 0, 0, 0, (0x00 << 24) | (0x00 << 16), bhvSawBladeWayPoint),
		OBJECT(MODEL_NONE, -8400, 5200, 475, 0, 0, 0, (0x01 << 24) | (0x00 << 16), bhvSawBladeWayPoint),
		OBJECT(MODEL_NONE, -2000, 5200, -475, 0, 0, 0, (0x00 << 24) | (0x01 << 16), bhvSawBladeWayPoint),
		OBJECT(MODEL_NONE, -2000, 5200, 475, 0, 0, 0, (0x01 << 24) | (0x01 << 16), bhvSawBladeWayPoint),
		OBJECT(MODEL_NONE, -3200, 5200, 0, 0, 0, 0, (0x02 << 24) | (0x01 << 16), bhvSawBladeWayPoint),
		OBJECT(MODEL_NONE, 2000, 5200, 0, 0, 0, 0, (0x02 << 24) | (0x00 << 16), bhvSawBladeWayPoint),
		OBJECT(MODEL_GOOMBA, -1, 4838, 490, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_NONE, -713, 4746, 0, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 637, 4746, 0, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 5030, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};