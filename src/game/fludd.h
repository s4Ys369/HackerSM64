#ifndef FLUDD_H
#define FLUDD_H

#include <PR/ultratypes.h>

#include "types.h"

u8 wearing_fludd(struct MarioState *m);
void fludd_reset_water_level(struct MarioState *m);
void fludd_hover(struct MarioState *m);

#endif // FLUDD_H