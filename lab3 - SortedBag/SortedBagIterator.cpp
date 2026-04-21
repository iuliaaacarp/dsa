#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

// Complexity: Theta(1)
SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    this->currentNode = bag.head;
    this->currentFreq = 1;
}

// Complexity: Theta(1)
TComp SortedBagIterator::getCurrent() {
    if (!this->valid()) {
        throw exception();
    }
    return this->currentNode->elem;
}

// Complexity: Theta(1)
bool SortedBagIterator::valid() {
    return this->currentNode != nullptr;
}

// Complexity: Theta(1)
void SortedBagIterator::next() {
    if (!this->valid()) {
        throw exception();
    }
    // If there are more occurrences of the current element, just increment frequency counter
    if (this->currentFreq < this->currentNode->freq) {
        this->currentFreq++;
    } else {
        // Otherwise, move to the next node
        this->currentNode = this->currentNode->next;
        this->currentFreq = 1;
    }
}

// Complexity: Theta(1)
void SortedBagIterator::first() {
    this->currentNode = this->bag.head;
    this->currentFreq = 1;
}