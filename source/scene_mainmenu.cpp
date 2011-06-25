#include <nds.h>
#include <stdio.h>

#include "scene_mainmenu.h"

//@TODO replace console with backgrounds


int mainmenu() {
    int held;
    int i;
    int select = 0;

    //@TODO set videomode
    consoleDemoInit();
    videoSetMode(MODE_5_2D | DISPLAY_BG2_ACTIVE);

    //@TODO init backgrounds
    toggleMainmenu(select);

    while(1) {
        scanKeys();
        held = keysHeld();
        
        if (held & KEY_UP) {
            if (select > 0) select--;
            toggleMainmenu(select);
        
        } else if (held & KEY_DOWN) {
            if (select < 2) select++;
            toggleMainmenu(select);
        
        } else if (held & KEY_B) {
            break;
        }

        //@FIXME remove this to gain speed again
        for(i=0;i<10;i++)
            swiWaitForVBlank();
    }

    //@TODO unload backgrounds

    return select;
}



void toggleMainmenu(int select) {
    consoleClear();

    printf("\n\n\t\tM A I N M E N U\n\n");
    switch(select) {
        case 0:
            printf("\t\t* 1 Player\n\n");
            printf("\t\t  2 Player\n\n");
            printf("\t\t  Wifi-Game");
            break;
    
        case 1:
            printf("\t\t  1 Player\n\n");
            printf("\t\t* 2 Player\n\n");
            printf("\t\t  Wifi-Game");
            break;

        case 2:
            printf("\t\t  1 Player\n\n");
            printf("\t\t  2 Player\n\n");
            printf("\t\t* Wifi-Game");
            break;
    }
}
