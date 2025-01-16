#include "array.h"

#include <stdexcept>
#include <functional>

/**
 * @test
 * Case 1: normal.
 *   Input: Array arr[5];
 *   Expect: [0, 0, 0, 0, 0].
 * Case 2(exception): size = -1. 
 *   Input: Array arr[-1];
 *   Expect: catch std::invalid_argument.
 */
Array::Array(int size): size(size) {
    if (size <= 0) {
        throw std::invalid_argument("Size must be greater than 0");
    }
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = 0; // Initialize all elements to 0
    }
}

/**
 * @notest
 */
Array::~Array() {
    delete[] data; // Release dynamically allocated memory
    data = nullptr; // Avoid dangling pointer
}

// Private methods

bool Array::isInRange(int index) const {
    return index >= 0 && index < size;
}

void Array::ensureInRange(int index) const {
    if (!isInRange(index)) {
        throw std::out_of_range("Index out of bounds");
    }
}

// Public methods

/**
 * @test
 * Case 1: 
 *   Input: arr.set(3, 5);
 *   Expect: [0, 0, 0, 5, 0]
 * Case 2(exception): out of range
 *   Input: arr.set(-1, 5);
 *   Expect: catch std::out_of_range
 */
void Array::set(int index, int value) {
    ensureInRange(index);
    data[index] = value;
}

/**
 * @test
 * Case 1: (after set()/test/case-1)
 *   Input: arr.get(3);
 *   Expect: 5
 * Case 2(exception): out of range
 *   Input: arr.get(-1);
 *   Expect: catch std::out_of_range
 */
int Array::get(int index) const {
    ensureInRange(index);
    return data[index];
}

/**
 * @test
 * Case 1:
 *   Input: arr.getSize()
 *   Expect: 5
 */
int Array::getSize() const {
    return size;
}

/**
 * @test
 * SET arr = [1, 2, 3, 4, 5]
 *
 * Case 1: Insert head
 * Input: arr.insert(0, 42);
 * Expect: [42, 1, 2, 3, 4].
 *
 * Case 2: Insert middle
 * Input: arr.insert(2, 42);
 * Expect: [1, 2, 42, 3, 4]
 *
 * Case 3: Insert tail
 * Input: arr.insert(4, 42);
 * Expect: [1, 2, 3, 4, 42]
 */
void Array::insert(int index, int value) {
    ensureInRange(index);

    int temp = get(index);
    int temp2 = 0;
    set(index, value);
    for (int i = index+1; i < size; ++i) {
        temp2 = get(i);
        set(i, temp);
        temp = temp2;
    }
}

/**
 * @test
 * SET arr = [1, 2, 3, 4, 5]
 *
 * Case 1: Normal
 * Input: arr.remove(2);
 * Expect: [1, 2, 4, 5, 0]
 */
void Array::remove(int index) {
    ensureInRange(index);

    int temp = 0;
    int temp2 = 0;
    for (int i = size-1; i >= index; --i) {
        temp2 = get(i);
        set(i, temp);
        temp = temp2;
    }
}

/**
 * @test
 * SET arr = [1, 2, 3, 4, 5]
 *
 * Case 1: found
 * Input: arr.find(2);
 * Expect: 1;
 *
 * Case 2: Not found
 * Input: arr.find(42);
 * Expect: -1;
 */
int Array::find(int value) const {
    for (int i=0; i < size; ++i) {
        if (get(i) == value) {
            return i;
        }
    }
    return -1;
}

/**
 * @test
 * 
 * Case 1: not empty
 * Input: [1, 2, 3, 4, 5].isEmpty();
 * Expect: false;
 *
 * Case 2: empty
 * Input: [0, 0, 0, 0, 0].isEmpty();
 * Expect: true;
 */
bool Array::isEmpty() const {
    for (int i = 0; i < size; ++i) {
        if (get(i) != 0) {
            return false;
        }
    }
    return true;
}

/**
 * @test
 * SET arr = [1, 2, 3, 4, 5]
 * 
 * Case: 
 * Input: arr.clear();
 * Expect: [0, 0, 0, 0, 0]
 */
void Array::clear() {
    for (int i = 0; i < size; ++i) {
        set(i, 0);
    }
}

/**
 * @test
 * SET arr = [1, 2, 3, 4, 5]
 *
 * Case 1: sum of elements
 * Input:
 * arr.traverse([&sum](int i)  {
 *      sum = sum + i;
 * })
 * Expect: 15
 *
 * Case 2: print to string
 * Input:
 * arr.traverse([&dump](int i) {
 *      std::string i_s = std::to_string(i);
 *      dump = dump + i_s + " ";
 * }
 * Expect: "1 2 3 4 5 "
 */
void Array::traverse(std::function<void(const int&)> func) const {
    for (int i = 0; i < size; ++i) {
        func(get(i));
    }
}
