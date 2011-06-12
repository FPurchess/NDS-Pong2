#include <nds.h>
#include <stdio.h>

#define STATS_CONSOLE

// Includes
#include "ball.h"
#include "player.h"
#include "stats.h"


int main(void) {
    int held;

    player player1;
    player player2;
    ball gameBall;
    scoreBox sBox;

    // Initalize Graphics Engine
    videoSetMode(MODE_0_2D);
	vramSetBankA(VRAM_A_LCD);
    
    oamInit(&oamMain, SpriteMapping_1D_128, false);
    
    initScoreBox(&sBox);
    initPlayer1(&player1);
    initPlayer2(&player2);
	initBall(&gameBall);

    // Initalize IRQ
    irqInit();
    irqEnable(IRQ_VBLANK);

	while(1) {
        scanKeys();
        held = keysHeld();

        //consoleClear();
        
        movePlayer(&player1, held);
        movePlayer(&player2, held);
        moveBall(&gameBall, &player1, &player2);

	    //printf("%d : %d",sBox.score[0],sBox.score[1]);
        
        drawPlayer(&player1);
        drawPlayer(&player2);
        drawBall(&gameBall);

        swiWaitForVBlank();
        oamUpdate(&oamMain);
	}

    return 0;
}
