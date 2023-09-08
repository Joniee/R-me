#include "Song.h"


Song::Song() {
	m_timeM = 0;
	m_timeS = 0;
	m_title = "";
	m_path = "";
	m_seeAlso = Linkedlist();
	m_similars = Linkedlist();
}

Song::Song(int min, int sec, string title, string path) {
	m_timeM = min;
	m_timeS = sec;
	m_title = title;
	m_path = path;
	m_seeAlso = Linkedlist();
	m_similars = Linkedlist();
}

bool Song::setTime(int min, int sec) {
	m_timeM = min;
	m_timeS = sec;
	return true;
}

int Song::getTimeM() {
	return m_timeM;
}

int Song::getTimeS() {
	return m_timeS;
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

bool Song::addSimilar(Song song){
	return m_similars.append(&song);
}

bool Song::removeSimilar(Song song) {
	return m_similars.removeSong(&song);
}

bool Song::removeSimilar(int position) {
	return m_similars.remove(position);
}

bool Song::removeAllSimilars() {
	return m_similars.removeList();
}

bool Song::addSeeAlso(Song song) {
	return m_seeAlso.append(&song);
}
bool Song::removeSeeAlso(Song song) {
	return m_seeAlso.removeSong(&song);
}

bool Song::removeSeeAlso(int position) {
	return m_seeAlso.remove(position);
}

bool Song::removeAllSeeAlso() {
	return m_seeAlso.removeList();
}

bool Song::operator==(Song song) {
	return m_path == song.getPath();
}

void Song::toString() {
	cout << "Title: " << m_title << " - Time: " << m_timeM << ":" << m_timeS << endl;
}

Linkedlist Song::similars() {
	return m_similars;
}

Linkedlist Song::seeAlso() {
	return m_seeAlso;
}
