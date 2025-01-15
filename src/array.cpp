#include "array.h"

#include <stdexcept>

/**
 * @brief Constructs an Array with the given size.
 * @param size The fixed size of the array.
 * @exception std::invalid_argument If size <= 0.
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
 * @brief Destructor to clean up allocated memory.
 */
Array::~Array() {
    delete[] data; // Release dynamically allocated memory
    data = nullptr; // Avoid dangling pointer
}

/**
 * @brief Sets the value at the specified index.
 * @param index The index where the value will be set.
 * @param value The value to set.
 * @exception std::out_of_range If the index is out of bounds.
 */
void Array::set(int index, int value) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    data[index] = value;
}

/**
 * @brief Gets the value at the specified index.
 * @param index The index to retrieve the value from.
 * @return The value at the specified index.
 * @exception std::out_of_range If the index is out of bounds.
 */
int Array::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

/**
 * @brief Returns the size of the array.
 * @return The fixed size of the array.
 */
int Array::getSize() const {
    return size;
}
