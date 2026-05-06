#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
	this->currPosition = this->col.head;
}

TElem MultiMapIterator::getCurrent() const{
	if (!valid())
		throw std::exception();
	return this->col.elements[this->currPosition];
}

bool MultiMapIterator::valid() const {
	if (this->currPosition != -1)
		return true;
	return false;
}

void MultiMapIterator::next() {
	if (!valid())
		throw std::exception();
	this->currPosition = this->col.next[this->currPosition];
}

void MultiMapIterator::first() {
	this->currPosition = this->col.head;
}

