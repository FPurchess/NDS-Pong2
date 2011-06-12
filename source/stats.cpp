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
 * set score to given values
 *
 * @param *scoreBox
 * @param score[2]
 */
void setScore(scoreBox *scoreBox, int score[2]) {
    if(scoreBox == NULL
    || score == NULL)
        return;
    scoreBox->score[0] = score[0];
    scoreBox->score[1] = score[1];
}

/**
 * change score by given values
 * score may contain negativ values
 *
 * @param *scoreBox
 * @param score
 */
void changeScore(scoreBox *scoreBox, int score[2]) {
    if(scoreBox == NULL
    || score == NULL)
        return;
    scoreBox->score[0] += score[0];
    scoreBox->score[1] += score[1];
}

/**
 * draws a given scoreBox
 */
void drawStats(scoreBox *scoreBox) {
    if(scoreBox == NULL)
        return;
#ifdef STATS_CONSOLE
    printf("%d : %d", scoreBox->score[0], scoreBox->score[1]);
#endif
}

void drawColon(boundingBox box) {
    
}

void drawNumber(boundingBox box, int number) {

}
