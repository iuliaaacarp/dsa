#include "SortedBag.h"

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
    }
}


bool SortedBag::exists(TElem elem) const{
    return this->frequency(elem) > 0;
}

