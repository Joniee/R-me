#pragma once


#include <string>
#include <vector>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>

using namespace std;

class Song {
private:
	float m_time;
	string m_path;
	string m_title;
	string m_lyrics;
	vector <Song> m_seeAlso;
	vector <Song> m_similars;
public:
	Song();
	Song(float, string, string);
	~Song();
	bool setTime(float);
	float getTime();
	bool setTitle(string);
	string getTitle();
	bool setPath(string);
	string getPath();
	bool setLyrics(string);
	string getLyrics();
	bool addSimilar(Song);
	bool operator==(Song);
	void toString();
	vector <Song> similars();
	vector <Song> seeAlso();
};