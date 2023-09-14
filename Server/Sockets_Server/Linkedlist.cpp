#include "Linkedlist.h"


Linkedlist::Linkedlist() {
	m_size = 0;
	m_head = new Node();
	m_back = new Node();
}

Linkedlist::Linkedlist(Song *item) {
	Node head(item);
	head.setNext(&head);
	head.setPrevious(&head);
	m_size++;
	m_head = &head;
	m_back = &head;
}

bool Linkedlist::append(Song *item) {
	if (m_size == 0) {
		Node head(item);
		head.setNext(&head);
		head.setPrevious(&head);
		m_size++;
		m_head = &head;
		m_back = &head;
		return true;
	}
	if (m_size >= 1) {
		Node back(m_back, m_head, item);
		m_back->setNext(&back);
		m_head->setPrevious(&back);
		m_back = &back;
		m_size++;
		return true;
	}
	return false;
}

bool Linkedlist::remove(int position) {
	if (position > m_size - 1 || position < 0) {
		return false;
	}
	if (m_size == 0) {
		return false;
	}
	if (m_size == 1) {
		m_size--;
		return true;
	}
	if (m_size > 1) {
		if (position == 0) {
			m_back->setNext(m_head->getNext());
			m_head->getNext()->setPrevious(m_back);
		}
		if (position == m_size - 1)
		{
			removeBack();
		}
		Node* act = m_head;
		for (int i = 0; i < position; i++)
		{
			act = act->getNext();
		}
		act->getPrevious()->setNext(act->getNext());
		act->getNext()->setPrevious(act->getPrevious());
		m_size--;
		return true;
	}
	return false;
}

bool Linkedlist::removeBack()
{
	if (m_size == 0) {
		return false;
	}
	if (m_size == 1) {
		m_head->setNext(m_head);
		m_head->setPrevious(m_head);
		m_back = m_head;
		m_size--;
		return true;
	}
	if (m_size > 1) {
		m_back->getPrevious()->setNext(m_head);
		m_head->setPrevious(m_back->getPrevious());
		m_back = m_back->getPrevious();
		m_size--;
		return true;
	}
	return false;
}

bool Linkedlist::removeSong(Song* item) {
	if (m_size == 0)
	{
		return false;
	}
	if (m_head->getSong() == item)
	{
		return remove(0);
	}
	if (m_back->getSong() == item)
	{
		return removeBack();
	}
	Node* act = m_head;
	while (act->getNext()->getSong() != item)
	{
		act = act->getNext();
	}
	act->getNext()->getNext()->setPrevious(act);
	act->setNext(act->getNext()->getNext());
	m_size--;
	return true;
}

bool Linkedlist::insert(int position, Song* item) {
	if (position < 0 || position > m_size) {
		return false;
	}
	if (m_size == 0) {
		Node head(item);
		m_head = &head;
		m_back = &head;
		m_size++;
		return true;
	}
	if (m_size == 1) {
		if (position == 0) {
			Node head(item);
			m_back->setNext(&head);
			head.setNext(m_head);
			m_head->setPrevious(&head);
			m_head = &head;
			m_size++;
			return true;
		}
		if (position == m_size) {
			append(item);
		}
		if (position > 0) {
			Node* act = m_head;
			for (int i = 0; i < position; i++) {
				act = act->getNext();
			}
			Node head(act->getPrevious(), act, item);
			act->getPrevious()->setNext(&head);
			act->setPrevious(&head);
			m_size++;
			return true;
		}
		return false;
	}
	return false;
}

bool Linkedlist::sort() {
	//TODO
	return false;
}

bool Linkedlist::removeList() {
	m_size = 0;
	m_head = NULL;
	m_back = NULL;
	return true;
}

int Linkedlist::getSize() {
	return m_size;
}

Song* Linkedlist::get(int position) {
	if (m_size == 0) {
		return NULL;
	}
	if (position == 0) {
		return m_head->getSong();
	}
	Node *act = m_head;
	if (position < 0) {
		position = abs(position);
		for (int i = 0; i < position; i++) {
			act = act->getPrevious();
		}
		return act->getSong();
	}
	for (int i = 0; i < position; i++) {
		act = act->getNext();
	}
	return act->getSong();
}

Song* Linkedlist::headSong() {
	return m_head->getSong();
}

Node* Linkedlist::head() {
	return m_head;
}

Song* Linkedlist::backSong() {
	return m_back->getSong();
}

Node* Linkedlist::back() {
	return m_back;
}

void Linkedlist::toString() {
	Node* act = m_head;
	for (int i = 0; i < m_size; i++) {
		cout << i << ". ";
		act->getSong()->toString();
		act = act->getNext();
	}
}