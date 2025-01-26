#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
 * @file linked_list.h
 * @brief Includes the class LinkedList, a realization of list by nodes.
 */

#include "list/abstract_list.h"

#include <initializer_list> // For std::initializer_list

class LinkedList : public AbstractList {
    private:
        /**
         * @struct Node
         * @brief Defines a node of the linked list.
         */
        struct Node {
            int value; ///< The value of this node.
            Node* next; ///< The address of next node.

            /**
             * @brief Construct a node based on a given value.
             */
            Node(int value): value(value), next(nullptr) {};

            /**
             * @brief Construct a node based on a value and the next node.
             */
            Node(int value, Node* next): value(value), next(next) {};
        };

        Node* head;

        /**
         * @brief Returns the node at the position.
         * @details Usage: a(2);
         * 
         * @param index The index to access.
         * @return The node at the given position.
         */
        Node* operator()(int index);

        Node* operator()(int index) const;

    public:
        LinkedList(int size);

        LinkedList(std::initializer_list<int> initialData);

        ~LinkedList();

        int& operator[](int index) override;

        int& operator[](int index) const override;

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

        int pop() override;

        int peek() const override;
        
        void push(int value) override;
};
#endif // LINKED_LIST_H
