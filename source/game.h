#ifndef H_GAME
#define H_GAME

#include "panel.h"
#include "ball.h"


/**
 * @param player p1
 * @param player p2
 * @param ball b
 * @return void
 */
void initGame(player *p1, player *p2, ball *b);

/**
 * @param boundingBox box
 * @return void
 */
void drawObject(boundingBox box, int color);


#endif
