#include <nds.h>
#include <stdio.h>

#include "panel.h"
#include "ball.h"
#include "stats.h"
#include "game.h"

#define STATS_CONSOLE

#define COLOR_BLACK 0

int main(void) {
    int held;

    player player1;
    player player2;
    ball gameBall;
    
    scoreBox sBox;
    if(!initScoreBox(&sBox))
        exit(1);

    int score[2] = {1,2};
    
    setScore(&sBox, score);
    
#ifdef STATS_CONSOLE
    consoleDemoInit();
#endif
    initGame(&player1, &player2, &gameBall);

    irqInit();
    irqEnable(IRQ_VBLANK);

    videoSetMode(MODE_FB0);
	vramSetBankA(VRAM_A_LCD);

	printf("%d : %d",sBox.score[0],sBox.score[1]);
	while(1) {
        scanKeys();
        held = keysHeld();

        drawObject(player1.box, COLOR_BLACK);
        drawObject(player2.box, COLOR_BLACK);
        drawObject(gameBall.box, COLOR_BLACK);

        movePanel(&player1, held);
        movePanel(&player2, held);
        moveBall(&gameBall);

        drawObject(player1.box, player1.color);
        drawObject(player2.box, player2.color);
        drawObject(gameBall.box, gameBall.color);

        swiWaitForVBlank();

        //consoleClear();
	}

    return 0;
}
