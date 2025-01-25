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
        const int extendRatio = 2; ///< Next capacity after extending.
                            
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

        /**
        class ListIterator : public iterator {
            public:
                int* current;

                ListIterator(int* current);
                
                int& operator*() override;

                ListIterator& operator++() override;

                ListIterator operator++(int) override;

                bool operator==(const ListIterator& other) const override;

                bool operator!=(const ListIterator& other) const override;
        };

        ListIterator begin() override;

        ListIterator end() override;
        **/
};
#endif // ARRAY_LIST_H
