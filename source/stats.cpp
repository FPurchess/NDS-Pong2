#include <stdio.h>
#include <nds.h>

#include "stats.h"

void initScoreBox(scoreBox *sBox) {
    #ifdef STATS_CONSOLE
    consoleDemoInit();
    #endif

    sBox->score[0] = 0;
    sBox->score[1] = 0;
}

/**
 * draws a given scoreBox
 */
void drawStats(scoreBox *scoreBox) {
    #ifdef STATS_CONSOLE
    printf("%d : %d", scoreBox->score[0], scoreBox->score[1]);
    #endif
}

/**
 * Count a point for one side
 *
 * @param scoreBox the score box
 * @param side the side which gets the point, 0-based
 */
void countPoint(scoreBox *scoreBox, int side) {
    scoreBox->score[side]++;
}
