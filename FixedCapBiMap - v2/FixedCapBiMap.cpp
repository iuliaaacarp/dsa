#include "FixedCapBiMap.h"

#include <stdexcept>

#include "FixedCapBiMapIterator.h"

FixedCapBiMap::FixedCapBiMap(int capacity) {
	if (capacity <= 0) {
		throw exception();
	}
	this->capacity = capacity;
	this->nelements = 0;
	this->elements = new TElem[this->capacity];
}

FixedCapBiMap::~FixedCapBiMap() {
	delete[] this->elements;
}

bool FixedCapBiMap::add(TKey c, TValue v){
	if (this->nelements == this->capacity) {
		throw exception();
	}
	int count = 0, index = 0;
	while (count < 2 && index < this->nelements) {
		if (this->elements[index].first == c) count++;
		index++;
	}
	if (count == 2)
		return false;
	this->elements[this->nelements].first = c;
	this->elements[this->nelements].second = v;
	this->nelements++;
	return true;
}

ValuePair FixedCapBiMap::search(TKey c) const{
	ValuePair result;
	result.first = NULL_TVALUE;
	result.second = NULL_TVALUE;
	int nrFound = 0;
	int index = 0;
	while (nrFound < 2 && index < this->nelements) {
		if (this->elements[index].first == c) {
			if (nrFound == 0) {
				result.first = this->elements[index].second;
				nrFound++;
			}
			else {
				result.second = this->elements[index].second;
				nrFound++;
			}
		}
		index++;
	}
	return result;
}

bool FixedCapBiMap::remove(TKey c, TValue v){
	int index = 0;
	while (index < this->nelements) {
		if (this->elements[index].first == c && this->elements[index].second == v) {
			this->elements[index] = this->elements[this->nelements - 1];
			this->nelements--;
			return true;
		}
		index++;
	}
	return false;
}


int FixedCapBiMap::size() const {
	return this->nelements;
}

bool FixedCapBiMap::isEmpty() const{
	if (this->nelements == 0) return true;
	return false;
}

bool FixedCapBiMap::isFull() const {
	if (this->nelements == this->capacity) return true;
	return false;
}

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
	return FixedCapBiMapIterator(*this);
}



