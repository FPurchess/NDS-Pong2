#include <nds.h>
#include "player.h"

void initPlayer1(player *p1){
    p1->box.pos.x = 5;
    p1->box.pos.y = 20;
    p1->box.width = 10;
    p1->box.height = 60;
    p1->speed = 2;
    p1->keyUp = KEY_UP;
    p1->keyDown = KEY_DOWN;

    p1->sprite_offx = -27;
    p1->sprite_offy = -2;
}

void initPlayer2(player *p2) {
    p2->box.pos.x = SCREEN_WIDTH - 10 - 5; // screen width - panel width - offset
    p2->box.pos.y = 20;
    p2->box.width = 10;
    p2->box.height = 60;
    p2->speed = 2;
    p2->keyUp = KEY_A;
    p2->keyDown = KEY_B;

    p2->sprite_offx = -27;
    p2->sprite_offy = -2;
}


/**
 * @param player p
 * @param int key
 * @return void
 */
void movePlayer(player *p, int key) {
    if (key & p->keyUp)
        p->box.pos.y -= p->speed;
    if (key & p->keyDown)
        p->box.pos.y += p->speed;

    if (p->box.pos.y <= 0)
        p->box.pos.y = 1;
    if (p->box.pos.y + p->box.height >= SCREEN_HEIGHT)
        p->box.pos.y = SCREEN_HEIGHT - p->box.height - 1;


    // Updating sprite position
    p->sprite.x = p->sprite_offx + p->box.pos.x;
    p->sprite.y = p->sprite_offy + p->box.pos.y;
}


