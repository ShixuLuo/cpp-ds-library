/**
 * @brief Source code for list.h.
 */

#include "list.h"
#include "array.h"

#include <stdexcept>
#include <functional>

// AbstractList
bool AbstractList::isInRange(int index) const {
    return (index >= 0 && index < size);
}

void AbstractList::ensureInRange(int index) const {
    if (!isInRange(index)) {
        throw std::out_of_range("");
    }
}

// List
/**
 * @test
 * @subcase normal
 * SET 1,2,3,4,5
 */
List::List() {
    data = new Array(capacity);
}

/**
 * @notest
 */
List::~List() {
    delete data;
}

/**
 * @notest
 */
int List::getCapacity() const {
    return capacity;
}

/**
 * @test
 * @subcase normal extend
 * SET 1,2,3,4,5
 * INPUT extend()
 * EXPECT 1,2,3,4,5
 * EXPECT getCapacity() = 20;
 */
void List::extend() {
    int newCapacity = getCapacity() * extendRatio;
    Array* newData = new Array(newCapacity);
    for (int i = 0; i < size; ++i) {
        newData->set(i, data->get(i));
    }
    delete data;
    data = newData;
    capacity = newCapacity;
}   

/**
 * @test
 * @subcase set without extension
 * SET 1,2,3,4,5;
 * EXPECT size == 5;
 *
 * @subcase set with extension
 * SET 1,2,3,4,5;
 * INPUT set(5, 42);
 * EXPECT size == 6;
 *
 * @subcase set at max capacity
 * SET 1,2,3,4,5
 * INPUT set(9, 42);
 * EXPECT 1,2,3,4,5,0,0,0,0,42;
 * EXPECT size == 10;
 * EXPECT capacity == 10;
 */
void List::set(int index, int value) {
    if (index < 0) {
        throw std::out_of_range("");
    }

    if (index+1 > size) {
        size = index+1;
    }

    if (size > capacity) {
        extend();
    } else {
        data->set(index, value);
    }
}

/**
 * @notest
 */
int List::get(int index) const {
    ensureInRange(index);

    return data->get(index);
}

/**
 * @test
 * @subcase insert without extension
 * SET 1,2,3,4,5
 * INPUT insert(3, 42);
 * EXPECT 1,2,3,42,4,5;
 * EXPECT size == 6;
 *
 * @subcase insert with extension
 * SET 1,2,3,4,5,0,0,0,0,10;
 * INPUT insert(3, 42);
 * EXPECT 1,2,3,42,4,5,0,0,0,0,10;
 * EXPECT size == 11;
 */
void List::insert(int index, int value) {
    ensureInRange(index);
    
    if (size+1 > getCapacity()) {
        extend();
    }

    size = size + 1;
    data->insert(index, value);
}

/**
 * @test
 * @subcase
 * SET 1,2,3,4,5
 * INPUT remove(2);
 * EXPECT 1,2,4,5
 * EXPECT size == 4;
 */
void List::remove(int index) {
    ensureInRange(index);

    data->remove(index);
    size = size - 1;
}

/**
 * @notest
 */
int List::find(int value) const {
    return data->find(value);
}

/**
 * @notest
 */
int List::getSize() const {
    return size;
}

/**
 * @notest
 */
bool List::isEmpty() const {
    return data->isEmpty();
}

/**
 * @notest
 */
void List::clear() {
    data->clear();
    size = 0;
}

/**
 * @notest
 */
void List::traverse(std::function<void(const int&)> func) const {
    for (int i = 0; i < size; ++i) {
        func(get(i));
    }
}
