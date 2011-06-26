#ifndef H_PANEL
#define H_PANEL

#include <nds.h>
#include "geometry.h"


// Types

typedef struct {
    boundingBox box;
    int speed;
    int keyUp;
    int keyDown;

    int sprite_offx;
    int sprite_offy;
    
    SpriteEntry *sprite;

    int layer;

    SpriteSize sprite_size;
    SpriteColorFormat sprite_format;
    u16* sprite_gfx; 
} player;


// Methods

void initPlayer1(player *p1);

void initPlayer2(player *p2);

/**
 * @param player p
 * @param int key
 * @return void
 */
void movePlayer(player *p, int key);


/**
 * @param player p
 * @return void
 */
void movePlayerKI(player *p, boundingBox *ball);

#endif
