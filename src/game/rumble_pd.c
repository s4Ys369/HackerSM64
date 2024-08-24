#include <ultra64.h>
#include "macros.h"
#include "config.h"

#include "buffers/buffers.h"
#include "main.h"
#include "rumble.h"

pakParams g_Paks[NUM_PADS];

void stop_rumble(s32 device)
{

    cancel_rumble();


    if (g_Paks[device].rumblestate != RUMBLESTATE_DISABLED_STOPPING && g_Paks[device].rumblestate != RUMBLESTATE_DISABLED_STOPPED) {
        g_Paks[device].rumblestate = RUMBLESTATE_ENABLED_STOPPING;
    }

    g_Paks[device].rumblettl = -1;
}

void update_pd_rumble(void)
{
	s32 i;

	for (i = 0; i < NUM_PADS; i++) {
		if (sRumblePakThreadActive) {
			switch (g_Paks[i].rumblestate) {
			case RUMBLESTATE_ENABLED_STARTING:
				g_Paks[i].rumblestate = RUMBLESTATE_ENABLED_RUMBLING;
				set_motor(MOTOR_START);
				break;
			case RUMBLESTATE_ENABLED_RUMBLING:
				if (g_Paks[i].rumblepulsestopat != -1) {
					if (g_Paks[i].rumblepulsetimer == 0) {
						set_motor(MOTOR_START);
					} else if ((u32)g_Paks[i].rumblepulsestopat == g_Paks[i].rumblepulsetimer) {
						set_motor(MOTOR_STOP);
					}

					g_Paks[i].rumblepulsetimer++;

					if (g_Paks[i].rumblepulselen == g_Paks[i].rumblepulsetimer) {
						g_Paks[i].rumblepulsetimer = 0;
					}
				}

				g_Paks[i].rumblettl--;

				if (g_Paks[i].rumblettl < 0) {
					g_Paks[i].rumblestate = RUMBLESTATE_ENABLED_STOPPING;
				}
				break;
			case RUMBLESTATE_ENABLED_STOPPING:
				g_Paks[i].rumblestate = RUMBLESTATE_ENABLED_STOPPED;
				set_motor(MOTOR_STOP);
				break;
			case RUMBLESTATE_DISABLED_STOPPING:
				set_motor(MOTOR_STOP);
				g_Paks[i].rumblestate = RUMBLESTATE_DISABLED_STOPPED;
				break;
			case RUMBLESTATE_ENABLING:
				g_Paks[i].rumblestate = RUMBLESTATE_ENABLED_STOPPED;
				g_Paks[i].rumblettl = -1;
				break;
			}
		}
	}
}

void queue_pd_rumble_data(s16 timer, s16 decay) {
    if (gCurrDemoInput != NULL) {
        return;
    }

    struct RumbleData* queueEnd = &gRumbleDataQueue[RUMBLE_QUEUE_SIZE - 1];

    // Write the rumble command.
    queueEnd->event = RUMBLE_EVENT_CONSTON;
    queueEnd->level = 80;
    queueEnd->timer = timer;
    queueEnd->decay = decay;
}

void pak_rumble(s32 device, f32 numsecs, s32 onduration, s32 offduration)
{

	if (sRumblePakThreadActive
			&& g_Paks[device].rumblestate != RUMBLESTATE_DISABLED_STOPPING
			&& g_Paks[device].rumblestate != RUMBLESTATE_DISABLED_STOPPED
			&& g_Paks[device].rumblettl < 60 * numsecs) {
		g_Paks[device].rumblestate = RUMBLESTATE_ENABLED_STARTING;
		g_Paks[device].rumblettl = 60 * numsecs;
		g_Paks[device].rumblepulsestopat = onduration;
		g_Paks[device].rumblepulselen = onduration + offduration;
		g_Paks[device].rumblepulsetimer = 0;
        queue_pd_rumble_data((s16)onduration, (s16)offduration);
	}
}