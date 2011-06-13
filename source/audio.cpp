#include <nds.h>
#include <maxmod9.h>

// Sounds
#include "soundbank.h"
#include "soundbank_bin.h"


void initAudio(void) {
    mmInitDefaultMem((mm_addr)soundbank_bin);
	
	// load background-music
	mmLoad( MOD_BGMUSIC );

	// @TODO: load sound effects

	// Start playing module
	mmStart( MOD_BGMUSIC, MM_PLAY_LOOP );
}
