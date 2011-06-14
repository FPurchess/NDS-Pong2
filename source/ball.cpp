#include <nds.h>
#include <maxmod9.h>
#include <stdio.h>

#include "ball.h"
#include "geometry.h"
#include "player.h"
#include "stats.h"

// Sprites
#include "spriteBall.h"

// Audio
#include "soundbank.h"

void initBall(ball *b) {
    b->speed = 1;
    b->box.pos.x = 100;
    b->box.pos.y = 30;
    b->box.width = 12;
    b->box.height = 12;
    b->direction.x = b->speed;
    b->direction.y = b->speed;

    b->sprite_offx = -2;
    b->sprite_offy = -2;

    b->sprite_size = SpriteSize_16x16;
    b->sprite_format = SpriteColorFormat_256Color;
    b->sprite_gfx = oamAllocateGfx(&oamMain, b->sprite_size, b->sprite_format);

    dmaCopy(spriteBallPal, SPRITE_PALETTE, 512);
    dmaCopy(spriteBallTiles,b->sprite_gfx, spriteBallTilesLen);
}

void drawBall(ball *b) {
    oamSet( &oamMain, 0, b->box.pos.x + b->sprite_offx, b->box.pos.y + b->sprite_offy, 0, 0,
            b->sprite_size, b->sprite_format, b->sprite_gfx,
            -1,false,false,false,false,false);
}

/**
 * @param ball b
 * @return void
 */
void moveBall(ball *b, player *p1, player *p2, scoreBox *sBox) {
    b->box.pos.x += b->direction.x;
    b->box.pos.y += b->direction.y;

    // horizontal collision
    if (b->box.pos.x <= 0) {
       scoring(1, b, sBox); 
    } else if (b->box.pos.x + b->box.width >= SCREEN_WIDTH) {
       scoring(0, b, sBox); 
    } else if (intersect(b->box, p1->box) || intersect(b->box, p2->box)) {
        b->direction.x *= -1;
        mmEffect( SFX_PANEL );
    }
    
    // vertical collision
    if (b->box.pos.y <= 0 || b->box.pos.y + b->box.height >= SCREEN_HEIGHT) {
        b->direction.y *= -1;
    }

}

void scoring(int player, ball *b, scoreBox *sBox) {
    b->direction.x *= -1;
    countPoint(sBox, player);    
    mmEffect( SFX_READY );
}
