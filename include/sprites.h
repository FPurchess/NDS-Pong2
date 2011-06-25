#ifndef H_SPRITES
#define H_SPRITES

// Includes
#include <nds.h>
#include "ball.h"
#include "player.h"


// Attributes

static const int SPRITE_DMA_CHANNEL = 3;

typedef struct {
    int oamId;
    int width;
    int height;
    int angle;
    SpriteEntry * entry;
} SpriteInfo;


// Methods

void initOAMTable(OAMTable *oam);

void updateOAM(OAMTable *oam);

void initSprites(OAMTable * oam, SpriteInfo *spriteInfo);

#endif
