#include "game.h"
#include <nds.h>
#include <stdio.h>


/**
 * @param panel p1
 * @param panel p2
 * @param ball b
 * @return void
 */
void initGame(panel *p1, panel *p2, ball *b) {
    // Ball
    b->speed = 2;
    b->box.pos.x = 100;
    b->box.pos.y = 30;
    b->box.width = 5;
    b->box.height = 5;
    b->color = RGB15(31,31,10);
    b->direction.x = b->speed;
    b->direction.y = b->speed;

    // Panel 1
    p1->box.pos.x = 5;
    p1->box.pos.y = 20;
    p1->box.width = 5;
    p1->box.height = 40;
    p1->speed = 2;
    p1->color = RGB15(20,0,0);

    // Panel 2
    p2->box.pos.x = SCREEN_WIDTH - 5 - 5; // screen width - panel width - offset
    p2->box.pos.y = 20;
    p2->box.width = 5;
    p2->box.height = 40;
    p2->speed = 2;
    p2->color = RGB15(20,0,0);
}

/**
 * @param panel p
 * @param int key
 * @return void
 */
void movePanelOne(panel *p, int key) {
    if (key & KEY_UP)
        p->box.pos.y -= 1;
    if (key & KEY_DOWN)
        p->box.pos.y += 1;
}

/**
 * @param panel p
 * @param int key
 * @return void
 */
void movePanelTwo(panel *p, int key) {
    if (key & KEY_A)
        p->box.pos.y -= 1;
    if (key & KEY_B)
        p->box.pos.y += 1;
}

/**
 * @param boundingBox box
 * @return void
 */
void drawObject(boundingBox box, int color) {
    int x,y;

    for(x = box.pos.x + box.width; x >= box.pos.x; x--) {
        for(y = box.pos.y + box.height; y >= box.pos.y; y--) {
		    VRAM_A[y * SCREEN_WIDTH + x] = color;
	    }
    }
}


