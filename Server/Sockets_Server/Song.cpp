#include "Song.h"

Song::Song() {

}

Song::Song(float time, string title, string path) {
	m_time = time;
	m_title = title;
	m_path = path;
}

Song::~Song() {

}

bool Song::setTime(float time) {
	m_time = time;
	return true;
}

float Song::getTime() {
	return m_time;
}

bool Song::setTitle(string title) {
	m_title = title;
	return true;
}

string Song::getTitle() {
	return m_title;
}

bool Song::setPath(string path) {
	m_path = path;
	return true;
}

string Song::getPath() {
	return m_path;
}

bool Song::setLyrics(string lyrics) {
	m_lyrics = lyrics;
	return true;
}

string Song::getLyrics() {
	return m_lyrics;
}

bool Song::addSimilar(Song song) {
	m_similars.push_back(song);
	return true;
}

bool Song::operator==(Song song) {
	return m_path == song.getPath();
}

void Song::toString() {
	cout << "Title: " << m_title << endl;
}

vector <Song> Song::similars() {
	if (m_seeAlso.size() > 2) {
		vector <Song> similars;
		for (int i = 0; i < 3; i++) {
			similars.push_back(m_similars[i]);
		}
		return m_similars;
	}
	return vector <Song>();
}

vector <Song> Song::seeAlso() {
	if (m_seeAlso.size() > 2) {
		vector <Song> seeAlso3;
		for (int i = 0; i < 3; i++) {
			seeAlso3.push_back(m_seeAlso[i]);
		}
		return m_seeAlso;
	}
	return vector <Song>();
}