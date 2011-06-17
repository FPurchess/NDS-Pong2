#include <nds.h>

#include "backgrounds.h"

// Backgrounds
#include "bgmain.h"
#include "bgsub.h"


void initBackgrounds() {
    // Background
    REG_BG3CNT = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY(3);
    
    REG_BG3PA = 1 << 8;
    REG_BG3PB = 0;
    REG_BG3PC = 0;
    REG_BG3PD = 1 << 8;

    REG_BG3X = 0;
    REG_BG3Y = 0;

    // Background 2
    REG_BG2CNT_SUB = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY(3);

    REG_BG2PA_SUB = 1 << 8;
    REG_BG2PB_SUB = 0;
    REG_BG2PC_SUB = 0;
    REG_BG2PD_SUB = 1 << 8;

    REG_BG2X_SUB = 0;
    REG_BG2Y_SUB = 0;
}

