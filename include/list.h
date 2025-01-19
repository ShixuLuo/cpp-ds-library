#ifndef LIST_H
#define LIST_H

/**
 * @file list.h
 * @brief An implement of lists in C++
 */

#include "abstractdatastructure.h"
#include "array.h"

#include <stdexcept>
#include <functional>

/**
 * @class AbstractList
 * @brief Base class for lists.
 */
class AbstractList : public AbstractDataStructure {
    protected:
        int capacity = 10; ///< The maximum size of this list.
        int size = 0; ///< The current size of this list.
        int extendRatio = 2; ///< The ratio of extended_capacity / current_cap.

        /**
         * @brief Checks the index is valid.
         *
         * @param index Index to compare.
         * @return true if index >=0 and < size; false else.
         */
        bool isInRange(int index) const;

        /**
         * @brief Ensures the index is in the range.
         *
         * @param index Index to check.
         * @exception std::out_of_range If the index is out of range.
         */
        void ensureInRange(int index) const;

    public:
        /**
         * @brief Destructor to clean up memory.
         */
        virtual ~AbstractList() = default;

        /**
         * @brief Sets the value at a giving index.
         * 
         * @param index The index to set.
         * @param value The value to set.
         */
        virtual void set(int index, int value) = 0;

        /**
         * @brief Gets the value at a specified index.
         *
         * @param index The index to get.
         * @exception std::out_of_range If the index exceeds the size.
         */
        virtual int get(int index) const = 0;

        /**
         * @brief Gets the current capacity of this list.
         *
         * @return Capacity of current list.
         */
        virtual int getCapacity() const = 0;

        /**
         * @brief Extend the capacity by a preset ratio.
         */
        virtual void extend() = 0;
};

/**
 * @class List
 * @brief An implement of list by array.
 */
class List : public AbstractList {
    private:
        Array* data;

    public:
        List();

        ~List();

        void set(int index, int value) override;

        int get(int index) const override;

        int getCapacity() const override;

        void extend() override;

        void insert(int index, int value) override;

        void remove(int index) override;

        int find(int value) const override;

        int getSize() const override;

        bool isEmpty() const override;

        void clear() override;

        void traverse(std::function<void(const int&)> func) const override;
};


#endif // LIST_H
