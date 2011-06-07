#ifndef H_GAME
#define H_GAME

#include "panel.h"
#include "ball.h"


/**
 * @param panel p1
 * @param panel p2
 * @param ball b
 * @return void
 */
void initGame(panel *p1, panel *p2, ball *b);

/**
 * @param panel p
 * @param int key
 * @return void
 */
void movePanelOne(panel *p, int key);

/**
 * @param panel p
 * @param int key
 * @return void
 */
void movePanelTwo(panel *p, int key);

/**
 * @param boundingBox box
 * @return void
 */
void drawObject(boundingBox box, int color);


#endif
