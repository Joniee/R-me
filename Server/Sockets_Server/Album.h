#pragma once

#ifndef Album_H
#define Album_H

#include "Song.h"
#include "Linkedlist.h"
#include <string>

typedef class Song;
typedef class Linkedlist;

using namespace std;

class Album
{
private:
	string m_title;
	int m_year;
	string m_artist;
	Linkedlist m_songs;
public:
	Album();
	Album(string, int, string);
	Album(string, int, string, Linkedlist);
	bool setTitle(string);
	string getTitle();
	bool setYear(int);
	int getYear();
	bool setArtist(string);
	string getArtist();
	bool addSong(Song*);
	bool removeSong(Song*);
	Linkedlist getSongs();
	void toString();
};
#endif