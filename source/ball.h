#ifndef H_BALL
#define H_BALL

#include "geometry.h"


// Types

struct movingObject {
    boundingBox box;
    int speed;
    position direction;
    int color;
};

typedef movingObject ball;


// Methods

/**
 * @param ball b
 * @return void
 */
void moveBall(ball b);


#endif
