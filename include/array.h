#ifndef ARRAY_H // Ensure this header is compiled exactly once
#define ARRAY_H

/**
 * @file array.h
 * @brief Defines the Array class and its operations.
 */

#include <stdexcept> // For exception handling

/**
 * @class Array
 * @brief An array implementation in C++.
 */
class Array {
    public: 
        /**
         * @brief Construct a array with the given size.
         * @param size The fixed size of the array.
         */
        Array(int size);

        /**
         * @brief Destructor to clean up allocated memory.
         */
        ~Array();

        /**
         * @brief Sets the value at the specified index
         * @param index The index where the value will be set.
         * @param value The value to set.
         * @exception std::out_of_range If the index is out of bounds.
         */
        void set(int index, int value);

        /**
         * @brief Gets the value at the specified index.
         * @param index The index to retrieve the value from.
         * @return The value at the specified index.
         * @exception std::out_of_range If the index is out of bounds.
         */
        int get(int index) const;

        /**
         * @brief Returns the size of the array.
         * @return The fixed size of the array.
         */
        int getSize() const;

    private:
        int* data; ///< Pointer to the array data.
        int size; ///< Fixed size of the array.
};

#endif // ARRAY_H
