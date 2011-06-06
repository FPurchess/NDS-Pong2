#include <nds.h>
#include <stdio.h>

#include "panel.h"
#include "ball.h"

#define LCD_W 256
#define LCD_H 192


int main(void) {
    int i;

    panel player1;
    panel player2;
    ball gameBall;

    consoleDemoInit();

	videoSetMode(MODE_FB0);

	vramSetBankA(VRAM_A_LCD);

	for(i = 0; i < 256 * 192; i++) {
		VRAM_A[i] = RGB15(31, 0, 0);
	}

	while(1) {
		swiWaitForVBlank();

        //consoleClear();
	}

    return 0;
}
