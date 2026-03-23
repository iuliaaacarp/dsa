#include "Stack.h"
#include <exception>

Stack::Stack(int capacity) {
    if (capacity < 0) {
        throw exception();
    }
    this->capacity = capacity;
    this->nrOfElements = 0;
    this->elems = new TElem[capacity];
}

Stack::Stack(const Stack &s) {
    this->capacity = s.capacity;
    this->nrOfElements = s.nrOfElements;
    this->elems = new TElem[this->nrOfElements];
    for (int i = 0; i < this->nrOfElements; i++) {
        this->elems[i] = s.elems[i];
    }
}

Stack &Stack::operator=(const Stack &s) {
    this->capacity = s.capacity;
    this->nrOfElements = s.nrOfElements;

    delete[] this->elems;
    this->elems = new TElem[this->nrOfElements];
    for (int i = 0; i < this->nrOfElements; i++) {
        this->elems[i] = s.elems[i];
    }
    return *this;
}

Stack::~Stack() {
    delete[] this->elems;
}

void Stack::resize(int factor) {
    int newCapacity = this->capacity * factor;
    TElem *temp = new TElem[newCapacity];
    for (int i = 0; i < this->nrOfElements; i++) {
        temp[i] = this->elems[i];
    }
    delete[] this->elems;
    this->elems = temp;
    this->capacity = newCapacity;
}

// BC: Theta(capacity)
// WC: Theta(capacity)
// TC: Theta(capacity)

bool Stack::isEmpty() const {
    if (this->nrOfElements == 0) {
        return true;
    }
    return false;
}

// BC = WC = TC: Theta(1)

void Stack::pushElem(TElem elem) {
    if (this->nrOfElements == this->capacity)
        resize(2);
    this->elems[this->nrOfElements] = elem;
    this->nrOfElements++;
}

// BC: Theta(1) when no resize is needed
// WC: Theta(capacity) when a resize is triggered
// TC: O(1) amortized

TElem Stack::popElem() {
    if (this->isEmpty()) {
        throw exception();
    }
    this->nrOfElements--;
    return this->elems[this->nrOfElements];
}

// BC = WC = TC: Theta(1)

TElem Stack::topElem() const {
    if (this->isEmpty()) {
        throw exception();
    }
    return this->elems[this->nrOfElements - 1];
}

// BC = WC = TC: Theta(1)

int Stack::size() const {
    return this->nrOfElements;
}

// BC = WC = TC: Theta(1)