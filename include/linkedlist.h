#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * @file linkedlist.h
 * @brief Defines linked list and its operations.
 */

#include "abstractdatastructure.h"

#include <stdexcept>
#include <functional>

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
class LinkedList : public AbstractDataStructure {
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
         * @brief Pushes a value at the head position.
         * @param value The value to insert at head.
         */
        void push_front(int value);

        /**
         * @brief Pushes a value at the tail position.
         * @param value The value to insert at tail.
         */
        void push_back(int value);

        /**
         * @brief Pops the node at head.
         * @return The value at head.
         * @exception std::runtime_error If the linked list is empty.
         */
        int pop_front();

        /**
         * @brief Pops the node at fail.
         *
         * @return The value at tail.
         * @exception std::runtime_errow If the linked list is empty.
         */
        int pop_back();

        /**
         * @brief Inserts a value at a giving position.
         *
         * @param index The index to insert.
         * @param value The value to insert.
         * @exception std::out_of_range If the index is bigger than the size.
         */
        void insert(int index, int value) override;

        /**
         * @brief Removes a node at a giving position.
         *
         * @param index The index to remove.
         * @exception std::out_of_range If the index is bigger than the size.
         */
        void remove(int index) override;

        /**
         * @brief Finds the position of a value in the linked list.
         *
         * @param value The value to find.
         * @return Index of the value, -1 if not exist.
         */
        int find(int value) const override;

        /**
         * @brief Returns the size of this linked list.
         *
         * @return The size.
         */
        int getSize() const override;

        /**
         * @brief Checks if the linked list is empty.
         *
         * @return true if empty, else false.
         */
        bool isEmpty() const override;

        /**
         * @brief Cleans the linked list.
         */
        void clear() override;

        /**
         * @brief Traverses the linked list and applies a function to each.
         *
         * #param func A function to apply.
         */
        void traverse(std::function<void(const int&)> func) const override;

        /**
         * @brief Sets a value at a giving position.
         * 
         * @param index Index to set.
         * @param value Value to set.
         * @exception std::out_of_range If index is invalid.
         */
        void set(int index, int value);

        /**
         * @brief Gets a value at a giving position.
         *
         * @param index Index to get.
         * @return The value at the giving position.
         * @exception std::out_of_range If index is invalid.
         */
        int get(int index) const;


    private:
        int size; ///< The size of this node.
        LinkNode* head; ///< Pointer to the head node.
        
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

        /**
         * @brief Returns the node at the giving index.
         *
         * @param index Index to return, -1 implies tail.
         * @return node The node at the index.
         * @exception std::out_of_range If is out of range.
         */
        LinkNode* getNode(int index) const;

};

#endif // LINKEDLIST_H
