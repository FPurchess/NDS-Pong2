#include <stdio.h>

#include "stats.h"

bool initScoreBox(scoreBox *sBox) {
    if(sBox == NULL)
        return false;
    
    // initialize score
    int iScore[2] = {0,0};
    setScore(sBox, iScore);
    
    return true;
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
    
}

void drawColon(boundingBox box) {
    
}

void drawNumber(boundingBox box, int number) {

}
