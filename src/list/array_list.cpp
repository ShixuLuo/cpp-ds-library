/**
 * @file array_list.h
 * @brief Implement methods of ArrayList.
 */

#include "list/array_list.h"

#include <initializer_list>
#include <stdexcept> // For std::out_of_range

ArrayList::ArrayList(int size) : AbstractList(size) {
    while (size > capacity) {
        capacity = capacity * extendRatio;
    }
    data = new int[capacity];
}

ArrayList::ArrayList(std::initializer_list<int> initialData) 
    : AbstractList(initialData.size())
{
    while (size > capacity) {
        capacity = capacity * extendRatio;
    }
    data = new int[capacity];
    int* current = data;
    for (auto& element : initialData) {
        current[0] = element;
        ++current;
    }
}

ArrayList::~ArrayList() {
    delete data;
}

void ArrayList::extend() {
    int newCapacity = capacity * extendRatio;
    int* newData = new int[newCapacity];
    for (int i = 0; i < capacity; ++i) {
        newData[i] = data[i];
    }
    delete data;
    data = newData;
    capacity = newCapacity;
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
int& ArrayList::operator[](int index) {
    ensureInRange(index);

    return data[index];
}

/**
 * @subcase const access;
 * SET const list {1, 2, 3, 4, 5}
 * INPUT list[0]
 * EXPECT 1
 */
int& ArrayList::operator[](int index) const {
    ensureInRange(index);

    return data[index];
}

/**
 * @test
 * @subcase to a normal list
 * SET list = {1, 2, 3, 4, 5}
 * INPUT list.insert(3, 42);
 * EXPECT {1, 2, 3, 42, 4, 5}
 * @subcase to an empty list
 * SET list = {}
 * INPUT list.insert(0, 42);
 * EXPECT {42}
 * @subcase to tail
 * SET list = {1, 2, 3, 4, 5}
 * INPUT insert(getSize(), 42);
 * EXPECT {1, 2, 3, 4, 5, 42}
 */
void ArrayList::insert(int index, int value) {
    size++;
    ensureInRange(index);

    if (size > capacity) {
        extend();
    }

    int temp = value;
    for (int i = size-1; i > index; --i) {
        (*this)[i] = (*this)[i-1];
    }
    (*this)[index] = value;
}

/**
 * @test
 * @subcase normal
 * SET list = {1, 2, 3, 4, 5}
 * INPUT remove(3);
 * EXPECT {1,2,3,5}
 */
void ArrayList::remove(int index) {
    ensureInRange(index);

    for (int i = index; i < size-1; ++i) {
        (*this)[i] = (*this)[i+1];
    }
    (*this)[size-1] = 0;
    size--;
}

/**
 * @test
 * @subcase normal
 * SET list = {1,2,3,4,5}
 * INPUT clear()
 * EXPECT {}
 */
void ArrayList::clear() {
    delete data;
    capacity = 10;
    size = 0;
    data = new int[capacity];
}

/**
 * @test
 * SET {1,2,3,4,5}
 * INPUT pop() x 5;
 * INPUT pop();
 * INPUT push() & peek() x 5;
 * EXPECT {1,2,3,4,5}
 */
int ArrayList::pop() {
    int value = (*this)[size-1];
    this->remove(size-1);
    return value;
}

int ArrayList::peek() const {
    return (*this)[size-1];
}

void ArrayList::push(int value) {
    this->insert(size, value);
}
