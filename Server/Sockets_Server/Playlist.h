#pragma once

#include "Linkedlist.h"

#include <iostream>
#include <string>

using namespace std;

class Playlist {
private:
	int m_numSong;
	string m_name;
	string m_desc;
	Linkedlist m_songs;


public:
	Playlist(string);
	Playlist(string, string);
	bool appendSong(int&);
	bool deleteSong(int&);
};