#pragma once
#include <exception>

using namespace std;

typedef int TElem;

class Queue {
private:
    TElem *elems;
    int capacity;
    int head;
    int tail;
    int nrOfElements;

    void resize(int factor =2);

public:
    Queue(int capacity = 10);

    Queue(const Queue &queue);
    Queue &operator=(const Queue &queue);
    ~Queue();

    void pushElem(TElem elem);
    TElem popElem();
    TElem frontElem() const;
    bool isEmpty() const;
    int size() const;
};