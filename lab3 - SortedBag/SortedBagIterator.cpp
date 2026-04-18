#include "SortedBagIterator.h"
#include <exception>

SortedBagIterator::SortedBagIterator(const SortedBag& bag) : bag(bag){
    this->current = this->bag.head;
    this->currFreq = 1;
}

// BC = WC = TC: Theta(1)
void SortedBagIterator::first(){
    this->current = this->bag.head;
    this->currFreq = 1;
}

// BC = WC = TC: Theta(1)
void SortedBagIterator::next(){
    if (!this->valid())
        throw std::exception();

    if (this->currFreq < this->current->freq)
        this->currFreq++;
    else{
        this->current = this->current->next;
        this->currFreq = 1;
    }
}

// BC = WC = TC: Theta(1)
TElem SortedBagIterator::getCurrent() const{
    if (!this->valid())
        throw std::exception();
    return this->current->elem;
}

// BC = WC = TC: Theta(1)
bool SortedBagIterator::valid() const{
    return this->current != nullptr;
}