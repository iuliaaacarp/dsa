#include "SortedBag.h"
#include "SortedBagIterator.h"

// Complexity: Theta(1)
SortedBag::SortedBag(Relation r) {
	this->relation = r;
	this->head = nullptr;
	this->tail = nullptr;
	this->totalSize = 0;
}

// Complexity: Best Case: Theta(1), Worst/Average Case: O(N) where N is the number of distinct elements
void SortedBag::add(TComp e) {
	Node* current = head;
	Node* prev = nullptr;

	while (current != nullptr && relation(current->elem, e)) {
		if (current->elem == e) {
			current->freq++;
			this->totalSize++;
			return;
		}
		prev = current;
		current = current->next;
	}

	if (current != nullptr && current->elem == e) {
		current->freq++;
		this->totalSize++;
		return;
	}

	Node* newNode = new Node{ e, 1, current, prev };

	if (prev != nullptr) {
		prev->next = newNode;
	} else {
		this->head = newNode;
	}

	if (current != nullptr) {
		current->prev = newNode;
	} else {
		this->tail = newNode;
	}

	this->totalSize++;
}

// Complexity: Best Case: Theta(1), Worst/Average Case: O(N)
bool SortedBag::remove(TComp e) {
	Node* current = head;

	while (current != nullptr) {
		if (current->elem == e) {
			current->freq--;
			this->totalSize--;

			if (current->freq == 0) {
				if (current->prev != nullptr) {
					current->prev->next = current->next;
				} else {
					this->head = current->next;
				}

				if (current->next != nullptr) {
					current->next->prev = current->prev;
				} else {
					this->tail = current->prev;
				}
				delete current;
			}
			return true;
		}
		current = current->next;
	}
	return false;
}

// Complexity: Best Case: Theta(1), Worst/Average Case: O(N)
bool SortedBag::search(TComp elem) const {
	Node* current = head;
	while (current != nullptr) {
		if (current->elem == elem) {
			return true;
		}
		current = current->next;
	}
	return false;
}

// Complexity: Best Case: Theta(1), Worst/Average Case: O(N)
int SortedBag::nrOccurrences(TComp elem) const {
	Node* current = head;
	while (current != nullptr) {
		if (current->elem == elem) {
			return current->freq;
		}
		current = current->next;
	}
	return 0;
}

// Complexity: Theta(1)
int SortedBag::size() const {
	return this->totalSize;
}

// Complexity: Theta(1)
bool SortedBag::isEmpty() const {
	return this->totalSize == 0;
}

// Complexity: Theta(1)
SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}

// Complexity: Theta(N)
SortedBag::~SortedBag() {
	Node* current = head;
	while (current != nullptr) {
		Node* toDelete = current;
		current = current->next;
		delete toDelete;
	}
}