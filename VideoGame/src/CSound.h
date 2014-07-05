/*
file:			CSound.h
description:	Sound.
author:			matthias
*/

#ifndef CSOUND_H
#define CSOUND_H

class CSound
{

private:

	char* path;
	
public:

	CSound();
	~CSound();

	// load or add track
	void addTrack(char* path_to_sounds, int id);

	// play single sound
	void playSound(int id);

	// intended for music, loop track until stopped explicitly
	void startTrack(int id);
	void stopTrack(int id);
};

#endif