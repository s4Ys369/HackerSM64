Vtx bob_dl_Floor_mesh_layer_1_vtx_0[4] = {
	{{ {-973, 0, 973}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {973, 0, 973}, 0, {1008, 1008}, {0, 127, 0, 255} }},
	{{ {973, 0, -973}, 0, {1008, -16}, {0, 127, 0, 255} }},
	{{ {-973, 0, -973}, 0, {-16, -16}, {0, 127, 0, 255} }},
};

Gfx bob_dl_Floor_mesh_layer_1_tri_0[] = {
	gsSPVertex(bob_dl_Floor_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_bob_dl_shade_Green[] = {
	gsSPLightColor(LIGHT_1, 0x33DD00FF),
	gsSPLightColor(LIGHT_2, 0x146E00FF),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_bob_dl_shade_Green[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx bob_dl_Floor_mesh_layer_1[] = {
	gsSPDisplayList(mat_bob_dl_shade_Green),
	gsSPDisplayList(bob_dl_Floor_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_bob_dl_shade_Green),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

