#include "Node.h"

Node::Node() {
	m_item = new Song();
	m_previous = new Node();
	m_next = new Node();
}

Node::Node(Song* item) {
	m_item = item;
	m_previous = new Node;
	m_next = new Node;
}

Node::Node(Node* p, Node* n, Song* i)
{
	m_previous = p;
	m_next = n;
	m_item = i;
}

Node* Node::getNext() {
	return m_next;
}

bool Node::setNext(Node* node) {
	m_next = node;
	return true;
}

Node* Node::getPrevious() {
	return m_previous;
}

bool Node::setPrevious(Node* node) {
	m_previous = node;
	return true;
}

Song* Node::getSong() {
	return m_item;
}

bool Node::setSong(Song* item) {
	m_item = item;
	return true;
}
