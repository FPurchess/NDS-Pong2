#include "geometry.h"


/**
 * checks if box2 collides with box1
 * 
 * @param boundingBox box1
 * @param boundingBox box2
 * @return int 0 no collision, 1-4 clockwise collision
 */
int collision(boundingBox box1, boundingBox box2) {
    // top
    if (box1.pos.x <= box2.pos.x && box1.pos.x + box1.height >= box2.pos.x) {
        if (box1.pos.y <= box2.pos.y && box1.pos.y + box1.height >= box2.pos.y + box2.height) {
            return 1;
        }
    }
    
    // right
    if (box1.pos.x <= box2.pos.x && box1.pos.x + box1.width >= box2.pos.x) {
        if (box1.pos.y <= box2.pos.y && box1.pos.y + box1.height >= box2.pos.y) {
            return 2;
        }
    }

    // bottom
    if (box1.pos.x <= box2.pos.x && box1.pos.x + box1.width >= box2.pos.x + box2.width) {
        if (box1.pos.y + box1.height >= box2.pos.y && box1.pos.y <= box2.pos.y) {
            return 3;
        }
    }

    //left
    if (box1.pos.x >= box2.pos.x + box2.width && box1.pos.x + box1.width <= box2.pos.x) {
        if (box1.pos.y <= box2.pos.y + box2.height && box1.pos.y + box1.height >= box2.pos.y) {
            return 4;
        }
    }

    return 0;
}
