#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

void MultiMap::resize(){
	int newCapacity = this->capacity * 2;
	TElem *newElems = new TElem[newCapacity];
	int *newNext = new int[newCapacity];
	int *newPrev = new int[newCapacity];

	for (int i = 0; i < this->capacity; i++){
		newElems[i] = this->elements[i];
		newNext[i] = this->next[i];
		newPrev[i] = this->prev[i];
	}

	for (int i = this->capacity; i < newCapacity; i++)
		newNext[i] = i + 1;

	newNext[newCapacity - 1] = -1;

	delete[] this->elements;
	this->elements = newElems;

	delete[] this->next;
	this->next = newNext;

	delete[] this->prev;
	this->prev = newPrev;

	this->firstFree = this->capacity;
	this->capacity = newCapacity;
}

MultiMap::MultiMap() {
	this->capacity = 10;
	this->elements = new TElem[this->capacity];
	this->next = new int[this->capacity];
	this->prev = new int[this->capacity];

	head = -1;
	tail = -1;
	this->mapSize = 0;

	for (int i = 0; i < this->capacity - 1; i++)
		next[i] = i + 1;

	next[this->capacity - 1] = -1;
	firstFree = 0;
}


void MultiMap::add(TKey c, TValue v) {
	if (this->firstFree == -1)
		resize();

	int pos = this->firstFree;
	this->firstFree = next[this->firstFree];

	this->elements[pos] = std::make_pair(c, v);
	next[pos] = -1;

	if (this->head == -1){
		this->head = pos;
		this->tail = pos;
		this->prev[pos] = -1;
	}
	else{
		this->next[this->tail] = pos;
		this->prev[pos] = this->tail;
		this->tail = pos;
	}
	this->mapSize++;
}


bool MultiMap::remove(TKey c, TValue v) {
	int curr = this->head;

	while (curr != -1){
		if (this->elements[curr].first == c && this->elements[curr].second == v){
			if (curr == this->head && curr == this->tail){
				this->head = -1;
				this->tail = -1;
			}
			else if (curr == this->head){
				this->head = next[curr];
				if (this->head != -1)
					this->prev[this->head] = -1;
			}
			else if (curr == this->tail){
				this->tail = this->prev[curr];
				if (this->tail != -1)
					this->next[this->tail] = -1;
			}
			else{
				this->next[this->prev[curr]] = this->next[curr];
				this->prev[this->next[curr]] = this->prev[curr];
			}
			this->next[curr] = this->firstFree;
			this->firstFree = curr;
			this->mapSize--;
			return true;
		}
		curr = this->next[curr];
	}

	return  false;
}


vector<TValue> MultiMap::search(TKey c) const {
	vector<TValue> result;
	int curr = this->head;

	while (curr != -1){
		if (this->elements[curr].first == c)
			result.push_back(this->elements[curr].second);
		curr = this->next[curr];
	}

	return result;
}


int MultiMap::size() const {
	return this->mapSize;
}


bool MultiMap::isEmpty() const {
	if (this->mapSize == 0) return true;
	return false;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
	delete[] this->elements;
	delete[] this->next;
	delete[] this->prev;
}

