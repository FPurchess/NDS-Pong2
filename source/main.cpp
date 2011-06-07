#include <nds.h>
#include <stdio.h>

#include "panel.h"
#include "ball.h"
#include "stats.h"
#include "game.h"

#define COLOR_BLACK 0

int main(void) {
    panel player1;
    panel player2;
    ball gameBall;
    
    scoreBox sBox;
    if(!initScoreBox(&sBox))
        exit(1);

    int score[2] = {1,2};
    
    setScore(&sBox, score);

//    consoleDemoInit();
    initGame(&player1, &player2, &gameBall);

	videoSetMode(MODE_FB0);
	vramSetBankA(VRAM_A_LCD);

	printf("%d : %d",sBox.score[0],sBox.score[1]);
	while(1) {
        drawObject(player1.box, COLOR_BLACK);
        drawObject(player2.box, COLOR_BLACK);
        drawObject(gameBall.box, COLOR_BLACK);

        drawObject(player1.box, player1.color);
        drawObject(player2.box, player2.color);
        drawObject(gameBall.box, gameBall.color);

        movePanelOne(&player1, 0);
        movePanelTwo(&player2, 0);
        moveBall(&gameBall);

        swiWaitForVBlank();

        //consoleClear();
	}

    return 0;
}
