#include <nds.h>

#include <video.h>


// Methods

void initVideo() {
    vramSetBankA(VRAM_A_MAIN_BG_0x06000000);
    vramSetBankB(VRAM_B_MAIN_BG_0x06020000);
    vramSetBankC(VRAM_C_SUB_BG_0x06200000);
    vramSetBankD(VRAM_D_LCD);
    vramSetBankE(VRAM_E_MAIN_SPRITE);

    videoSetMode(MODE_5_2D | DISPLAY_BG2_ACTIVE | DISPLAY_SPR_ACTIVE | DISPLAY_SPR_1D);
    videoSetModeSub(MODE_5_2D | DISPLAY_BG3_ACTIVE);
}