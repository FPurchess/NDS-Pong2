#include <nds.h>
#include <maxmod9.h>
#include <stdio.h>

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


//@TODO replace console with backgrounds

void initMainmenuVideo() {
    consoleDemoInit();
    videoSetMode(MODE_5_2D | DISPLAY_BG2_ACTIVE);
}

void printMainmenu(int mode) {
    printf("\n\n\t\tM A I N M E N U\n\n");
    for(int i=0;i<=GAME_MODE_LENGTH;i++) {
        printf("\t\t%c %s\n\n", i==mode ? '*' : ' ', gameModes[i].name);
    }
}

int main(void) {
    int i, held = 0, mode = 0;
    
    powerOn(POWER_ALL);
    lcdSwap();

    initMainmenuVideo();

    while(1) {
        consoleClear();
        printMainmenu(mode);
    
        scanKeys();
        held = keysHeld();

        if (held & KEY_UP && mode > 0) {
            mode--;

        } else if (held & KEY_DOWN && mode < GAME_MODE_LENGTH) {
            mode++;

        } else if (held & KEY_A) {
            gameModes[mode].funcp();
            initMainmenuVideo();
        }

        //@FIXME remove this to gain speed again
        for(i=0;i<5;i++)
            swiWaitForVBlank();
	}

    return 0;
}
