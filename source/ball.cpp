#include "ball.h"
#include <nds.h>


/**
 * @param ball b
 * @return void
 */
void moveBall(ball *b) {
    b.box.pos.x += b.direction.x;
    b.box.pos.y += b.direction.y;

    // horizontal collision
    if (b.box.pos.x <= 0 || b.box.pos.x >= SCREEN_WIDTH) {
        b.direction.x *= -1;
    }
    
    // vertical collision
    if (b.box.pos.y <= 0 || b.box.pos.y >= SCREEN_HEIGHT) {
        b.direction.y *= -1;
    }
    

}


