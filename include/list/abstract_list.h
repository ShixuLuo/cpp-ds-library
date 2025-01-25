#ifndef ABSTRACT_LIST_H
#define ABSTRACT_LIST_H

/**
 * @file abstract_list.h
 * @brief An abstract list implementation.
 */

#include <stdexcept>

#include "list_interface.h"

/**
 * @class AbstractList
 * @brief An implement of abstract lists.
 */
class AbstractList : public ListInterface {
    protected:
        int size; ///< The size of the list.
        
        /**
         * @brief Checks the index is a valid argument.
         * @param index The index to check size.
         * @return true if index >=0 and < size. false otherwise.
         */
        bool isInRange(int index) const { 
            return (index >= 0 && index < size); 
        };

        /**
         * @brief Ensures the index is in range.
         * @param index The index to check.
         * @exception std::out_of_range If the index is not in range.
         */
        void ensureInRange(int index) const {
            if (!isInRange(index)) {
                throw std::out_of_range("The index is out of bound");
            }
        }

    public:
        AbstractList(int size) : size(size) {};

        int find(int value) const override {
            for (int i = 0; i < size; ++i) {
                if (value == operator[](i)) {
                    return i;
                }
            }
            return -1;
        }

        int getSize() const override { return size; }

        bool isEmpty() const override { return (size == 0); }
};

#endif // ABSTRACT_LIST_H
