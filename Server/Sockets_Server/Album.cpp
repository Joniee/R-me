#include "Album.h"


Album::Album() {
	m_title = "";
	m_year = 0;
	m_artist = "";
	m_songs = Linkedlist();
}

Album::Album(string title, int year, string artist) {
	m_title = title;
	m_year = year;
	m_artist = artist;
}

Album::Album(string title, int year, string artist, Linkedlist list) {
	m_title = title;
	m_year = year;
	m_artist = artist;
	m_songs = list;
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

bool Album::addSong(Song* song) {
	return m_songs.append(song);
}

bool Album::removeSong(Song* song) {
	return m_songs.removeSong(song);
	
}

Linkedlist Album::getSongs() {
	return m_songs;
}

void Album::toString() {
	cout << "Album title: " << m_title << endl;
	cout << "Year of publication: " << m_year << endl;
	cout << "Artist: " << m_artist << endl;
	cout << "List of songs: " << endl;
	m_songs.toString();
}
