#include "src/game/envfx_snow.h"

const GeoLayout hover_jet_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hover_jet_hover_jet_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
