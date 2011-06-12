#include <nds.h>
#include "player.h"

// Sprites
#include "spritePlayer.h"


void initPlayer1(player *p1){
    p1->box.pos.x = 5;
    p1->box.pos.y = 20;
    p1->box.width = 10;
    p1->box.height = 62;
    p1->speed = 2;
    p1->keyUp = KEY_UP;
    p1->keyDown = KEY_DOWN;

    p1->sprite_offx = -10;
    p1->sprite_offy = -2;

    p1->sprite_size = SpriteSize_64x64;
    p1->sprite_format = SpriteColorFormat_256Color;
    p1->sprite_gfx = oamAllocateGfx(&oamMain, p1->sprite_size, p1->sprite_format);

    dmaCopy(spritePlayerPal, SPRITE_PALETTE, 512);
    dmaCopy(spritePlayerTiles, p1->sprite_gfx, spritePlayerTilesLen);
}

void initPlayer2(player *p2) {
    p2->box.pos.x = SCREEN_WIDTH - 5 - 5; // screen width - panel width - offset
    p2->box.pos.y = 20;
    p2->box.width = 5;
    p2->box.height = 40;
    p2->speed = 2;
    p2->keyUp = KEY_A;
    p2->keyDown = KEY_B;

    p2->sprite_offx = -10;
    p2->sprite_offy = -2;

    p2->sprite_size = SpriteSize_64x64;
    p2->sprite_format = SpriteColorFormat_256Color;
    p2->sprite_gfx = oamAllocateGfx(&oamMain, p2->sprite_size, p2->sprite_format);

    dmaCopy(spritePlayerTiles,p2->sprite_gfx, spritePlayerTilesLen);
}


void drawPlayer(player *p) {
    oamSet( &oamMain, 0, p->box.pos.y + p->sprite_offy, p->box.pos.x + p->sprite_offx, 0, 0,
            p->sprite_size, p->sprite_format, p->sprite_gfx,
            -1,false,false,false,false,false);
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
}


