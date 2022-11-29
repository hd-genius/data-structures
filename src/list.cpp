#include "list.h"


template <class T>
List<T>::List() {}

template <class T>
List<T>::~List() {}

template <class T>
void List<T>::prepend(T* newValue) {
	Node<T>* currentHead = this->head;
	Node<T>* newNode = new Node<T>(newValue, currentHead);
	this->head = newNode;
	this->tracked_length++;
}

template <class T>
void List<T>::append(T* newValue) {
	Node<T>* newNode = new Node<T>(newValue);
	if (this->head == nullptr) {
		this->head = newNode;
	}
	else {
		Node<T>* currentNode = this->head;
		while (currentNode->next != nullptr) {
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
	this->tracked_length++;
}

template <class T>
T& List<T>::operator[](size_t index) const {
	Node<T>* currentNode = this->head;
	size_t movesRemaining = index;
	while (movesRemaining > 0) {
		currentNode = currentNode->next;
		movesRemaining--;
	}
	return *(currentNode->value);
}

template <class T>
size_t List<T>::length() const {
	return this->tracked_length;
}
