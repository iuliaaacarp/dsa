#include "SortedBag.h"

#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation rel){
    this->relation = rel;
    this->head = nullptr;
    this->tail = nullptr;
    this->bagSize = 0;
}

// BC = WC = TC: Theta(N)
SortedBag::~SortedBag(){
    Node *curr = this->head;
    while (curr != nullptr)
    {
        Node *temp = curr->next;
        delete curr;
        curr = temp;
    }
}

// BC = WC = TC: Theta(1)
int SortedBag::size() const{
    return this->bagSize;
}

// BC = WC = TC: Theta(1)
bool SortedBag::isEmpty() const{
    return this->bagSize == 0;
}

// BC = WC = TC: Theta(1)
SortedBagIterator SortedBag::iterator() const{
    return SortedBagIterator(*this);
}

// BC: Theta(1) - List is empty or element belongs at the head.
// WC: Theta(N) - Element belongs at the tail or doesn't exist and goes to the end (N = number of unique elements).
// TC: O(N)
void SortedBag::add(TElem elem){
    Node *curr = this->head;
    while (curr != nullptr && this->relation(curr->elem, elem) && curr->elem != elem){
        curr = curr->next;
    }
    if (curr != nullptr && curr->elem == elem)
        curr->freq++;
    else
    {
        Node *newNode = new Node {elem, 1,nullptr, nullptr};
        if (this->head == nullptr){ // the list is empty
            this->head = newNode;
            this->tail = newNode;
        }
        else if (curr == this->head){ // insert before the head
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = newNode;
        }
        else if (curr == nullptr){ // insert after the tail
            newNode->prev = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;
        }
        else{ // insert in the middle
            newNode->prev = curr->prev;
            newNode->next = curr;
            curr->prev->next = newNode;
            curr->prev = newNode;
        }
    }
    this->bagSize++;
}

// BC: Theta(1) - Element is at the head.
// WC: Theta(N) - Element is at the tail or not in the bag.
// TC: O(N)
bool SortedBag::remove(TElem elem){
    Node *curr = this->head;
    while (curr != nullptr && curr->elem != elem){
        curr = curr->next;
    }
    if (curr == nullptr)
        return false;

    curr->freq--;
    this->bagSize--;
    if (curr->freq == 0)
    {
        if (curr == this->head && curr == this->tail){ // only one node
            this->head = nullptr;
            this->tail = nullptr;
        }
        else if (curr == this->head){ // remove head
            this->head = this->head->next;
            this->head->prev = nullptr;
        }
        else if (curr == this->tail){ // remove tail
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
        }
        else{ // remove in the middle
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        delete curr;
    }
    return true;
}

// BC: Theta(1), WC: Theta(N), TC: O(N)
bool SortedBag::exists(TElem elem) const{
    return this->frequency(elem) > 0;
}

// BC: Theta(1), WC: Theta(N), TC: O(N)
int SortedBag::frequency(TElem elem) const{
    Node *curr = this->head;
    while (curr != nullptr){
        if (curr->elem == elem)
            return curr->freq;
        curr = curr->next;
    }
    return 0;
}
