#include <nds.h>

#include "scene_mainmenu.h"
#include "mode_oneplayer.h"
#include "mode_twoplayer.h"


int main(void) {
    int gameMode;
    
    powerOn(POWER_ALL);
    lcdSwap();

    while(1) {
        gameMode = mainmenu();

        switch (gameMode) {
            case 0:
                mode_oneplayer();
                break;
            case 1:
                mode_twoplayer();
                break;
        }
	}

    return 0;
}
