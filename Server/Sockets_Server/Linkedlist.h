#pragma once

#ifndef Linkedlist_H
#define Linkedlist_H


#include "Node.h"
#include "Song.h"

typedef class Node;
typedef class Song;

class Linkedlist
{
private:
	int m_size = 0;
	Node m_head;
	Node m_back;
public:
	Linkedlist();
	Linkedlist(Song*);
	bool append(Song*);
	bool remove(int);
	bool removeBack();
	bool removeSong(Song*);
	bool insert(int, Song*);
	bool sort();
	bool removeList();
	int getSize();
	Song* get(int);
	Song* headSong();
	Node* head();
	Song* backSong();
	Node* back();
	void toString();
};

#endif