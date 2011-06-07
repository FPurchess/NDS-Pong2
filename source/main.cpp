#include <nds.h>
#include <stdio.h>

#include "panel.h"
#include "ball.h"
#include "game.h"

#define COLOR_BLACK 0

int main(void) {
    panel player1;
    panel player2;
    ball gameBall;

    initGame(&player1, &player2, &gameBall);

    consoleDemoInit();
	videoSetMode(MODE_FB0);
	vramSetBankA(VRAM_A_LCD);

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
