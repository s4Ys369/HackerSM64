#ifndef INTRO_HEADER_H
#define INTRO_HEADER_H

#include "types.h"

// geo
extern const GeoLayout intro_geo_splash_screen[];
extern const GeoLayout intro_geo_mario_head_regular[];
extern const GeoLayout intro_geo_mario_head_dizzy[];
extern const GeoLayout intro_geo_debug_level_select[];

// leveldata
extern Lights1 logo_kgs1_lights;
extern Lights1 logo_kgs3_lights;
extern Lights1 logo_kgs0_lights;
extern Lights1 logo_kgs2_lights;
extern u8 logo_kgs1_ci4[];
extern u8 logo_kgs1_ci4_pal_rgba16[];
extern u8 logo_kgs3_i8[];
extern u8 logo_kgs0_ci4[];
extern u8 logo_kgs0_ci4_pal_rgba16[];
extern u8 logo_kgs2_i8[];
extern Vtx logo_Plane_mesh_vtx_cull[8];
extern Vtx logo_Plane_mesh_vtx_0[4];
extern Gfx logo_Plane_mesh_tri_0[];
extern Vtx logo_Plane_mesh_vtx_1[4];
extern Gfx logo_Plane_mesh_tri_1[];
extern Vtx logo_Plane_mesh_vtx_2[4];
extern Gfx logo_Plane_mesh_tri_2[];
extern Vtx logo_Plane_mesh_vtx_3[4];
extern Gfx logo_Plane_mesh_tri_3[];
extern Gfx mat_logo_kgs1[];
extern Gfx mat_revert_logo_kgs1[];
extern Gfx mat_logo_kgs3[];
extern Gfx mat_logo_kgs0[];
extern Gfx mat_revert_logo_kgs0[];
extern Gfx mat_logo_kgs2[];
extern Gfx logo_Plane_mesh[];
extern const Gfx intro_seg7_dl_copyright_trademark[];
extern const f32 intro_seg7_table_scale_1[];
extern const f32 intro_seg7_table_scale_2[];

// script
extern const LevelScript level_intro_splash_screen[];
extern const LevelScript level_intro_mario_head_regular[];
extern const LevelScript level_intro_mario_head_dizzy[];
extern const LevelScript level_intro_entry_level_select[];
extern const LevelScript script_intro_file_select[];
extern const LevelScript script_intro_level_select[];
extern const LevelScript script_intro_main_level_entry_stop_music[];
extern const LevelScript script_intro_main_level_entry[];
extern const LevelScript script_intro_splash_screen[];

#endif
