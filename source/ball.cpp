#include <nds.h>
#include <stdio.h>

#include "ball.h"
#include "geometry.h"
#include "player.h"


void initBall(ball *b) {
    b->speed = 1;
    b->box.pos.x = 100;
    b->box.pos.y = 30;
    b->box.width = 5;
    b->box.height = 5;
    b->direction.x = b->speed;
    b->direction.y = b->speed;

    b->sprite_size = SpriteSize_64x64;
    b->sprite_format = SpriteColorFormat_256Color;
    b->sprite_gfx = oamAllocateGfx(&oamMain, b->sprite_size, b->sprite_format);
}

void drawBall(ball *b) {
    oamSet( &oamMain, 0, b->box.pos.y + b->sprite_offy, b->box.pos.x + b->sprite_offx, 0, 0,
            b->sprite_size, b->sprite_format, b->sprite_gfx,
            -1,false,false,false,false,false);
}

/**
 * @param ball b
 * @return void
 */
void moveBall(ball *b, player *p1, player *p2) {
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


