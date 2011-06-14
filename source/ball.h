#ifndef H_BALL
#define H_BALL

#include "geometry.h"
#include "player.h"
#include "stats.h"


// Types

typedef struct {
    boundingBox box;
    
    int speed;
    position direction;
    
    int sprite_offx;
    int sprite_offy;
    
    SpriteSize sprite_size;
    SpriteColorFormat sprite_format;
    u16* sprite_gfx; 
} ball;



// Methods

void initBall(ball *b);

void drawBall(ball *b);

/**
 * @param ball b
 * @return void
 */
void moveBall(ball *b, player *p1, player *p2, scoreBox *sBox);

void scoring(int player, ball *b, scoreBox *sBox);

#endif
