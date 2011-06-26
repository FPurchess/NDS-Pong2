#include <nds.h>
#include <maxmod9.h>

// Sounds
#include "soundbank.h"
#include "soundbank_bin.h"


// Methods

void initAudio() {
    mmInitDefaultMem((mm_addr)soundbank_bin);

	// load background-music
	mmLoad( MOD_BGMUSIC );

	// load sound effects
    mmLoadEffect( SFX_PANEL );
    mmLoadEffect( SFX_READY );
    mmLoadEffect( SFX_WALL );
}

void playSfx(mm_sound_effect *sound) {
    mmEffectEx( sound );
}

void startMusic() {
    //mmStart( MOD_BGMUSIC, MM_PLAY_LOOP );
}


void stopMusic() {
    mmStop();
}
