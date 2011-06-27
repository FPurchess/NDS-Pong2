#include <nds.h>
#include <maxmod9.h>
#include <stdio.h>

#include "video.h"
#include "backgrounds.h"
#include "mode_oneplayer.h"
#include "mode_twoplayer.h"


#define GAME_MODE_LENGTH 1

typedef struct {
    const char *name;
    void (*funcp)(void);
} funcmap;

const funcmap gameModes[] = {
    {"1 Player", mode_oneplayer},
    {"2 Player", mode_twoplayer}
};


int main(void) {
    int held = 0, mode = 0;
    
    powerOn(POWER_ALL);
    lcdSwap();

    initVideo();
    
    initBackgrounds();
    displaySplash();
    displayMainmenu(mode);

    while(1) {
        consoleClear();
    
        scanKeys();
        held = keysHeld();

        if (held & KEY_UP && mode > 0) {
            mode--;
            displayMainmenu(mode);

        } else if (held & KEY_DOWN && mode < GAME_MODE_LENGTH) {
            mode++;
            displayMainmenu(mode);

        } else if (held & KEY_A) {
            gameModes[mode].funcp();
            initVideo();
            displayMainmenu(mode);
        }

        swiWaitForVBlank();
	}

    return 0;
}
