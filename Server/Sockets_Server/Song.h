#pragma once

#ifndef Song_H
#define Song_H

#include <string>
#include "Linkedlist.h"
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>

typedef class Linkedlist;

using namespace std;

class Song {
private:
	int m_timeM;
	int m_timeS;
	string m_path;
	string m_title;
	string m_lyrics;
	Linkedlist m_seeAlso;
	Linkedlist m_similars;
public:
	Song();
	Song(int, int, string, string);
	~Song() {};
	bool setTime(int, int);
	int getTimeM();
	int getTimeS();
	bool setTitle(string);
	string getTitle();
	bool setPath(string);
	string getPath();
	bool setLyrics(string);
	string getLyrics();
	bool addSimilar(Song);
	bool removeSimilar(Song);
	bool removeSimilar(int);
	bool removeAllSimilars();
	bool addSeeAlso(Song);
	bool removeSeeAlso(Song);
	bool removeSeeAlso(int);
	bool removeAllSeeAlso();
	bool operator==(Song);
	void toString();
	Linkedlist similars();
	Linkedlist seeAlso();
};
#endif