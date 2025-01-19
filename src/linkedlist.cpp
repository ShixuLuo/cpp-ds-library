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
    // Operation % in C++ is not the same as (mod n).
    // It might return a negative value if the input is negative.
    // The implement of a (mod n) is as follow:
    // (a % n + n) % n;
    // This will ensure the result is positive.
    index = (index % size + size) % size;
    LinkNode* current = head;
    for (int i = 0; i<index; ++i) {
        current = current->next;
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

/**
 * @test
 * CASE 1: normal;
 * SET 5->4->3->2->1;
 * INPUT: pop_back();
 * EXPECT: 5->4->3->2;
 * EXPECT: size==4;
 *
 * CASE 2: size == 1;
 * SET 1;
 * INPUT: pop_back();
 * EXPECT: nullptr;
 * EXPECT: size==0;
 */
int LinkedList::pop_back() {
    if (isEmpty()) {
        throw std::runtime_error("Attempt to delete an element from "
                            "an empty linked list");
    }
    if (size == 1) {
        return pop_front();
    }
    LinkNode* before_tail = getNode(-2);
    LinkNode* tail = before_tail->next;
    int value = tail->value;
    before_tail->next = nullptr;
    delete tail;
    size -= 1;
    return value;
}

/**
 * @test
 * @subcase normal
 * SET 5->4->3->2->1;
 * INPUT insert(2, 42);
 * EXPECT 5->4->42->3->2->1;
 * EXPECT size == 6;
 * 
 * @subcase head
 * SET 5->4->3->2->1;
 * INPUT insert(0, 42);
 * EXPECT 42->5->4->3->2->1;
 * EXPECT size == 6;
 */
void LinkedList::insert(int index, int value) {
    ensureInRange(index);

    if (index == 0) {
        push_front(value);
    } else {
        LinkNode* node = getNode(index-1);
        LinkNode* temp = node->next;
        node->next = new LinkNode(value);
        node->next->next = temp;
        size += 1;
    }
}

/**
 * @test
 * @subcase normal
 * SET 5-4-3-2-1;
 * INPUT remove(2);
 * EXPECT 5-4-2-1;
 * EXPECT size == 4;
 *
 * @subcase head
 * SET 5-4-3-2-1;
 * INPUT remove(0);
 * EXPECT 4-3-2-1;
 * EXPECT size == 4;
 */
void LinkedList::remove(int index) {
    ensureInRange(index);

    if (index == 0) {
        pop_front();
    } else {
        LinkNode* node = getNode(index-1);
        LinkNode* temp = node->next;
        node->next = temp->next;
        delete temp;
        size -= 1;
    }
}

/**
 * @test
 * @subcase normally found
 * SET 5-4-3-2-1;
 * Input find(4);
 * Expect 1;
 *
 * @subcase not found
 * SET 5-4-3-2-1;
 * Input find(42);
 * Expect -1;
 *
 * @subcase not found in empty
 * SET 0;
 * INPUT find(5);
 * Expect -1;
 */
int LinkedList::find(int value) const {
   LinkNode* node = head;
   int index = 0;
   while (node != nullptr) {
       if (node->value == value) {
           return index;
       } else {
           node = node->next;
           index += 1;
       }
   }
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
    if (head == nullptr && size == 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * @test
 * @subcase normal clear;
 * SET 5-4-3-2-1;
 * INPUT clear();
 * EXPECT isEmpty() == true;
 * EXPECT size == 0;
 *
 * @subcase empty clear;
 * SET 0
 * INPUT clear()
 * EXPECT isEmpty() == true;
 * EXPECT size == 0;
 */
void LinkedList::clear() {
    LinkNode* current = head;
    LinkNode* temp = current;
    while (current != nullptr) {
        temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    size = 0;
}

/**
 * @test
 * @subcase sum
 * SET 5-4-3-2-1;
 * INPUT traverse(sum());
 * EXPECT 15;
 *
 * @subcase print
 * SET 5-4-3-2-1;
 * INPUT traverse(print());
 * EXPECT '5->4->3->2->1->nullptr'
 */
void LinkedList::traverse(std::function<void(const int&)> func) const {
    LinkNode* current = head;
    for (int i = 0; i < size; ++i) {
        func(current->value);
        current = current->next;
    }
}

