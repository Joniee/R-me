#include "Playlist.h"

Playlist::Playlist(string name) {
	m_name = name;
}

Playlist::Playlist(string name, string desc) {
	m_name = name;
	m_desc = desc;
}

bool Playlist::appendSong(int& item) {
	return 0;
}

bool Playlist::deleteSong(int& item) {
	return 0;
}