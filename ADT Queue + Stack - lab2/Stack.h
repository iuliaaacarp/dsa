#pragma once
#include <exception>

using namespace std;

typedef int TElem;

class Stack {
private:
    TElem* elems;
    int capacity;
    int nrOfElements;

    void resize(int factor =2);

public:
    Stack(int capacity = 10);

    Stack(const Stack& stack);
    Stack &operator=(const Stack& stack);
    ~Stack();

    void pushElem(TElem elem);
    TElem popElem();
    TElem topElem() const;
    bool isEmpty() const;
    int size() const;
};