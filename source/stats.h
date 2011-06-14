#ifndef H_STATS
#define H_STATS

#include "geometry.h"

#define STATS_CONSOLE

typedef struct {
    int score[2];
    boundingBox box;
    int color;
} scoreBox;

/**
 * Initializes the given score box and sets it as the score box for the current game
 *
 * @param scoreBox the score box to initialize
 */
void initScoreBox(scoreBox *scoreBox);

/**
 * Draws the given score box.
 *
 * @param scoreBox the score box to redraw
 */
void drawStats(scoreBox *scoreBox);

/**
 * Count a point for one side
 *
 * @param scoreBox the score box
 * @param side the side which gets the point, 0-based
 */
void countPoint(scoreBox scoreBox, int side);

#endif
