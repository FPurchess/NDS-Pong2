#include <nds.h>
#include <stdio.h>

#include "panel.h"
#include "ball.h"
#include "stats.h"

#define LCD_W 256
#define LCD_H 192

#define ERR_INIT_SBOX_FAILED 1


int main(void) {
    int i;

    panel player1;
    panel player2;
    ball gameBall;
    
    scoreBox sBox;
    if(!initScoreBox(&sBox))
        exit(ERR_INIT_SBOX_FAILED);

    int score[2] = {1,2};
    
    setScore(&sBox, score);

//    consoleDemoInit();

	videoSetMode(MODE_FB0);

	vramSetBankA(VRAM_A_LCD);

	for(i = 0; i < 256 * 192; i++) {
		VRAM_B[i] = RGB15(31, 0, 0);
	}
	
	printf("%d : %d",sBox.score[0],sBox.score[1]);

	while(1) {
		swiWaitForVBlank();

        //consoleClear();
	}

    return 0;
}
