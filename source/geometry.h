#ifndef H_GEOMETRY
#define H_GEOMETRY

// Types

struct point {
    int x;
    int y;
};

typedef point position;

struct box {
    position pos;
    int width;
    int height;
};

typedef box boundingBox;

// Methods

/**
 * checks if box2 collides with box1
 * 
 * @param boundingBox box1
 * @param boundingBox box2
 * @return int 0 no collision, 1-4 clockwise collision
 */
int collision(boundingBox box1, boundingBox box2);

#endif
