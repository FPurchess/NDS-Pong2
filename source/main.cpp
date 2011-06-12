#include <nds.h>
#include <stdio.h>

// Includes

#include "player.h"
#include "ball.h"
#include "stats.h"

// Sprites

#include "spriteBall.h"


#define STATS_CONSOLE

#define COLOR_BLACK 0

int main(void) {
    int held;

    player player1;
    player player2;
    ball gameBall;
   /* 
    scoreBox sBox;
    int score[2] = {0,0};
    setScore(&sBox, score);
    
#ifdef STATS_CONSOLE
    consoleDemoInit();
#endif
*/

    // Initalize Graphics Engine
    videoSetMode( MODE_0_2D );
	vramSetBankA(VRAM_A_LCD);
    
    oamInit(&oamMain, SpriteMapping_1D_128, false);
    
    //initScoreBox(&sBox);
	initBall(&gameBall);
    initPlayer1(&player1);
    initPlayer2(&player2);

    dmaCopy(spriteBallPal, SPRITE_PALETTE, 512);

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
        
        for(held=0;held<10000000;held++){}
	}

    return 0;
}
