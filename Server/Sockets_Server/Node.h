#pragma once

#include "Song.h"

#ifndef Node_H
#define Node_H

typedef class Song;

class Node
{
private:
	Node *m_previous;
	Node *m_next;
	Song *m_item;
public:
	Node();
	Node(Song*);
	Node(Node*, Node*, Song*);
	~Node() {};
	Node* getNext();
	bool setNext(Node*);
	Node* getPrevious();
	bool setPrevious(Node*);
	Song* getSong();
	bool setSong(Song*);
};

#endif