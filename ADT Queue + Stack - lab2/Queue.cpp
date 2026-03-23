#include "Queue.h"

Queue::Queue(int capacity) {
    if (capacity <= 0) {
        throw exception();
    }
    this->capacity = capacity;
    this->nrOfElements = 0;
    this->head = 0;
    this->tail = 0;
    this->elems = new TElem[this->capacity];
}

Queue::~Queue() {
    delete[] this->elems;
}

bool Queue::isEmpty() const{
    return this->nrOfElements == 0;
}

// BC = WC = TC: Theta(1)

int Queue::size() const {
    return this->nrOfElements;
}

// BC = WC = TC: Theta(1)

void Queue::resize(int factor) {
    int newCapacity = factor * this->capacity;
    TElem* temp = new TElem[newCapacity];
    for (int i = 0; i < this->nrOfElements; i++) {
        temp[i] = this->elems[(this->head + i) % (this->capacity)];
    }
    delete[] this->elems;
    this->elems = temp;
    this->capacity = newCapacity;
    this->head = 0;
    this->tail = this->nrOfElements;
}

// BC: Theta(capacity)
// WC: Theta(capacity)
// TC: Theta(capacity)

void Queue::pushElem(TElem elem) {
    if (this->nrOfElements == this->capacity)
        resize(2);
    this->elems[this->tail] = elem;
    this->tail = (this->tail + 1) % (this->capacity);
    this->nrOfElements++;
}

// BC: Theta(1) when no resize is needed
// WC: Theta(capacity) when resize is triggered
// TC: O(1) amortized

TElem Queue::popElem() {
    if (this->isEmpty()) {
        throw exception();
    }
    TElem temp = this->elems[this->head];
    this->head = (this->head + 1) % (this->capacity);
    this->nrOfElements--;
    return temp;
}

// BC = WC = TC: Theta(1)

TElem Queue::frontElem() const {
    if (this->isEmpty()) {
        throw exception();
    }
    return this->elems[this->head];
}

// BC = WC = TC: Theta(1)