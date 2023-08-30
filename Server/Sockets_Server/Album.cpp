#include "Album.h"


Album::Album() {

}

Album::Album(string title, int year, string artist) {
	m_title = title;
	m_year = year;
	m_artist = artist;
}

Album::Album(string title, int year, string artist, vector <Song> songs) {
	m_title = title;
	m_year = year;
	m_artist = artist;
	m_songs = songs;
}

Album::~Album() {

}

bool Album::setTitle(string title) {
	m_title = title;
	return true;
}

string Album::getTitle() {
	return m_title;
}

bool Album::setYear(int year) {
	m_year = year;
	return true;
}

int Album::getYear() {
	return m_year;
}

bool Album::setArtist(string artist) {
	m_artist = artist;
	return true;
}

string Album::getArtist() {
	return m_artist;
}

bool Album::addSong(Song song) {
	m_songs.push_back(song);
	return true;
}

vector <Song> Album::getSongs() {
	return m_songs;
}

void Album::toString() {
	cout << "Album title: " << m_title << endl;
	cout << "Year of publication: " << m_year << endl;
	cout << "Artist: " << m_artist << endl;
	cout << "List of songs: " << endl;
	for (int i = 0; i < m_songs.size(); i++) {
		m_songs[i].toString();
	}
}
