#ifndef FLUDD_H
#define FLUDD_H

#include <PR/ultratypes.h>

#include "types.h"

extern u8 isWearingFludd;

u8 wearing_fludd(struct MarioState *m);
void fludd_hover(struct MarioState *m);

#endif // FLUDD_H