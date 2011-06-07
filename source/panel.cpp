#include "panel.h"

/**
 * @param player p
 * @param int key
 * @return void
 */
void movePanel(player *p, int key) {
    if (key & p->keyUp)
        p->box.pos.y -= p->speed;
    if (key & p->keyDown)
        p->box.pos.y += p->speed;

    if (p->box.pos.y < 0)
        p->box.pos.y = 0;
    if (p->box.pos.y > SCREEN_HEIGHT)
        p->box.pos.y = SCREEN_HEIGHT;
}


