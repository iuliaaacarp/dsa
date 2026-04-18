#pragma once

#include "SortedBag.h"

class SortedBagIterator
{
    friend class SortedBag;
private:
    const SortedBag &bag;
    SortedBag::Node* current;
    int currFreq;

    SortedBagIterator(const SortedBag &bag);

public:
    void first();
    void next();
    TElem getCurrent() const;
    bool valid() const;
};