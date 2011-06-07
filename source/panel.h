#ifndef H_PANEL
#define H_PANEL

#include "geometry.h"


// Types

struct panel {
    boundingBox box;
    int color;
    int speed;
    int keyUp;
    int keyDown;
};

typedef panel player;


// Methods

/**
 * @param player p
 * @param int key
 * @return void
 */
void movePanel(player *p, int key);

#endif
