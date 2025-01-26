/**
 * @file stack.cpp
 * @brief Source codes for stack.h.
 */

#include <initializer_list>

#include "stack/stack_interface.h"
#include "stack/stack.h"
#include "list/list_interface.h"
#include "list/array_list.h"

Stack::Stack(ListInterface* initialData) : data(initialData) {}

Stack::Stack(std::initializer_list<int> initialData) {
    data = new ArrayList(initialData);
}

Stack::Stack() {
    data = new ArrayList(0);
}

Stack::~Stack() {
    delete data;
}

int Stack::pop() {
    return data->pop();
}

int Stack::peek() const {
    return data->peek();
}

void Stack::push(int value) {
    data->push(value);
}

void Stack::clear() {
    data->clear();
}

bool Stack::isEmpty() const {
    return data->isEmpty();
}

int Stack::getSize() const {
    return data->getSize();
}
