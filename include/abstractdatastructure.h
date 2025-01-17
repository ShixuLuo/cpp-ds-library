#ifndef ABSTRACT_DATASTRUCTURE_H
#define ABSTRACT_DATASTRUCTURE_H

/**
 * @file abstractdatastructure.h
 * @brief An abstract class of all data structures.
 * @details Includes basic methods:
 * insert, remove, find,
 * size, isEmpty,
 * clear, traverse
 */

#include <functional> // For std::function

/**
 * @class AbstractDataStructure
 * @brief An abstract data structure containing basic operations.
 */
class AbstractDataStructure {
    public:
        /**
         * @brief Destructor to clean up memory
         */
        virtual ~AbstractDataStructure() = default;

        /**
         * @brief Inserts a value to a giving index.
         *
         * @param index The index to insert.
         * @param value The value to set.
         */
        virtual void insert(int index, int value) = 0;

        /**
         * @brief Removes a value at a giving index.
         *
         * @param index The index to remove.
         */
        virtual void remove(int index) = 0;

        /**
         * @brief Finds a giving value in this structure.
         *
         * @param value The value to be found.
         * @return The index of the value. If not exist, return -1.
         */
        virtual int find(int value) const = 0;

        /**
         * @brief Gets the size of this structure.
         *
         * @return The size.
         */
        virtual int getSize() const = 0;
        
        /**
         * @brief Checks if the structure is empty.
         *
         * @return True if it is empty, else False.
         */
        virtual bool isEmpty() const = 0;

        /**
         * @brief Clean the data structure to empty.  
         */
        virtual void clear() = 0;

        /**
         * @brief Traverses the data structure and applies a function to each.
         *
         * @param func The function to apply.
         */
        virtual void traverse(std::function<void(const int&)> func) const = 0;
};

#endif // ABSTRACT_DATASTRUCTURE_H
