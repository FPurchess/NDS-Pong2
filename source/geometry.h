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
 * checks if box2 intersects with box1
 *
 * @param boundingBox box1
 * @param boundingBox box2
 * @return bool
 */
bool intersect(boundingBox box1, boundingBox box2);

#endif
