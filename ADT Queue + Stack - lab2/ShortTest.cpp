#include "ShortTest.h"

#include <assert.h>
#include <iostream>

#include "Stack.h"
#include "Queue.h"

void TestQueue() {
    cout << "Testing the queue... ";

    Queue q(2);

    assert(q.isEmpty() == true);
    assert(q.size() == 0);

    q.pushElem(2);
    q.pushElem(3);
    q.pushElem(4);

    Queue q2(2);
    assert(q2.isEmpty() == true);
    q2 = q;
    assert(q2.size() == 3);
    assert(q.isEmpty() == false);
    assert(q.frontElem() == 2);

    assert(q.size() == 3);
    assert(q.isEmpty() == false);
    assert(q.frontElem() == 2);

    assert(q2.popElem() == 2);
    assert(q.popElem() == 2);
    q.pushElem(5);
    assert(q.frontElem() == 3);
    assert(q.size() == 3);

    q.pushElem(6);
    assert(q.frontElem() == 3);

    q2 = q;

    assert(q.size() == 4);
    assert(q2.size() == 4);
    assert(q.popElem() == 3);
    assert(q.popElem() == 4);
    assert(q.popElem() == 5);
    assert(q.popElem() == 6);

    assert(q.isEmpty() == true);
    assert(q.size() == 0);

    cout << "All tests ran successfully!";
}

void TestStack() {
    cout << "Testing the stack... ";

    Stack s(2);

    assert(s.isEmpty() == true);
    assert(s.size() == 0);

    s.pushElem(2);
    s.pushElem(3);
    s.pushElem(4);

    Stack s2(5);
    assert(s2.isEmpty() == true);
    assert(s2.size() == 0);
    s2 = s;
    assert(s2.size() == 3);
    assert(s2.isEmpty() == false);
    assert(s2.topElem() == 4);

    assert(s.size() == 3);
    assert(s.isEmpty() == false);
    assert(s.topElem() == 4);

    assert(s2.popElem() == 4);
    assert(s.popElem() == 4);
    assert(s.size() == 2);
    assert(s.topElem() == 3);
    assert(s.isEmpty() == false);
    assert(s.popElem() == 3);
    assert(s.popElem() == 2);

    assert(s.size() == 0);
    assert(s.isEmpty() == true);

    cout << "All tests ran successfully!" << "\n";
}

