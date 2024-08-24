#ifndef RUMBLE_PD_H
#define RUMBLE_PD_H

#include <PR/ultratypes.h>

typedef enum 
{
    PAKSTATE_NOPAK,
    PAKSTATE_UNPLUGGING,
    PAKSTATE_READY = 11         
} PAK_STATE;

typedef enum
{
    RUMBLESTATE_NONE,
    RUMBLESTATE_DETECTED,
    RUMBLESTATE_ENABLED_STOPPED,  
    RUMBLESTATE_ENABLED_STARTING,  
    RUMBLESTATE_ENABLED_RUMBLING,  
    RUMBLESTATE_ENABLED_STOPPING, 
    RUMBLESTATE_DISABLED_STOPPING,
    RUMBLESTATE_DISABLED_STOPPED, 
    RUMBLESTATE_ENABLING          
} RUMBLE_STATE;

typedef struct pakParams
{
    s32 state;
	u32 rumblestate;
	s32 rumblepulsestopat;
	u32 rumblepulselen;
	u32 rumblepulsetimer; 
    float rumblettl;
} pakParams;

#define NUM_PADS 1
extern pakParams g_Paks[NUM_PADS];

void stop_rumble(s32 device);
void update_pd_rumble(void);
void queue_pd_rumble_data(s16 timer, s16 decay);
void pak_rumble(s32 device, f32 numsecs, s32 onduration, s32 offduration);

#endif // RUMBLE_PD_H