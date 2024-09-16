#ifndef OBJECT_COLLISION_H
#define OBJECT_COLLISION_H

void detect_object_collisions(void);
s32 detect_object_hitbox_overlap(struct Object *a, struct Object *b);

#endif // OBJECT_COLLISION_H
