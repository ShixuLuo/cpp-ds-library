/**
 * @file linked_list.cpp
 * @brief Implement methods of ArrayList.
 */

#include "list/linked_list.h"

#include <initializer_list>
#include <stdexcept> // For std::out_of_range

LinkedList::LinkedList(int size) : AbstractList(size) {
    Node* current = nullptr;
    for (int i = size-1; i >= 0; --i) {
        current = new Node(0, current);
    }
    head = current;
}

LinkedList::LinkedList(std::initializer_list<int> initialData) 
    : AbstractList(initialData.size())
{
    Node* current = nullptr;
    for (auto it = initialData.end()-1; it >= initialData.begin(); --it) {
        current = new Node(*it, current);
    }
    
    head = current;
}

LinkedList::~LinkedList() {
    clear();
}

LinkedList::Node* LinkedList::operator()(int index) {
    ensureInRange(index);

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current;
}

LinkedList::Node* LinkedList::operator()(int index) const {
    ensureInRange(index);

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current;
}

/**
 * @test
 * @subcase access
 * SET list = {1, 2, 3, 4, 5}
 * INPUT list[0]
 * EXPECT 1
 * @subcase modify
 * SET list = {1, 2, 3, 4, 5}
 * INPUT list[0] = 42;
 * EXPECT {42, 2, 3, 4, 5}
 * @subcase out of range
 * SET list = {1, 2, 3, 4, 5}
 * INPUT list[42];
 * EXPECT std::out_of_range.
 */
int& LinkedList::operator[](int index) {
    return (*this)(index)->value;
}

/**
 * @subcase const access;
 * SET const list {1, 2, 3, 4, 5}
 * INPUT list[0]
 * EXPECT 1
 */
int& LinkedList::operator[](int index) const {
    return (*this)(index)->value;
}

/**
 * @test
 * @subcase to an empty list
 * SET list = {}
 * INPUT list.insert(0, 42);
 * EXPECT {42}
 * @subcase to head
 * SET list = {1, 2, 3, 4, 5}
 * INPUT insert(0, 42);
 * EXPECT {42, 1, 2, 3, 4, 5}
 * @subcase to tail
 * SET list = {1, 2, 3, 4, 5}
 * INPUT insert(getSize(), 42);
 * EXPECT {1, 2, 3, 4, 5, 42}
 */
void LinkedList::insert(int index, int value) {
    size++;

    if (index == 0) {
        head = new Node(value, head);
    } else {
        Node* node = (*this)(index-1);
        node->next = new Node(value, node->next);
    }
}

/**
 * @test
 * @subcase to head
 * SET list = {1, 2, 3, 4, 5}
 * INPUT remove(0);
 * EXPECT {2,3,4,5}
 * @subcase to tail
 * SET list = {1, 2, 3, 4, 5}
 * INPUT remove(4);
 * EXPECT {1,2,3,4}
 * @subcase normal
 * SET list = {1, 2, 3, 4, 5}
 * INPUT remove(2);
 * EXPECT {1,2,4,5}
 */
void LinkedList::remove(int index) {
    ensureInRange(index);

    if (index == 0) {
        head = head->next;
    } else {
        Node* node = (*this)(index-1);
        Node* temp = node->next;
        node->next = temp->next;
        delete temp;
    }

    size--;
}

/**
 * @test
 * @subcase normal
 * SET list = {1,2,3,4,5}
 * INPUT clear()
 * EXPECT {}
 */
void LinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    size = 0;
}

int LinkedList::pop() {
    int value = (*this)[0];
    remove(0);
    return value;
}

int LinkedList::peek() const {
    return (*this)[0];
}

void LinkedList::push(int value) {
    insert(0, value);
}
