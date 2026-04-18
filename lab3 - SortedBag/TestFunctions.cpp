#include "TestFunctions.h"
#include <cassert>
#include <iostream>

bool relationAsc(TElem elem1, TElem elem2){
    return elem1 <= elem2;
}
bool relationDesc(TElem elem1, TElem elem2){
    return elem1 >= elem2;
}

void testSortedBag(){
    SortedBag bag(relationAsc);

    assert(bag.isEmpty() == true);
    assert(bag.size() == 0);
    assert(bag.exists(10) == false);
    assert(bag.frequency(10) == 0);

    bag.add(10);
    bag.add(5);
    bag.add(10);
    bag.add(20);
    bag.add(5);

    assert(bag.isEmpty() == false);
    assert(bag.size() == 5);
    assert(bag.exists(10) == true);
    assert(bag.frequency(10) == 2);
    assert(bag.frequency(5) == 2);
    assert(bag.frequency(20) == 1);
    assert(bag.frequency(99) == 0);

    assert(bag.remove(99) == false);

    assert(bag.remove(10) == true);
    assert(bag.size() == 4);
    assert(bag.exists(10) == 1);

    assert(bag.remove(10) == true);
    assert(bag.size() == 3);
    assert(bag.exists(10) == false);
    assert(bag.exists(10) == 0);

    bag.remove(5);
    bag.remove(5);
    bag.remove(20);
    assert(bag.isEmpty() == true);
    assert(bag.size() == 0);

    std::cout << "SortedBag Tests Passed!" << "\n";
}

void testSortedBagIterator(){

    SortedBag bag(relationAsc);
    bag.add(5);
    bag.add(20);
    bag.add(5);
    bag.add(10);
    bag.add(10);
    bag.add(10);

    SortedBagIterator it = bag.iterator();

    assert(it.valid() == true);

    assert(it.getCurrent() == 5);
    it.next();
    assert(it.getCurrent() == 5);
    it.next();

    assert(it.getCurrent() == 10);
    it.next();
    assert(it.getCurrent() == 10);
    it.next();
    assert(it.getCurrent() == 10);
    it.next();

    assert(it.getCurrent() == 20);
    it.next();

    assert(it.valid() == false);

    try {
        it.getCurrent();
        assert(false);
    }
    catch (std::exception&) {
        assert(true);
    }

    try {
        it.next();
        assert(false);
    }
    catch (std::exception&) {
        assert(true);
    }

    it.first();
    assert(it.valid() == true);
    assert(it.getCurrent() == 5);
    std::cout << "SortedBagIterator Tests Passed!" << "\n";
}