#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * @file linkedlist.h
 * @brief Defines linked list and its operations.
 */

#include <stdexcept>

/**
 * @struct LinkNode
 * @brief A node containing a value and next position.
 * @var value The data to save.
 * @var next A pointer of next node, default as nullptr.
 */
struct LinkNode {
    int value; ///< The value of this node.
    LinkNode* next; ///< The address of next node.

    /**
     * @brief Construct a node with giving value and pointing to nullptr.
     * @param value The value to set.
     */
    LinkNode(int value);
};

/**
 * @class LinkedList
 * @brief A linked list implementation in C++.
 */
class LinkedList {
    public:
        /**
         * @brief Construct an empty linked list with head pointing to nullptr.
         */
        LinkedList();

        /**
         * @brief Destructor to clean up
         */
        ~LinkedList();

        /**
         * @brief Insert a value at the head position.
         * @param value The value to insert at head.
         */
        void insertHead(int value);

        /**
         * @brief Insert a value at the tail position.
         * @param value The value to insert at tail.
         */
        void insertTail(int value);

        /**
         * @brief Delete the node at head.
         * @return The value at head.
         * @exception std::runtime_error If the linked list is empty.
         */
        int deleteHead();

        /**
         * @brief Traverse the whole linked node and print out.
         */
        void traverse() const;

    private:
        LinkNode* head; ///< Pointer to the head node.
};

#endif // LINKEDLIST_H
