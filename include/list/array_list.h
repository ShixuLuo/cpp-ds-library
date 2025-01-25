#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

/**
 * @file array_list.h
 * @brief Includes the class ArrayList, a realization of list by array.
 */

#include "list/abstract_list.h"

#include <initializer_list> // For std::initializer_list

class ArrayList : public AbstractList {
    private:
        int* data; ///< Point to the data array.
        int capacity = 10; ///< Current capacity of this list.
        int extendRatio = 2; ///< Next capacity after extending.
                            
        /**
         * @brief Extends the list to extendRatio times of its capacity.
         */
        void extend() const;

    public:
        ArrayList(int size);

        ArrayList(std::initializer_list<int> initialData);

        ~ArrayList();

        int& operator[](int index) override;

        void insert(int index, int value) override;

        void remove(int index) override;

        void clear() override;

        class ListIterator : public iterator {
            private:
                int* current;

            public:
                ListIterator(int* current);
                
                int& operator*() override;

                iterator& operator++() override;

                iterator operator++(int) override;

                bool operator==(const iterator& other) const override;

                bool operator!=(const iterator& other) const override;
        };

        iterator begin() override;

        iterator end() override;
};
#endif // ARRAY_LIST_H
