#include <nds.h>
#include <stdio.h>

#include "ball.h"
#include "geometry.h"
#include "panel.h"


/**
 * @param ball b
 * @return void
 */
void moveBall(ball *b, panel *p1, panel *p2) {
    b->box.pos.x += b->direction.x;
    b->box.pos.y += b->direction.y;

    // horizontal collision
    if (b->box.pos.x <= 0 || b->box.pos.x + b->box.width >= SCREEN_WIDTH
        || intersect(b->box, p1->box) || intersect(b->box, p2->box)) {
        b->direction.x *= -1;
    }
    
    // vertical collision
    if (b->box.pos.y <= 0 || b->box.pos.y + b->box.height >= SCREEN_HEIGHT) {
        b->direction.y *= -1;
    }

}


