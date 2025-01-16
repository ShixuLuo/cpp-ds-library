#ifndef ARRAY_H // Ensure this header is compiled exactly once
#define ARRAY_H

/**
 * @file array.h
 * @brief Defines the Array class and its operations.
 */

#include "abstractdatastructure.h"
#include <stdexcept> // For exception handling
#include <functional> // For std::function

/**
 * @class Array
 * @brief An array implementation in C++.
 */
class Array : public AbstractDataStructure {
    public: 
        /**
         * @brief Construct a array with the given size.
         * @param size The fixed size of the array.
         * @exception std::invalid_argument If size <= 0.
         */
        Array(int size);

        /**
         * @brief Destructor to release memory.
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
         * @brief Inserts a value at a specified position.
         * @details Value at the tail will be dropped.
         * 
         * @param index The index to insert.
         * @param value The value to set.
         */
        void insert(int index, int value) override;

        /**
         * @brief Removes an entry at a given index.
         * @details All elements after the given position will be shifted
         * one position to the left.
         *
         * @param index The index to remove.
         */
        void remove(int index) override;

        /**
         * @brief Finds the first occurence of a given value.
         *
         * @param value The value to be found.
         * @return The index of the given value, -1 if doesn't exist.
         */
        int find(int value) const override;

        /**
         * @brief Gets the size of this array.
         *
         * @return The size of the array.
         */
        int getSize() const override;

        /**
         * @brief Checks if this array is empty.
         *
         * @return true if is empty, else false.
         */
        bool isEmpty() const override;

        /**
         * @brief Sets all entries to 0.
         */
        void clear() override;

        /**
         * @brief Traverses the whole array with a given function.
         *
         * @param func The function to apply.
         */
        void traverse(std::function<void(const int&)> func) const override;

    private:
        int* data; ///< Pointer to the array data.
        int size; ///< Size of the array.

        /**
         * @brief Checks if the index is valid.
         *
         * @param index Index to check.
         * @return true if is valid, else false
         */
        bool isInRange(int index) const;

        /**
         * @brief Ensures the index is in range.
         *
         * @param index Index to check.
         * @exception: std::out_of_range If is out of range.
         */
        void ensureInRange(int index) const;
};

#endif // ARRAY_H
