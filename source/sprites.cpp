#include <nds.h>

#include "sprites.h"
#include "ball.h"
#include "player.h"

// Sprites
#include "spriteBall.h"
#include "spritePlayer.h"
//#include "spritePlayer2.h"


// Methods

void initOAMTable(OAMTable *oam) {
    for (int i = 0; i < SPRITE_COUNT; i++) {
        oam->oamBuffer[i].attribute[0] = ATTR0_DISABLED;
        oam->oamBuffer[i].attribute[1] = 0;
        oam->oamBuffer[i].attribute[2] = 0;
    }
    for (int i = 0; i < MATRIX_COUNT; i++) {
        oam->matrixBuffer[i].hdx = 1 << 8;
        oam->matrixBuffer[i].hdy = 0;
        oam->matrixBuffer[i].vdx = 0;
        oam->matrixBuffer[i].vdy = 1 << 8;
    }
    updateOAM(oam);
}

void updateOAM(OAMTable *oam) {
    DC_FlushAll();
    dmaCopyHalfWords(SPRITE_DMA_CHANNEL,
                     oam->oamBuffer,
                     OAM,
                     SPRITE_COUNT * sizeof(SpriteEntry));
}

void initSprites(OAMTable * oam, SpriteInfo *spriteInfo) {
    /*  Define some sprite configuration specific constants.
     * 
     *  We will use these to compute the proper index into memory for certain
     *  tiles or palettes.
     *
     *  OFFSET_MULTIPLIER is calculated based on the following formula from
     *  GBATEK (http://nocash.emubase.de/gbatek.htm#dsvideoobjs):
     *      TileVramAddress = TileNumber * BoundaryValue
     *  Since SPRITE_GFX is a uint16*, the compiler will increment the address
     *  it points to by 2 for each change in 1 of the array index into
     *  SPRITE_GFX. (The compiler does pointer arithmetic.)
     */
    static const int BYTES_PER_16_COLOR_TILE = 32;
    static const int COLORS_PER_PALETTE = 16;
    static const int BOUNDARY_VALUE = 32; /* This is the default boundary value
                                           * (can be set in REG_DISPCNT) */
    static const int OFFSET_MULTIPLIER = BOUNDARY_VALUE /
                                         sizeof(SPRITE_GFX[0]);

    /* Keep track of the available tiles */
    int nextAvailableTileIdx = 0;

    /* Create the ship sprite. */
    static const int BALL_OAM_ID = 0;
    SpriteInfo * ballInfo = &spriteInfo[BALL_OAM_ID];
    SpriteEntry * ball = &oam->oamBuffer[BALL_OAM_ID];

    /* Initialize shuttleInfo */
    ballInfo->oamId = BALL_OAM_ID;
    ballInfo->width = 16;
    ballInfo->height = 16;
    ballInfo->angle = 0;
    ballInfo->entry = ball;

    /*
     *  Configure attribute 0. 
     *
     *  OBJCOLOR_16 will make a 16-color sprite. We specify that we want an
     *  affine sprite (via isRotateScale) here because we would like to rotate
     *  the ship.
     */
    ball->y = SCREEN_HEIGHT / 2 - ballInfo->height;
    ball->isRotateScale = false;
    ball->isSizeDouble = false;
    ball->blendMode = OBJMODE_NORMAL;
    ball->isMosaic = false;
    ball->colorMode = OBJCOLOR_16;
    ball->shape = OBJSHAPE_SQUARE;

    /*
     *  Configure attribute 1.
     *
     *  rotationIndex refers to the loation of affine transformation matrix. We
     *  set it to a location computed with a macro. OBJSIZE_64, in our case
     *  since we are making a square sprite, creates a 64x64 sprite.
     */
    ball->x = SCREEN_WIDTH / 2 - ballInfo->width * 2 +
                    ballInfo->width / 2;
    ball->size = OBJSIZE_16;

    /* 
     *  Configure attribute 2.
     * 
     *  Configure which tiles the sprite will use, which priority layer it will
     *  be placed onto, which palette the sprite should use, and whether or not
     *  to show the sprite.
     */
    ball->gfxIndex = nextAvailableTileIdx;
    nextAvailableTileIdx += spriteBallTilesLen / BYTES_PER_16_COLOR_TILE;
    ball->priority = OBJPRIORITY_0;
    ball->palette = ballInfo->oamId;

    // copy palette 
    dmaCopyHalfWords(SPRITE_DMA_CHANNEL,
                     spriteBallPal,
                     &SPRITE_PALETTE[ballInfo->oamId *
                                     COLORS_PER_PALETTE],
                     spriteBallPalLen);

    // copy sprite
    dmaCopyHalfWords(SPRITE_DMA_CHANNEL,
                     spriteBallTiles,
                     &SPRITE_GFX[ball->gfxIndex * OFFSET_MULTIPLIER],
                     spriteBallTilesLen);

}

