
Gfx alien_Body_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 alien_Body_rgba16[] = {
	#include "actors/alien/body.rgba16.inc.c"
};

Vtx alien_root_mesh_layer_1_vtx_0[38] = {
	{{{-5, -3, -2},0, {1025, 976},{0x2F, 0x3, 0x8A, 0xFF}}},
	{{{-9, 14, -3},0, {1021, 979},{0xC4, 0xED, 0x92, 0xFF}}},
	{{{-2, -2, 7},0, {1020, 976},{0x57, 0xA4, 0xF4, 0xFF}}},
	{{{7, 14, -2},0, {1018, 979},{0x42, 0xE8, 0x96, 0xFF}}},
	{{{7, -2, -2},0, {1014, 976},{0x10, 0xF2, 0x83, 0xFF}}},
	{{{14, -75, 17},0, {1007, 966},{0x5, 0xEF, 0x82, 0xFF}}},
	{{{19, -72, 24},0, {1004, 966},{0x79, 0xF, 0x24, 0xFF}}},
	{{{12, -2, 8},0, {1009, 976},{0x7B, 0xF, 0x1E, 0xFF}}},
	{{{7, 14, -2},0, {1013, 979},{0x42, 0xE8, 0x96, 0xFF}}},
	{{{10, 17, 5},0, {1010, 979},{0x79, 0x7, 0x26, 0xFF}}},
	{{{3, -2, 12},0, {1016, 976},{0xF2, 0x7, 0x7E, 0xFF}}},
	{{{-3, 18, 14},0, {1020, 979},{0x4, 0xB, 0x7E, 0xFF}}},
	{{{-4, -2, 12},0, {1022, 976},{0x27, 0xF2, 0x78, 0xFF}}},
	{{{-12, 19, 9},0, {1029, 979},{0x95, 0xD, 0x44, 0xFF}}},
	{{{-15, -2, 6},0, {1031, 976},{0x82, 0xFE, 0xD, 0xFF}}},
	{{{-11, 17, 4},0, {1029, 979},{0x86, 0x8, 0xDE, 0xFF}}},
	{{{-9, 14, -3},0, {1026, 979},{0xC4, 0xED, 0x92, 0xFF}}},
	{{{-12, -76, -2},0, {1033, 966},{0x18, 0x7, 0x83, 0xFF}}},
	{{{-9, -76, 4},0, {1030, 966},{0x7D, 0xF0, 0xE, 0xFF}}},
	{{{-14, -77, 9},0, {1033, 966},{0x1, 0xF2, 0x7E, 0xFF}}},
	{{{-19, -77, 3},0, {1036, 966},{0x81, 0xA, 0xFC, 0xFF}}},
	{{{-23, -163, -15},0, {1045, 954},{0x6, 0x4, 0x81, 0xFF}}},
	{{{-19, -164, -13},0, {1044, 954},{0x7A, 0xE3, 0xEE, 0xFF}}},
	{{{-23, -165, -9},0, {1045, 954},{0xF8, 0xE1, 0x7B, 0xFF}}},
	{{{-27, -164, -13},0, {1047, 954},{0x85, 0xFE, 0xE1, 0xFF}}},
	{{{-24, -177, -13},0, {1047, 953},{0xF2, 0x82, 0xF5, 0xFF}}},
	{{{9, -73, 22},0, {1010, 966},{0x83, 0xEC, 0xFE, 0xFF}}},
	{{{27, -162, 21},0, {998, 954},{0x1E, 0xF1, 0x85, 0xFF}}},
	{{{28, -162, 23},0, {997, 954},{0x7E, 0xFE, 0xF4, 0xFF}}},
	{{{26, -162, 26},0, {998, 954},{0xC, 0xF7, 0x7E, 0xFF}}},
	{{{12, -72, 27},0, {1007, 966},{0xE0, 0x9, 0x7B, 0xFF}}},
	{{{23, -162, 22},0, {1000, 954},{0x88, 0xE2, 0xE1, 0xFF}}},
	{{{23, -162, 22},0, {1000, 954},{0x88, 0xE2, 0xE1, 0xFF}}},
	{{{27, -162, 21},0, {998, 954},{0x1E, 0xF1, 0x85, 0xFF}}},
	{{{27, -174, 24},0, {998, 953},{0x9, 0x82, 0xC, 0xFF}}},
	{{{28, -162, 23},0, {997, 954},{0x7E, 0xFE, 0xF4, 0xFF}}},
	{{{26, -162, 26},0, {998, 954},{0xC, 0xF7, 0x7E, 0xFF}}},
	{{{12, -72, 27},0, {1007, 966},{0xE0, 0x9, 0x7B, 0xFF}}},
};

Gfx alien_root_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_root_mesh_layer_1_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(2, 3, 4, 0, 2, 4, 5, 0),
	gsSP2Triangles(6, 5, 4, 0, 4, 7, 6, 0),
	gsSP2Triangles(4, 8, 7, 0, 7, 8, 9, 0),
	gsSP2Triangles(9, 10, 7, 0, 9, 11, 10, 0),
	gsSP2Triangles(10, 11, 2, 0, 2, 11, 12, 0),
	gsSP2Triangles(12, 11, 13, 0, 12, 13, 14, 0),
	gsSP2Triangles(14, 13, 15, 0, 14, 15, 16, 0),
	gsSP2Triangles(14, 16, 0, 0, 14, 0, 17, 0),
	gsSP2Triangles(18, 17, 0, 0, 0, 2, 18, 0),
	gsSP2Triangles(19, 18, 2, 0, 2, 12, 19, 0),
	gsSP2Triangles(20, 19, 12, 0, 12, 14, 20, 0),
	gsSP2Triangles(17, 20, 14, 0, 20, 17, 21, 0),
	gsSP2Triangles(22, 21, 17, 0, 17, 18, 22, 0),
	gsSP2Triangles(23, 22, 18, 0, 18, 19, 23, 0),
	gsSP2Triangles(24, 23, 19, 0, 19, 20, 24, 0),
	gsSP2Triangles(21, 24, 20, 0, 24, 21, 25, 0),
	gsSP2Triangles(21, 22, 25, 0, 22, 23, 25, 0),
	gsSP2Triangles(23, 24, 25, 0, 10, 2, 26, 0),
	gsSP2Triangles(5, 26, 2, 0, 26, 5, 27, 0),
	gsSP2Triangles(28, 27, 5, 0, 5, 6, 28, 0),
	gsSP2Triangles(29, 28, 6, 0, 6, 30, 29, 0),
	gsSP2Triangles(30, 6, 7, 0, 7, 10, 30, 0),
	gsSP2Triangles(26, 30, 10, 0, 30, 26, 31, 0),
	gsSP1Triangle(27, 31, 26, 0),
	gsSPVertex(alien_root_mesh_layer_1_vtx_0 + 32, 6, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(3, 4, 2, 0, 4, 0, 2, 0),
	gsSP1Triangle(0, 4, 5, 0),
	gsSPEndDisplayList(),
};

Vtx alien_torso_skinned_mesh_layer_1_vtx_0[8] = {
	{{{-9, 14, -3},0, {1022, 979},{0xC4, 0xED, 0x92, 0xFF}}},
	{{{-9, 14, -3},0, {1026, 979},{0xC4, 0xED, 0x92, 0xFF}}},
	{{{7, 14, -2},0, {1018, 979},{0x42, 0xE8, 0x96, 0xFF}}},
	{{{7, 14, -2},0, {1013, 979},{0x42, 0xE8, 0x96, 0xFF}}},
	{{{10, 17, 5},0, {1010, 979},{0x79, 0x7, 0x26, 0xFF}}},
	{{{-3, 18, 14},0, {1020, 979},{0x4, 0xB, 0x7E, 0xFF}}},
	{{{-12, 19, 9},0, {1029, 979},{0x95, 0xD, 0x44, 0xFF}}},
	{{{-11, 17, 4},0, {1029, 979},{0x86, 0x8, 0xDE, 0xFF}}},
};

Gfx alien_torso_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_torso_skinned_mesh_layer_1_vtx_0 + 0, 8, 0),
	gsSPEndDisplayList(),
};

Vtx alien_torso_mesh_layer_1_vtx_0[8] = {
	{{{-2, 21, -9},0, {1022, 982},{0xE0, 0xEE, 0x87, 0xFF}}},
	{{{4, 21, -9},0, {1020, 982},{0x30, 0xEA, 0x8D, 0xFF}}},
	{{{4, 21, -9},0, {1017, 982},{0x30, 0xEA, 0x8D, 0xFF}}},
	{{{11, 23, -1},0, {1010, 983},{0x7E, 0xF0, 0x0, 0xFF}}},
	{{{5, 26, 5},0, {1015, 983},{0x2C, 0x6, 0x77, 0xFF}}},
	{{{-7, 26, 4},0, {1020, 983},{0xB9, 0xC, 0x68, 0xFF}}},
	{{{-7, 26, 4},0, {1025, 983},{0xB9, 0xC, 0x68, 0xFF}}},
	{{{-10, 24, -3},0, {1030, 983},{0x86, 0xFE, 0xDD, 0xFF}}},
};

Gfx alien_torso_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_torso_mesh_layer_1_vtx_0 + 0, 8, 8),
	gsSP2Triangles(8, 9, 0, 0, 0, 10, 2, 0),
	gsSP2Triangles(10, 11, 3, 0, 4, 3, 11, 0),
	gsSP2Triangles(4, 11, 12, 0, 4, 12, 5, 0),
	gsSP2Triangles(13, 5, 12, 0, 14, 6, 5, 0),
	gsSP2Triangles(14, 15, 6, 0, 6, 15, 7, 0),
	gsSP2Triangles(7, 15, 1, 0, 15, 8, 1, 0),
	gsSPEndDisplayList(),
};

Vtx alien_torso_mesh_layer_1_vtx_1[22] = {
	{{{-2, 21, -9},0, {1022, 982},{0xE0, 0xEE, 0x87, 0xFF}}},
	{{{-8, 64, -14},0, {1020, 988},{0xD2, 0xF3, 0x8A, 0xFF}}},
	{{{4, 21, -9},0, {1020, 981},{0x30, 0xEA, 0x8D, 0xFF}}},
	{{{12, 52, 6},0, {1020, 986},{0x40, 0xFE, 0x6E, 0xFF}}},
	{{{-7, 26, 4},0, {1020, 983},{0xB9, 0xC, 0x68, 0xFF}}},
	{{{5, 26, 5},0, {1015, 983},{0x2C, 0x6, 0x77, 0xFF}}},
	{{{-10, 24, -3},0, {1030, 983},{0x86, 0xFE, 0xDD, 0xFF}}},
	{{{-8, 64, -14},0, {1029, 988},{0xD2, 0xF3, 0x8A, 0xFF}}},
	{{{-12, 65, -5},0, {1033, 988},{0x8C, 0xD3, 0x17, 0xFF}}},
	{{{-10, 53, 5},0, {1030, 987},{0xB0, 0x3, 0x63, 0xFF}}},
	{{{-7, 26, 4},0, {1025, 983},{0xB9, 0xC, 0x68, 0xFF}}},
	{{{-11, 72, 2},0, {1031, 989},{0xBE, 0x18, 0x6A, 0xFF}}},
	{{{-18, 78, -6},0, {1033, 990},{0x90, 0x37, 0x17, 0xFF}}},
	{{{2, 84, -2},0, {1020, 991},{0xF2, 0xA4, 0x57, 0xFF}}},
	{{{-2, 86, -6},0, {1025, 991},{0x82, 0xB, 0xF0, 0xFF}}},
	{{{3, 83, -11},0, {1020, 991},{0x6, 0x12, 0x82, 0xFF}}},
	{{{-17, 73, -11},0, {1034, 989},{0x9C, 0x9, 0xB2, 0xFF}}},
	{{{-8, 64, -14},0, {1020, 990},{0xD2, 0xF3, 0x8A, 0xFF}}},
	{{{14, 63, -13},0, {1010, 988},{0x3F, 0xF9, 0x92, 0xFF}}},
	{{{4, 21, -9},0, {1018, 982},{0x30, 0xEA, 0x8D, 0xFF}}},
	{{{11, 23, -1},0, {1010, 983},{0x7E, 0xF0, 0x0, 0xFF}}},
	{{{12, 52, 6},0, {1010, 986},{0x40, 0xFE, 0x6E, 0xFF}}},
};

Gfx alien_torso_mesh_layer_1_tri_1[] = {
	gsSPVertex(alien_torso_mesh_layer_1_vtx_1 + 0, 22, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(0, 6, 7, 0, 8, 7, 6, 0),
	gsSP2Triangles(9, 8, 6, 0, 10, 9, 6, 0),
	gsSP2Triangles(9, 10, 3, 0, 9, 3, 11, 0),
	gsSP2Triangles(9, 11, 8, 0, 11, 12, 8, 0),
	gsSP2Triangles(11, 13, 12, 0, 14, 12, 13, 0),
	gsSP2Triangles(12, 14, 15, 0, 16, 12, 15, 0),
	gsSP2Triangles(17, 16, 15, 0, 12, 16, 8, 0),
	gsSP2Triangles(8, 16, 7, 0, 1, 18, 19, 0),
	gsSP2Triangles(19, 18, 20, 0, 20, 21, 5, 0),
	gsSPEndDisplayList(),
};

Vtx alien_head_skinned_mesh_layer_1_vtx_0[4] = {
	{{{3, 83, -11},0, {1020, 991},{0x6, 0x12, 0x82, 0xFF}}},
	{{{-2, 86, -6},0, {1025, 991},{0x82, 0xB, 0xF0, 0xFF}}},
	{{{8, 85, -5},0, {1016, 991},{0x7C, 0x13, 0x13, 0xFF}}},
	{{{2, 84, -2},0, {1020, 991},{0xF2, 0xA4, 0x57, 0xFF}}},
};

Gfx alien_head_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_head_skinned_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSPEndDisplayList(),
};

Vtx alien_head_mesh_layer_1_vtx_0[4] = {
	{{{1, 20, -14},0, {1020, 993},{0xF6, 0xC1, 0x92, 0xFF}}},
	{{{10, 16, -7},0, {1016, 993},{0x65, 0xC2, 0xD3, 0xFF}}},
	{{{-6, 17, -7},0, {1023, 993},{0x9B, 0xC5, 0xCE, 0xFF}}},
	{{{1, 7, 1},0, {1020, 993},{0xF2, 0x8F, 0xC8, 0xFF}}},
};

Gfx alien_head_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_head_mesh_layer_1_vtx_0 + 0, 4, 4),
	gsSP2Triangles(0, 4, 5, 0, 6, 4, 0, 0),
	gsSP2Triangles(1, 6, 0, 0, 7, 6, 1, 0),
	gsSP2Triangles(3, 7, 1, 0, 2, 7, 3, 0),
	gsSP2Triangles(5, 7, 2, 0, 5, 2, 0, 0),
	gsSPEndDisplayList(),
};

Vtx alien_head_mesh_layer_1_vtx_1[117] = {
	{{{2, 38, -32},0, {1023, 899},{0xFE, 0xAF, 0x9E, 0xFF}}},
	{{{-6, 17, -7},0, {1020, 861},{0x9B, 0xC5, 0xCE, 0xFF}}},
	{{{-16, 42, -28},0, {1036, 899},{0xAA, 0xC2, 0xB9, 0xFF}}},
	{{{4, -2, 17},0, {880, 80},{0x6C, 0xC1, 0x15, 0xFF}}},
	{{{22, 27, -1},0, {752, 144},{0x74, 0xCE, 0x10, 0xFF}}},
	{{{19, 33, 5},0, {752, 240},{0x57, 0x1, 0x5D, 0xFF}}},
	{{{19, 33, 5},0, {752, 370},{0x57, 0x1, 0x5D, 0xFF}}},
	{{{1, 0, 20},0, {1004, 25},{0xFF, 0x8, 0x7F, 0xFF}}},
	{{{4, -2, 17},0, {876, 25},{0x6C, 0xC1, 0x15, 0xFF}}},
	{{{2, 38, -32},0, {1023, 899},{0xFE, 0xAF, 0x9E, 0xFF}}},
	{{{1, 20, -14},0, {1008, 869},{0xF6, 0xC1, 0x92, 0xFF}}},
	{{{21, 39, -26},0, {980, 899},{0x4F, 0xBA, 0xB9, 0xFF}}},
	{{{10, 16, -7},0, {995, 861},{0x65, 0xC2, 0xD3, 0xFF}}},
	{{{2, 38, -32},0, {992, 899},{0xFE, 0xAF, 0x9E, 0xFF}}},
	{{{2, 38, -32},0, {993, 899},{0xFE, 0xAF, 0x9E, 0xFF}}},
	{{{-6, 17, -7},0, {1020, 861},{0x9B, 0xC5, 0xCE, 0xFF}}},
	{{{1, 7, 1},0, {1008, 844},{0xF2, 0x8F, 0xC8, 0xFF}}},
	{{{0, -4, 16},0, {1016, 835},{0xF9, 0x90, 0xC4, 0xFF}}},
	{{{21, 39, -26},0, {971, 899},{0x4F, 0xBA, 0xB9, 0xFF}}},
	{{{22, 27, -1},0, {978, 869},{0x74, 0xCE, 0x10, 0xFF}}},
	{{{10, 16, -7},0, {986, 861},{0x65, 0xC2, 0xD3, 0xFF}}},
	{{{29, 50, -14},0, {968, 899},{0x7B, 0xDF, 0x0, 0xFF}}},
	{{{22, 27, -1},0, {979, 869},{0x74, 0xCE, 0x10, 0xFF}}},
	{{{21, 39, -26},0, {971, 899},{0x4F, 0xBA, 0xB9, 0xFF}}},
	{{{0, -4, 16},0, {999, 835},{0xF9, 0x90, 0xC4, 0xFF}}},
	{{{-3, -1, 16},0, {877, 25},{0x8D, 0xCE, 0x14, 0xFF}}},
	{{{1, 0, 20},0, {1005, 25},{0xFF, 0x8, 0x7F, 0xFF}}},
	{{{-14, 35, 4},0, {752, 370},{0xA8, 0xC, 0x5A, 0xFF}}},
	{{{-14, 35, 4},0, {752, 240},{0xA8, 0xC, 0x5A, 0xFF}}},
	{{{-18, 30, -2},0, {752, 144},{0x88, 0xDA, 0xF, 0xFF}}},
	{{{-3, -1, 16},0, {880, 80},{0x8D, 0xCE, 0x14, 0xFF}}},
	{{{4, -2, 17},0, {1001, 824},{0x6C, 0xC1, 0x15, 0xFF}}},
	{{{0, -6, 20},0, {1008, 816},{0xFA, 0x9A, 0x4C, 0xFF}}},
	{{{0, -4, 16},0, {1007, 823},{0xF9, 0x90, 0xC4, 0xFF}}},
	{{{0, -4, 16},0, {1008, 823},{0xF9, 0x90, 0xC4, 0xFF}}},
	{{{0, -6, 20},0, {1007, 816},{0xFA, 0x9A, 0x4C, 0xFF}}},
	{{{-3, -1, 16},0, {1014, 824},{0x8D, 0xCE, 0x14, 0xFF}}},
	{{{3, 58, -46},0, {1029, 938},{0x0, 0xCB, 0x8C, 0xFF}}},
	{{{-10, 90, -50},0, {1030, 963},{0xC5, 0xB, 0x90, 0xFF}}},
	{{{5, 94, -54},0, {1007, 954},{0x5, 0x17, 0x83, 0xFF}}},
	{{{-21, 73, -40},0, {1045, 938},{0x9E, 0xEB, 0xB2, 0xFF}}},
	{{{-16, 42, -28},0, {1035, 899},{0xAA, 0xC2, 0xB9, 0xFF}}},
	{{{2, 38, -32},0, {1023, 899},{0xFE, 0xAF, 0x9E, 0xFF}}},
	{{{-20, 93, -37},0, {1046, 955},{0x93, 0x39, 0xE1, 0xFF}}},
	{{{-25, 75, -28},0, {1052, 929},{0x81, 0x3, 0xFE, 0xFF}}},
	{{{-16, 42, -28},0, {1044, 899},{0xAA, 0xC2, 0xB9, 0xFF}}},
	{{{-22, 54, -16},0, {1047, 899},{0x82, 0xEF, 0x2, 0xFF}}},
	{{{-18, 30, -2},0, {1037, 869},{0x88, 0xDA, 0xF, 0xFF}}},
	{{{-6, 17, -7},0, {1030, 861},{0x9B, 0xC5, 0xCE, 0xFF}}},
	{{{-9, 102, -45},0, {1030, 972},{0xBF, 0x56, 0xBD, 0xFF}}},
	{{{5, 94, -54},0, {1008, 972},{0x5, 0x17, 0x83, 0xFF}}},
	{{{6, 106, -47},0, {1008, 978},{0x9, 0x64, 0xB2, 0xFF}}},
	{{{21, 100, -44},0, {986, 972},{0x4F, 0x4A, 0xBE, 0xFF}}},
	{{{20, 88, -49},0, {985, 963},{0x41, 0x3, 0x93, 0xFF}}},
	{{{31, 89, -35},0, {970, 955},{0x74, 0x29, 0xE1, 0xFF}}},
	{{{30, 69, -38},0, {970, 938},{0x60, 0xDF, 0xB4, 0xFF}}},
	{{{34, 71, -26},0, {964, 929},{0x7E, 0xF4, 0xFC, 0xFF}}},
	{{{21, 39, -26},0, {971, 899},{0x4F, 0xBA, 0xB9, 0xFF}}},
	{{{29, 50, -14},0, {968, 899},{0x7B, 0xDF, 0x0, 0xFF}}},
	{{{3, 58, -46},0, {987, 938},{0x0, 0xCB, 0x8C, 0xFF}}},
	{{{21, 39, -26},0, {980, 899},{0x4F, 0xBA, 0xB9, 0xFF}}},
	{{{2, 38, -32},0, {993, 899},{0xFE, 0xAF, 0x9E, 0xFF}}},
	{{{-14, 35, 4},0, {752, 371},{0xA8, 0xC, 0x5A, 0xFF}}},
	{{{1, 0, 20},0, {1005, 25},{0xFF, 0x8, 0x7F, 0xFF}}},
	{{{3, 40, 12},0, {1008, 371},{0xFF, 0x18, 0x7D, 0xFF}}},
	{{{19, 33, 5},0, {752, 370},{0x57, 0x1, 0x5D, 0xFF}}},
	{{{1, 20, -14},0, {132, 137},{0xF6, 0xC1, 0x92, 0xFF}}},
	{{{1, 7, 1},0, {522, 134},{0xF2, 0x8F, 0xC8, 0xFF}}},
	{{{10, 16, -7},0, {328, 38},{0x65, 0xC2, 0xD3, 0xFF}}},
	{{{-6, 17, -7},0, {323, 218},{0x9B, 0xC5, 0xCE, 0xFF}}},
	{{{-6, 17, -7},0, {1029, 861},{0x9B, 0xC5, 0xCE, 0xFF}}},
	{{{0, -4, 16},0, {1016, 835},{0xF9, 0x90, 0xC4, 0xFF}}},
	{{{-18, 30, -2},0, {1024, 844},{0x88, 0xDA, 0xF, 0xFF}}},
	{{{-3, -1, 16},0, {1014, 824},{0x8D, 0xCE, 0x14, 0xFF}}},
	{{{22, 27, -1},0, {991, 844},{0x74, 0xCE, 0x10, 0xFF}}},
	{{{4, -2, 17},0, {1001, 824},{0x6C, 0xC1, 0x15, 0xFF}}},
	{{{0, -4, 16},0, {999, 835},{0xF9, 0x90, 0xC4, 0xFF}}},
	{{{10, 16, -7},0, {986, 861},{0x65, 0xC2, 0xD3, 0xFF}}},
	{{{-3, -1, 16},0, {880, 48},{0x8D, 0xCE, 0x14, 0xFF}}},
	{{{0, -6, 20},0, {1008, -16},{0xFA, 0x9A, 0x4C, 0xFF}}},
	{{{1, 0, 20},0, {1008, 48},{0xFF, 0x8, 0x7F, 0xFF}}},
	{{{4, -2, 17},0, {880, 48},{0x6C, 0xC1, 0x15, 0xFF}}},
	{{{6, 106, -47},0, {1008, 1008},{0x9, 0x64, 0xB2, 0xFF}}},
	{{{-9, 102, -45},0, {752, 976},{0xBF, 0x56, 0xBD, 0xFF}}},
	{{{7, 111, -34},0, {1008, 976},{0x9, 0x7E, 0x9, 0xFF}}},
	{{{-8, 104, -31},0, {752, 912},{0xBF, 0x6A, 0x18, 0xFF}}},
	{{{-20, 93, -37},0, {560, 848},{0x93, 0x39, 0xE1, 0xFF}}},
	{{{-20, 88, -21},0, {560, 752},{0x9C, 0x38, 0x37, 0xFF}}},
	{{{-25, 75, -28},0, {368, 720},{0x81, 0x3, 0xFE, 0xFF}}},
	{{{-20, 60, -8},0, {560, 528},{0x96, 0x14, 0x43, 0xFF}}},
	{{{-22, 54, -16},0, {432, 528},{0x82, 0xEF, 0x2, 0xFF}}},
	{{{-18, 30, -2},0, {624, 304},{0x88, 0xDA, 0xF, 0xFF}}},
	{{{-14, 35, 4},0, {752, 240},{0xA8, 0xC, 0x5A, 0xFF}}},
	{{{-7, 66, 2},0, {816, 528},{0xC9, 0x2B, 0x6A, 0xFF}}},
	{{{-7, 66, 2},0, {816, 528},{0xC9, 0x2B, 0x6A, 0xFF}}},
	{{{-14, 35, 4},0, {752, 240},{0xA8, 0xC, 0x5A, 0xFF}}},
	{{{3, 40, 12},0, {1008, 240},{0xFF, 0x18, 0x7D, 0xFF}}},
	{{{4, 66, 4},0, {1008, 528},{0x0, 0x2F, 0x76, 0xFF}}},
	{{{15, 64, 3},0, {816, 528},{0x37, 0x25, 0x6C, 0xFF}}},
	{{{19, 33, 5},0, {752, 240},{0x57, 0x1, 0x5D, 0xFF}}},
	{{{28, 56, -6},0, {560, 528},{0x6C, 0x7, 0x43, 0xFF}}},
	{{{22, 27, -1},0, {624, 304},{0x74, 0xCE, 0x10, 0xFF}}},
	{{{29, 50, -14},0, {432, 528},{0x7B, 0xDF, 0x0, 0xFF}}},
	{{{34, 71, -26},0, {368, 720},{0x7E, 0xF4, 0xFC, 0xFF}}},
	{{{31, 84, -19},0, {560, 752},{0x6A, 0x2C, 0x36, 0xFF}}},
	{{{31, 89, -35},0, {560, 848},{0x74, 0x29, 0xE1, 0xFF}}},
	{{{21, 102, -30},0, {752, 912},{0x4F, 0x61, 0x18, 0xFF}}},
	{{{21, 100, -44},0, {752, 976},{0x4F, 0x4A, 0xBE, 0xFF}}},
	{{{7, 111, -34},0, {1008, 976},{0x9, 0x7E, 0x9, 0xFF}}},
	{{{6, 106, -47},0, {1008, 1008},{0x9, 0x64, 0xB2, 0xFF}}},
	{{{7, 104, -21},0, {1008, 848},{0x5, 0x67, 0x4B, 0xFF}}},
	{{{-8, 104, -31},0, {752, 912},{0xBF, 0x6A, 0x18, 0xFF}}},
	{{{-9, 92, -14},0, {752, 752},{0xC9, 0x4C, 0x56, 0xFF}}},
	{{{-20, 88, -21},0, {560, 752},{0x9C, 0x38, 0x37, 0xFF}}},
	{{{-20, 60, -8},0, {560, 528},{0x96, 0x14, 0x43, 0xFF}}},
	{{{6, 88, -6},0, {1008, 720},{0x1, 0x47, 0x69, 0xFF}}},
	{{{21, 90, -13},0, {752, 752},{0x3D, 0x46, 0x56, 0xFF}}},
};

Gfx alien_head_mesh_layer_1_tri_1[] = {
	gsSPVertex(alien_head_mesh_layer_1_vtx_1 + 0, 31, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 1, 0),
	gsSP2Triangles(11, 12, 13, 0, 14, 12, 10, 0),
	gsSP2Triangles(15, 16, 17, 0, 18, 19, 20, 0),
	gsSP2Triangles(21, 22, 23, 0, 12, 24, 16, 0),
	gsSP2Triangles(25, 26, 27, 0, 28, 29, 30, 0),
	gsSPVertex(alien_head_mesh_layer_1_vtx_1 + 31, 31, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 7, 6, 0),
	gsSP2Triangles(10, 9, 6, 0, 10, 6, 11, 0),
	gsSP2Triangles(9, 12, 7, 0, 13, 12, 9, 0),
	gsSP2Triangles(14, 13, 9, 0, 15, 13, 14, 0),
	gsSP2Triangles(14, 16, 15, 0, 14, 17, 16, 0),
	gsSP2Triangles(12, 18, 7, 0, 7, 18, 19, 0),
	gsSP2Triangles(18, 20, 19, 0, 19, 20, 21, 0),
	gsSP2Triangles(22, 19, 21, 0, 22, 21, 23, 0),
	gsSP2Triangles(24, 22, 23, 0, 24, 23, 25, 0),
	gsSP2Triangles(26, 24, 25, 0, 26, 25, 27, 0),
	gsSP2Triangles(28, 22, 24, 0, 28, 8, 22, 0),
	gsSP2Triangles(29, 28, 24, 0, 30, 28, 29, 0),
	gsSPVertex(alien_head_mesh_layer_1_vtx_1 + 62, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 9, 11, 10, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 12, 14, 0),
	gsSP2Triangles(16, 17, 18, 0, 18, 17, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 22, 21, 23, 0),
	gsSP2Triangles(23, 21, 24, 0, 25, 23, 24, 0),
	gsSP2Triangles(25, 24, 26, 0, 27, 25, 26, 0),
	gsSP2Triangles(27, 26, 28, 0, 28, 29, 27, 0),
	gsSP2Triangles(27, 29, 30, 0, 27, 30, 31, 0),
	gsSPVertex(alien_head_mesh_layer_1_vtx_1 + 94, 23, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
	gsSP2Triangles(4, 5, 6, 0, 6, 5, 7, 0),
	gsSP2Triangles(6, 7, 8, 0, 8, 9, 6, 0),
	gsSP2Triangles(6, 9, 10, 0, 9, 11, 10, 0),
	gsSP2Triangles(10, 11, 12, 0, 11, 13, 12, 0),
	gsSP2Triangles(12, 13, 14, 0, 13, 15, 14, 0),
	gsSP2Triangles(12, 14, 16, 0, 16, 14, 17, 0),
	gsSP2Triangles(18, 16, 17, 0, 18, 17, 19, 0),
	gsSP2Triangles(20, 18, 19, 0, 0, 18, 20, 0),
	gsSP2Triangles(0, 21, 18, 0, 3, 21, 0, 0),
	gsSP2Triangles(4, 21, 3, 0, 4, 22, 21, 0),
	gsSP2Triangles(6, 22, 4, 0, 6, 10, 22, 0),
	gsSP2Triangles(10, 12, 22, 0, 22, 12, 16, 0),
	gsSP2Triangles(22, 16, 21, 0, 21, 16, 18, 0),
	gsSPEndDisplayList(),
};

Vtx alien_larm_skinned_mesh_layer_1_vtx_0[10] = {
	{{{14, 63, -13},0, {1010, 988},{0x3F, 0xF9, 0x92, 0xFF}}},
	{{{-8, 64, -14},0, {1020, 990},{0xD2, 0xF3, 0x8A, 0xFF}}},
	{{{3, 83, -11},0, {1020, 991},{0x6, 0x12, 0x82, 0xFF}}},
	{{{2, 84, -2},0, {1020, 991},{0xF2, 0xA4, 0x57, 0xFF}}},
	{{{8, 85, -5},0, {1016, 991},{0x7C, 0x13, 0x13, 0xFF}}},
	{{{12, 52, 6},0, {1010, 987},{0x40, 0xFE, 0x6E, 0xFF}}},
	{{{11, 23, -1},0, {1010, 983},{0x7E, 0xF0, 0x0, 0xFF}}},
	{{{12, 52, 6},0, {1010, 986},{0x40, 0xFE, 0x6E, 0xFF}}},
	{{{-11, 72, 2},0, {1031, 989},{0xBE, 0x18, 0x6A, 0xFF}}},
	{{{12, 52, 6},0, {1020, 987},{0x40, 0xFE, 0x6E, 0xFF}}},
};

Gfx alien_larm_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_larm_skinned_mesh_layer_1_vtx_0 + 0, 10, 0),
	gsSPEndDisplayList(),
};

Vtx alien_larm_mesh_layer_1_vtx_0[7] = {
	{{{-7, 14, 3},0, {1020, 989},{0xC8, 0x18, 0x6F, 0xFF}}},
	{{{-7, 14, 3},0, {1020, 989},{0xC8, 0x18, 0x6F, 0xFF}}},
	{{{-7, 14, 3},0, {1008, 989},{0xC8, 0x18, 0x6F, 0xFF}}},
	{{{-15, 15, -4},0, {1006, 990},{0x8C, 0x27, 0x21, 0xFF}}},
	{{{-12, 18, -9},0, {1006, 989},{0xAD, 0x47, 0xC0, 0xFF}}},
	{{{-3, 20, -4},0, {1006, 988},{0xD7, 0x6C, 0x34, 0xFF}}},
	{{{-7, 14, 3},0, {1009, 989},{0xC8, 0x18, 0x6F, 0xFF}}},
};

Gfx alien_larm_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_larm_mesh_layer_1_vtx_0 + 0, 7, 10),
	gsSP2Triangles(3, 8, 10, 0, 9, 11, 8, 0),
	gsSP2Triangles(12, 13, 3, 0, 3, 13, 4, 0),
	gsSP2Triangles(13, 2, 4, 0, 14, 2, 13, 0),
	gsSP2Triangles(14, 1, 2, 0, 1, 14, 0, 0),
	gsSP2Triangles(0, 14, 15, 0, 0, 15, 6, 0),
	gsSP2Triangles(15, 7, 6, 0, 15, 16, 5, 0),
	gsSPEndDisplayList(),
};

Vtx alien_larm_mesh_layer_1_vtx_1[4] = {
	{{{-3, 20, -4},0, {1006, 988},{0xD7, 0x6C, 0x34, 0xFF}}},
	{{{-15, 15, -4},0, {1006, 990},{0x8C, 0x27, 0x21, 0xFF}}},
	{{{-7, 14, 3},0, {1009, 989},{0xC8, 0x18, 0x6F, 0xFF}}},
	{{{-12, 18, -9},0, {1006, 989},{0xAD, 0x47, 0xC0, 0xFF}}},
};

Gfx alien_larm_mesh_layer_1_tri_1[] = {
	gsSPVertex(alien_larm_mesh_layer_1_vtx_1 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSPEndDisplayList(),
};

Vtx alien_larmu_skinned_mesh_layer_1_vtx_0[3] = {
	{{{-3, 20, -4},0, {1006, 988},{0xD7, 0x6C, 0x34, 0xFF}}},
	{{{-12, 18, -9},0, {1006, 989},{0xAD, 0x47, 0xC0, 0xFF}}},
	{{{-15, 15, -4},0, {1006, 990},{0x8C, 0x27, 0x21, 0xFF}}},
};

Gfx alien_larmu_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_larmu_skinned_mesh_layer_1_vtx_0 + 0, 3, 0),
	gsSPEndDisplayList(),
};

Vtx alien_larmu_mesh_layer_1_vtx_0[4] = {
	{{{5, 46, -1},0, {997, 982},{0x7B, 0xF, 0xE3, 0xFF}}},
	{{{-1, 47, -4},0, {995, 982},{0xEE, 0x23, 0x87, 0xFF}}},
	{{{-5, 46, 0},0, {994, 983},{0x82, 0x1, 0xED, 0xFF}}},
	{{{-1, 43, 5},0, {995, 983},{0xF8, 0xDE, 0x7A, 0xFF}}},
};

Gfx alien_larmu_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_larmu_mesh_layer_1_vtx_0 + 0, 4, 3),
	gsSP2Triangles(1, 3, 0, 0, 4, 3, 1, 0),
	gsSP2Triangles(5, 4, 1, 0, 1, 2, 5, 0),
	gsSP2Triangles(6, 5, 2, 0, 0, 6, 2, 0),
	gsSP1Triangle(3, 6, 0, 0),
	gsSPEndDisplayList(),
};

Vtx alien_larmf_skinned_mesh_layer_1_vtx_0[4] = {
	{{{-1, 43, 5},0, {995, 983},{0xF8, 0xDE, 0x7A, 0xFF}}},
	{{{5, 46, -1},0, {997, 982},{0x7B, 0xF, 0xE3, 0xFF}}},
	{{{-1, 47, -4},0, {995, 982},{0xEE, 0x23, 0x87, 0xFF}}},
	{{{-5, 46, 0},0, {994, 983},{0x82, 0x1, 0xED, 0xFF}}},
};

Gfx alien_larmf_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_larmf_skinned_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSPEndDisplayList(),
};

Vtx alien_larmf_mesh_layer_1_vtx_0[4] = {
	{{{-1, 63, 7},0, {981, 975},{0xF8, 0xF3, 0x7E, 0xFF}}},
	{{{3, 65, 1},0, {982, 975},{0x7D, 0x8, 0xEE, 0xFF}}},
	{{{-1, 66, -2},0, {981, 975},{0x3, 0x16, 0x83, 0xFF}}},
	{{{-4, 66, 1},0, {980, 975},{0x84, 0x2, 0xE6, 0xFF}}},
};

Gfx alien_larmf_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_larmf_mesh_layer_1_vtx_0 + 0, 4, 4),
	gsSP2Triangles(0, 1, 4, 0, 5, 4, 1, 0),
	gsSP2Triangles(1, 2, 5, 0, 6, 5, 2, 0),
	gsSP2Triangles(2, 3, 6, 0, 7, 6, 3, 0),
	gsSP2Triangles(3, 0, 7, 0, 4, 7, 0, 0),
	gsSPEndDisplayList(),
};

Vtx alien_hand_skinned_mesh_layer_1_vtx_0[4] = {
	{{{-1, 63, 7},0, {981, 975},{0xF8, 0xF3, 0x7E, 0xFF}}},
	{{{3, 65, 1},0, {982, 975},{0x7D, 0x8, 0xEE, 0xFF}}},
	{{{-1, 66, -2},0, {981, 975},{0x3, 0x16, 0x83, 0xFF}}},
	{{{-4, 66, 1},0, {980, 975},{0x84, 0x2, 0xE6, 0xFF}}},
};

Gfx alien_hand_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_hand_skinned_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSPEndDisplayList(),
};

Vtx alien_hand_mesh_layer_1_vtx_0[4] = {
	{{{0, 17, 5},0, {980, 974},{0x23, 0x21, 0x76, 0xFF}}},
	{{{0, 19, -1},0, {980, 974},{0x7F, 0x1, 0x3, 0xFF}}},
	{{{1, 21, -4},0, {980, 973},{0x3E, 0x22, 0x97, 0xFF}}},
	{{{-5, 20, -1},0, {977, 973},{0x87, 0x20, 0xEB, 0xFF}}},
};

Gfx alien_hand_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_hand_mesh_layer_1_vtx_0 + 0, 4, 4),
	gsSP2Triangles(0, 1, 4, 0, 5, 4, 1, 0),
	gsSP2Triangles(1, 2, 5, 0, 6, 5, 2, 0),
	gsSP2Triangles(2, 3, 6, 0, 7, 6, 3, 0),
	gsSP2Triangles(3, 0, 7, 0, 4, 7, 0, 0),
	gsSPEndDisplayList(),
};

Vtx alien_hand_mesh_layer_1_vtx_1[5] = {
	{{{0, 17, 5},0, {980, 974},{0x23, 0x21, 0x76, 0xFF}}},
	{{{0, 19, -1},0, {980, 974},{0x7F, 0x1, 0x3, 0xFF}}},
	{{{1, 28, 2},0, {979, 972},{0x1C, 0x78, 0x1D, 0xFF}}},
	{{{1, 21, -4},0, {980, 973},{0x3E, 0x22, 0x97, 0xFF}}},
	{{{-5, 20, -1},0, {977, 973},{0x87, 0x20, 0xEB, 0xFF}}},
};

Gfx alien_hand_mesh_layer_1_tri_1[] = {
	gsSPVertex(alien_hand_mesh_layer_1_vtx_1 + 0, 5, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(3, 4, 2, 0, 4, 0, 2, 0),
	gsSPEndDisplayList(),
};

Vtx alien_rarm_skinned_mesh_layer_1_vtx_0[3] = {
	{{{-18, 78, -6},0, {1033, 990},{0x90, 0x37, 0x17, 0xFF}}},
	{{{-12, 65, -5},0, {1033, 988},{0x8C, 0xD3, 0x17, 0xFF}}},
	{{{-17, 73, -11},0, {1034, 989},{0x9C, 0x9, 0xB2, 0xFF}}},
};

Gfx alien_rarm_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_rarm_skinned_mesh_layer_1_vtx_0 + 0, 3, 0),
	gsSPEndDisplayList(),
};

Vtx alien_rarm_mesh_layer_1_vtx_0[4] = {
	{{{-27, 70, -4},0, {1045, 982},{0x4B, 0x2A, 0x5E, 0xFF}}},
	{{{-28, 73, -10},0, {1047, 982},{0x40, 0x52, 0xB7, 0xFF}}},
	{{{-32, 69, -12},0, {1045, 982},{0xD1, 0xFA, 0x8A, 0xFF}}},
	{{{-34, 67, -7},0, {1044, 982},{0xA9, 0xA8, 0x1E, 0xFF}}},
};

Gfx alien_rarm_mesh_layer_1_tri_0[] = {
	gsSPVertex(alien_rarm_mesh_layer_1_vtx_0 + 0, 4, 3),
	gsSP2Triangles(1, 0, 3, 0, 3, 0, 4, 0),
	gsSP2Triangles(2, 4, 0, 0, 4, 2, 5, 0),
	gsSP2Triangles(6, 5, 2, 0, 6, 2, 1, 0),
	gsSP1Triangle(3, 6, 1, 0),
	gsSPEndDisplayList(),
};

Vtx alien_rarm_mesh_layer_1_vtx_1[13] = {
	{{{-34, 67, -7},0, {1044, 982},{0xA9, 0xA8, 0x1E, 0xFF}}},
	{{{-27, 70, -4},0, {1045, 982},{0x4B, 0x2A, 0x5E, 0xFF}}},
	{{{-72, 109, 23},0, {1060, 975},{0x6E, 0x23, 0x35, 0xFF}}},
	{{{-76, 112, 21},0, {1061, 975},{0x1A, 0x67, 0xBA, 0xFF}}},
	{{{-28, 73, -10},0, {1047, 982},{0x40, 0x52, 0xB7, 0xFF}}},
	{{{-79, 109, 19},0, {1060, 975},{0xA7, 0x9, 0xA6, 0xFF}}},
	{{{-32, 69, -12},0, {1045, 982},{0xD1, 0xFA, 0x8A, 0xFF}}},
	{{{-76, 106, 23},0, {1059, 975},{0xCF, 0x95, 0x30, 0xFF}}},
	{{{-75, 114, 32},0, {1059, 974},{0x55, 0xB, 0x5E, 0xFF}}},
	{{{-80, 117, 28},0, {1062, 973},{0x7, 0x7A, 0xDF, 0xFF}}},
	{{{-85, 114, 28},0, {1059, 973},{0x8B, 0xFD, 0xCF, 0xFF}}},
	{{{-81, 112, 29},0, {1059, 973},{0xDA, 0x90, 0x2F, 0xFF}}},
	{{{-86, 116, 36},0, {1059, 972},{0xAF, 0x15, 0x60, 0xFF}}},
};

Gfx alien_rarm_mesh_layer_1_tri_1[] = {
	gsSPVertex(alien_rarm_mesh_layer_1_vtx_1 + 0, 13, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(1, 4, 3, 0, 5, 3, 4, 0),
	gsSP2Triangles(4, 6, 5, 0, 7, 5, 6, 0),
	gsSP2Triangles(6, 0, 7, 0, 2, 7, 0, 0),
	gsSP2Triangles(7, 2, 8, 0, 9, 8, 2, 0),
	gsSP2Triangles(2, 3, 9, 0, 10, 9, 3, 0),
	gsSP2Triangles(3, 5, 10, 0, 11, 10, 5, 0),
	gsSP2Triangles(5, 7, 11, 0, 8, 11, 7, 0),
	gsSP2Triangles(11, 8, 12, 0, 8, 9, 12, 0),
	gsSP2Triangles(9, 10, 12, 0, 10, 11, 12, 0),
	gsSPEndDisplayList(),
};


Gfx mat_alien_body[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, alien_Body_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
    gsSPLightColor(LIGHT_1, 0xfefefeff),
    gsSPLightColor(LIGHT_2, 0x7f7f7fff),
	gsSPEndDisplayList(),
};

Gfx alien_root_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_root_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx alien_torso_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_torso_skinned_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx alien_torso_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_torso_mesh_layer_1_tri_0),
	gsSPDisplayList(alien_torso_mesh_layer_1_tri_1),
	gsSPEndDisplayList(),
};

Gfx alien_head_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_head_skinned_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx alien_head_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_head_mesh_layer_1_tri_0),
	gsSPDisplayList(alien_head_mesh_layer_1_tri_1),
	gsSPEndDisplayList(),
};

Gfx alien_larm_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_larm_skinned_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx alien_larm_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_larm_mesh_layer_1_tri_0),
	gsSPDisplayList(alien_larm_mesh_layer_1_tri_1),
	gsSPEndDisplayList(),
};

Gfx alien_larmu_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_larmu_skinned_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx alien_larmu_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_larmu_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx alien_larmf_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_larmf_skinned_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx alien_larmf_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_larmf_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx alien_hand_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_hand_skinned_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx alien_hand_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_hand_mesh_layer_1_tri_0),
	gsSPDisplayList(alien_hand_mesh_layer_1_tri_1),
	gsSPEndDisplayList(),
};

Gfx alien_rarm_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_rarm_skinned_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx alien_rarm_mesh_layer_1[] = {
	gsSPDisplayList(mat_alien_body),
	gsSPDisplayList(alien_rarm_mesh_layer_1_tri_0),
	gsSPDisplayList(alien_rarm_mesh_layer_1_tri_1),
	gsSPEndDisplayList(),
};

Gfx alien_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

