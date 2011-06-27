#include <nds.h>
#include <maxmod9.h>
#include <stdio.h>

// Includes
#include "audio.h"
#include "video.h"
#include "backgrounds.h"
#include "sprites.h"
#include "ball.h"
#include "player.h"
#include "stats.h"

// Methods

void mode_oneplayer(void) {
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

    // Init Game-Elements
    initScoreBox(&sBox);
	initBall(&ball);
    initPlayer1(&player1);
    initPlayer2(&player2);

    displayMainBackground();
	displaySubBackground();

    // Init Audio
    initAudio();
    startMusic();
    
    while(!(held & KEY_START)) {
        scanKeys();
        held = keysHeld();

        movePlayer(&player1, held);
        movePlayerKI(&player2, &ball.box);
        moveBall(&ball, &player1, &player2, &sBox);

        swiWaitForVBlank();
        updateOAM(oam);
	}

    //@TODO free memory and clear oamBuffer
    initOAMTable(oam);
    stopMusic();
}
