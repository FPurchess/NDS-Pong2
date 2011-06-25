#ifndef H_BALL
#define H_BALL

#include <nds.h>
#include <maxmod9.h>

#include "geometry.h"
#include "player.h"
#include "stats.h"


// Types

typedef struct {
    boundingBox box;
    
    float speed;
    position direction;

    SpriteEntry *sprite;

    int sprite_offx;
    int sprite_offy;

    mm_sound_effect sfx_wall;
    mm_sound_effect sfx_panel;
    mm_sound_effect sfx_scoring;
} ball;



// Methods

void initBall(ball *b);

/**
 * @param ball b
 * @return void
 */
void moveBall(ball *b, player *p1, player *p2, scoreBox *sBox);

void scoring(int player, ball *b, scoreBox *sBox);

#endif
