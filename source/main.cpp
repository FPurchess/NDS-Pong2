#include <nds.h>
#include <maxmod9.h>
#include <stdio.h>

#define STATS_CONSOLE

// Includes
#include "audio.h"
#include "backgrounds.h"
#include "sprites.h"
#include "ball.h"
#include "player.h"
#include "stats.h"

void initVideo() {
    vramSetMainBanks(VRAM_A_MAIN_BG_0x06000000,
                     VRAM_B_MAIN_BG_0x06020000,
                     VRAM_C_SUB_BG_0x06200000,
                     VRAM_D_LCD);

    vramSetBankE(VRAM_E_MAIN_SPRITE);
    videoSetMode(MODE_5_2D | DISPLAY_BG2_ACTIVE | DISPLAY_SPR_ACTIVE | DISPLAY_SPR_1D );
    videoSetModeSub(MODE_5_2D | DISPLAY_BG3_ACTIVE);
}

int main(void) {
    int held;

    player player1;
    player player2;
    ball ball;
    scoreBox sBox;

    powerOn(POWER_ALL_2D);
    lcdSwap();

    // Initalize Graphics Engine
    initVideo();
    initBackgrounds();

    // Init Sprites
    SpriteInfo spriteInfo[SPRITE_COUNT];
    OAMTable *oam = new OAMTable();
    initOAMTable(oam);
    initSprites(oam, spriteInfo);

    // Init Audio
    initAudio();

    // Init Game-Elements
    initScoreBox(&sBox);
	initBall(&ball);
    initPlayer1(&player1);
    initPlayer2(&player2);

    // Initalize IRQ
    irqInit();
    irqEnable(IRQ_VBLANK);

    displayMainBackground();
	displaySubBackground();

    while(1) {
        scanKeys();
        held = keysHeld();

        consoleClear();

        movePlayer(&player1, held);
        movePlayer(&player2, held);
        moveBall(&ball, &player1, &player2, &sBox);

        swiWaitForVBlank();
        updateOAM(oam);
	}

    return 0;
}
