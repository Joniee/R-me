#pragma once

#include "Song.h"

#include <string>
#include <vector>

using namespace std;

class Album
{
private:
	string m_title;
	int m_year;
	string m_artist;
	vector <Song> m_songs;
public:
	Album();
	Album(string, int, string);
	Album(string, int, string, vector <Song>);
	~Album();
	bool setTitle(string);
	string getTitle();
	bool setYear(int);
	int getYear();
	bool setArtist(string);
	string getArtist();
	bool addSong(Song);
	vector <Song> getSongs();
	void toString();
};
