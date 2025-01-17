#include "linkedlist.h"

#include <stdexcept>
#include <functional>

LinkNode::LinkNode(int value) : value(value), next(nullptr) {}

/**
 * @test
 * @SUBCASE create
 * INPUT LinkedList llist();
 * EXPECT llist.head == nullptr;
 */
LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    LinkNode* current = head;
    while (current != nullptr) {
        LinkNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

// Private

bool LinkedList::isInRange(int index) const {
    return (index >= 0 && index < size);
}

void LinkedList::ensureInRange(int index) const {
    if (!isInRange(index)) {
        throw std::out_of_range("Out of range");
    }
}

LinkNode* LinkedList::getNode(int index) const {
    LinkNode* current = head;
    int i = 0;
    while (i != index) {
        if (current->next == nullptr) {
            return current;
        }
        current = current->next;
        ++i;
    }
    return current;
}

// Public

/**
 * @test
 * CASE 1: normal
 * SET 5->4->3->2->1
 * INPUT set(2, 42);
 * EXPECT 5->4->42->2->0
 */
void LinkedList::set(int index, int value) {
    ensureInRange(index);

    LinkNode* node = getNode(index);
    node->value = value;
}

/**
 * @test
 * CASE 1: normal
 * SET 5->4->3->2->1
 * INPUT llist.get(2);
 * EXPECT 3;
 *
 * CASE 2: exception
 * INPUT llist.get(-1);
 * EXPECT std::out_of_range;
 */
int LinkedList::get(int index) const {
    ensureInRange(index);

    LinkNode* node = getNode(index);
    return node->value;
}

/**
 * @notest
 */
void LinkedList::push_front(int value) {
    LinkNode* temp = head;
    head = new LinkNode(value);
    head->next = temp;
    size = size + 1;
}

/**
 * @test
 * CASE 1: normal
 * SET 5->4->3->2->1;
 * INPUT pop_front()
 * EXPECT 4->3->2->1, size=4;
 *
 * CASE 2: exception
 * INPUT pop_front()
 * EXPECT std::runtime_error
 */
int LinkedList::pop_front() {
    if (isEmpty()) {
        throw std::runtime_error("Attempt to delete an element from "
                                 "an empty linked list");
    }
    int value = head->value;
    LinkNode* oldHead = head;
    head = head->next;
    delete oldHead;
    size = size - 1;
    return value;
}

/**
 * @test
 * CASE 1: normal
 * SET 5->4->3->2->1;
 * INPUT push_back(42);
 * EXPECT 5->4->3->2->1->42, size=6;
 */
void LinkedList::push_back(int value) {
    if (isEmpty()) {
        head = new LinkNode(value);
    } else {
        LinkNode* tail = getNode(-1);
        tail->next = new LinkNode(value);
    }
    size = size + 1;
}

int LinkedList::pop_back() {
    throw std::runtime_error("Function not implemented");
    return -1;
}

void LinkedList::insert(int index, int value) {
    throw std::runtime_error("Function not implemented");
}

void LinkedList::remove(int index) {
    throw std::runtime_error("Function not implemented");
}

int LinkedList::find(int value) const {
    throw std::runtime_error("Function not implemented");
    return -1;
}

/**
 * @notest;
 */
int LinkedList::getSize() const {
    return size;
}

/**
 * @notest
 */
bool LinkedList::isEmpty() const {
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
}

void LinkedList::clear() {
    throw std::runtime_error("Function not implemented");
}

void LinkedList::traverse(std::function<void(const int&)> func) const {
    throw std::runtime_error("Function not implemented");
}

