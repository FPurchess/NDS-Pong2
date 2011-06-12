#ifndef H_STATS
#define H_STATS

#include "geometry.h"

#define STATS_CONSOLE

typedef struct {
    int score[2];
    boundingBox box;
    int color;
} scoreBox;

void initScoreBox(scoreBox *scoreBox);
void setScore(scoreBox *scoreBox, int score[2]);
void changeScore(scoreBox scoreBox, int score[2]);
void drawStats(scoreBox scoreBox);
void drawColon(boundingBox box);
void drawNumber(boundingBox box, int number);

#endif
