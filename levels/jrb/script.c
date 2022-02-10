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
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
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
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, bbc2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_JRB, 0x01, 0x0A, WARP_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_JRB, 0x01, 0x0A, WARP_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_JRB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -6986, -295, 5474, 0, 90, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, -7126, -270, 5474, 0, 90, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, 190, -295, 5474, 0, 90, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -4727, -223, 4866, 0, 0, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, -4727, -198, 4726, 0, 0, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -3954, -223, 4866, 0, 0, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, -3954, -198, 4726, 0, 0, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -694, -295, 5474, 0, -90, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, 50, -270, 5474, 0, 90, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -2714, 85, 5474, 0, -90, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, -2574, 110, 5474, 0, -90, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_BULLET_BILL, -554, -270, 5474, 0, -90, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 2974, -340, 5515, 0, 0, 0, 0x000B0000, bhvWarpPipe),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, 2143, -295, 5474, 0, -90, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, 2283, -270, 5474, 0, -90, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_NONE, -6309, 0, 5472, 0, 90, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 90, -6309, 0, 5472),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SHOW_DIALOG(/*index*/ 0x00, DIALOG_001),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_KOOPA_ROAD),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, jrb_area_2),
		WARP_NODE(0x0A, LEVEL_JRB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_JRB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -6986, -295, 1875, 0, 90, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, -7126, -270, 1875, 0, 90, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -6986, 8, 1875, 0, 90, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, -7126, 33, 1875, 0, 90, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -4854, -183, 1398, 0, 0, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, -4854, -158, 1258, 0, 0, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -4854, 184, 1398, 0, 0, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, -4854, 209, 1258, 0, 0, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, 856, -183, 1398, 0, 0, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, 856, -158, 1258, 0, 0, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -3458, -183, 1398, 0, 0, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, -3458, -158, 1258, 0, 0, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -3458, 184, 1398, 0, 0, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, -3458, 209, 1258, 0, 0, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, 856, 184, 1398, 0, 0, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, 856, 209, 1258, 0, 0, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -1968, -183, 1398, 0, 0, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, -1968, -158, 1258, 0, 0, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -1968, 184, 1398, 0, 0, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, -1968, 209, 1258, 0, 0, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -456, -183, 1398, 0, 0, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, -456, -158, 1258, 0, 0, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, -456, 184, 1398, 0, 0, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, -456, 209, 1258, 0, 0, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, 1664, 17, 1855, 0, -90, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, 1804, 42, 1855, 0, -90, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, 2947, 181, 1855, 0, -90, 0, 0x00000000, bhvBulletBillCannon),
		OBJECT(MODEL_BULLET_BILL, 3087, 206, 1855, 0, -90, 0, 0x00010000, bhvBulletBill),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 2521, -340, 1942, 0, 0, 0, 0x000B0000, bhvWarpPipe),
		OBJECT(MODEL_STAR, -2500, -1500, 1910, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, -6419, 0, 1910, 0, 90, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(jrb_area_2_collision),
		MACRO_OBJECTS(jrb_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_KOOPA_ROAD),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 90, -6309, 0, 5472),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
