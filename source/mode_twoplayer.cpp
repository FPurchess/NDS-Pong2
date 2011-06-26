#include <nds.h>
#include <maxmod9.h>
#include <stdio.h>

// Includes
#include "audio.h"
#include "backgrounds.h"
#include "sprites.h"
#include "ball.h"
#include "player.h"
#include "stats.h"


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

void mode_twoplayer(void) {
    int held = 0;

    player player1;
    player player2;
    ball ball;
    scoreBox sBox;

    // Initalize Graphics Engine
    initVideo();
    initBackgrounds();

    // Init Sprites
    SpriteInfo spriteInfo[SPRITE_COUNT];
    OAMTable *oam = new OAMTable();
    initOAMTable(oam);
    initSprites(oam, spriteInfo);

    static const int BALL_OAM_ID    = 0;
    static const int PLAYER1_OAM_ID = 1;
    static const int PLAYER2_OAM_ID = 2;
    ball.sprite = &oam->oamBuffer[BALL_OAM_ID];
    player1.sprite = &oam->oamBuffer[PLAYER1_OAM_ID];
    player2.sprite = &oam->oamBuffer[PLAYER2_OAM_ID];

    // Init Audio
    initAudio();

    // Init Game-Elements
    initScoreBox(&sBox);
	initBall(&ball);
    initPlayer1(&player1);
    initPlayer2(&player2);

    displayMainBackground();
	displaySubBackground();

    while(1) {
        scanKeys();
        held = keysHeld();

        if (held & KEY_START) break;

        movePlayer(&player1, held);
        movePlayer(&player2, held);
        moveBall(&ball, &player1, &player2, &sBox);

        swiWaitForVBlank();
        updateOAM(oam);
	}

    //@TODO free memory and clear oamBuffer
}
