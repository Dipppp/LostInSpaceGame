#include "Music.h"

Music::Music(DATAFILE *Data){
	mMusic = new MIDI*[1];
	mMusic[0] = (MIDI *)Data[MUSIC_MID].dat;//load_midi("Music/Music.MID");
}

Music::~Music(){
	for (int i=0; i<1; i++){
        destroy_midi(mMusic[i]);
    }
    delete mMusic;
}

void Music::play(){
	//stop_midi();
	if (play_midi(mMusic[0], 1) != 0) {
		allegro_message("Error playing Midi\n%s exiting program", allegro_error);
		exit(EXIT_FAILURE);
	}
}

void Music::musicToggle(){
	if(!mPaused){
		mPaused = true;
		midi_pause();
	}else{
		mPaused = false;
		midi_resume();
	}
}
