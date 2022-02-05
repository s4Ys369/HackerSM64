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
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _clouds_skybox_yay0SegmentRomStart, _clouds_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, bbc_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_ENDING, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BULLET_BILL, -2073, 1975, -435, 0, 90, 0, 0x00000000, bhvBulletBill),
		OBJECT(MODEL_BULLET_BILL, 2152, 1975, 338, 0, -90, 0, 0x00000000, bhvBulletBill),
		OBJECT(MODEL_BULLET_BILL, -1181, 1975, -1816, 0, 45, 0, 0x00000000, bhvBulletBill),
		OBJECT(MODEL_BULLET_BILL, 1260, 1975, 1719, 0, -135, 0, 0x00000000, bhvBulletBill),
		OBJECT(MODEL_BULLET_BILL, 426, 1975, -2161, 0, 0, 0, 0x00000000, bhvBulletBill),
		OBJECT(MODEL_BULLET_BILL, 1807, 1975, -1269, 0, -45, 0, 0x00000000, bhvBulletBill),
		OBJECT(MODEL_BULLET_BILL, -1728, 1975, 1172, 0, 135, 0, 0x00000000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -1933, 1950, -435, 0, 90, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, 2012, 1950, 338, 0, -90, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -1082, 1950, -1717, 0, 45, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, 1161, 1950, 1620, 0, -135, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, 426, 1950, -2021, 0, 0, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, 1708, 1950, -1170, 0, -45, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -1629, 1950, 1073, 0, 135, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_NONE, 0, 473, 2855, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 473, 2855),
		OBJECT(MODEL_WHOMP, 28, 1895, -37, 0, 0, 0, 0x00000000, bhvWhompKingBoss),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 473, 2855),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
