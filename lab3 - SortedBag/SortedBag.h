#pragma once
#include <exception>

typedef int TElem;
typedef bool (*Relation)(TElem, TElem);

class SortedBagIterator;

class SortedBag
{
    friend class SortedBagIterator;
private:
    struct Node
    {
        TElem elem;
        int freq;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;
    Relation relation;
    int bagSize;

public:
    SortedBag(Relation rel);
    ~SortedBag();
    int size() const;
    bool isEmpty() const;
    SortedBagIterator iterator() const;

    void add(TElem elem);
    bool remove(TElem elem);
    bool exists(TElem elem) const;
    int frequency(TElem elem) const;
};