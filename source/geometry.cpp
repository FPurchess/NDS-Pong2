#include "geometry.h"


/**
 * checks if box2 intersects with box1
 * 
 * @param boundingBox box1
 * @param boundingBox box2
 * @return bool
 */
bool intersect(boundingBox box1, boundingBox box2) {
    if (box1.pos.y + box1.height < box2.pos.y) return false;
	if (box1.pos.y > box2.pos.y + box2.height) return false;

	if (box1.pos.x + box1.width < box2.pos.x) return false;
	if (box1.pos.x > box2.pos.x + box2.width) return false;

    return true;
}
