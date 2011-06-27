#include <nds.h>

#include "backgrounds.h"

// Backgrounds
#include "splash.h"
#include "bgmain.h"
#include "bgsub.h"
#include "mainmenu0.h"
#include "mainmenu1.h"


// Methods

void initBackgrounds() {
    // Background
    REG_BG2CNT = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY(3);
    
    REG_BG2PA = 1 << 8;
    REG_BG2PB = 0;
    REG_BG2PC = 0;
    REG_BG2PD = 1 << 8;

    REG_BG2X = 0;
    REG_BG2Y = 0;

    // Background 2
    REG_BG3CNT_SUB = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY(3);

    REG_BG3PA_SUB = 1 << 8;
    REG_BG3PB_SUB = 0;
    REG_BG3PC_SUB = 0;
    REG_BG3PD_SUB = 1 << 8;

    REG_BG3X_SUB = 0;
    REG_BG3Y_SUB = 0;
}

void displayMainmenu(int mode) {
    switch (mode) {
        case 0:
            dmaCopyHalfWords(DMA_CHANNEL, mainmenu0Bitmap, (uint16 *)BG_BMP_RAM(0), mainmenu0BitmapLen);
            break;
        case 1:
            dmaCopyHalfWords(DMA_CHANNEL, mainmenu1Bitmap, (uint16 *)BG_BMP_RAM(0), mainmenu1BitmapLen);
            break;
    }
}

void displaySplash() {
    dmaCopyHalfWords(DMA_CHANNEL, splashBitmap, (uint16 *)BG_BMP_RAM_SUB(0), splashBitmapLen);
}

void displayMainBackground() {
    dmaCopyHalfWords(DMA_CHANNEL, bgmainBitmap, (uint16 *)BG_BMP_RAM(0), bgmainBitmapLen);
}

void displaySubBackground() {
    dmaCopyHalfWords(DMA_CHANNEL, bgsubBitmap, (uint16 *)BG_BMP_RAM_SUB(0), bgsubBitmapLen);
}
