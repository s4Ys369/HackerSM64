#ifndef INTRO_HEADER_H
#define INTRO_HEADER_H

#include "types.h"

// geo
extern const GeoLayout intro_geo_splash_screen[];
extern const GeoLayout intro_geo_mario_head_regular[];
extern const GeoLayout intro_geo_mario_head_dizzy[];
extern const GeoLayout intro_geo_debug_level_select[];

// leveldata
extern u8 title_E006410_rgba16[];
extern u8 title_E005C10_rgba16[];
extern u8 title_E011C10_rgba16[];
extern u8 title_E00EC10_rgba16[];
extern u8 title_E004810_rgba16[];
extern u8 title_E010C10_rgba16[];
extern Vtx title_title_mesh_vtx_cull[8];
extern Vtx title_title_mesh_vtx_0[2465];
extern Gfx title_title_mesh_tri_0[];
extern Vtx title_title_mesh_vtx_1[23];
extern Gfx title_title_mesh_tri_1[];
extern Vtx title_title_mesh_vtx_2[24];
extern Gfx title_title_mesh_tri_2[];
extern Vtx title_title_mesh_vtx_3[31];
extern Gfx title_title_mesh_tri_3[];
extern Vtx title_title_mesh_vtx_4[43];
extern Gfx title_title_mesh_tri_4[];
extern Vtx title_title_mesh_vtx_5[28];
extern Gfx title_title_mesh_tri_5[];
extern Gfx mat_title_wood[];
extern Gfx mat_title_gold[];
extern Gfx mat_title_yellow[];
extern Gfx mat_title_red[];
extern Gfx mat_title_green[];
extern Gfx mat_title_blue[];
extern Gfx title_title_mesh[];

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
