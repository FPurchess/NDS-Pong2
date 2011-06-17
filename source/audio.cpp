#include <nds.h>
#include <maxmod9.h>

// Sounds
#include "soundbank.h"
#include "soundbank_bin.h"


void initAudio(void) {
    mmInitDefaultMem((mm_addr)soundbank_bin);
	
	// load background-music
	mmLoad( MOD_BGMUSIC );

	// load sound effects
    mmLoadEffect( SFX_PANEL );
    mmLoadEffect( SFX_READY );
    mmLoadEffect( SFX_WALL );

	// Start playing background-music
	mmStart( MOD_BGMUSIC, MM_PLAY_LOOP );
}
