#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H

/**
 * @file ListInterface.h
 * @brief An interface for lists.
 */

/**
 * @class ListInterface
 * @brief Defines common operations for a list.
 */
class ListInterface {
    public:
        virtual ~ListInterface() = default;

        /**
         * @brief Permits to use [] to set and get a value.
         * 
         * @param index The index to access.
         * @return The reference of the value at the index.
         */
        virtual int& operator[](int index) = 0;

        /**
         * @brief Const version of operation[].
         */
        virtual const int& operator[](int index) const = 0;

        
        // /**
        //  * @class iterator
        //  * @brief Defines an iterator for lists.
        //  */
        // class iterator {
        //     public:
        //         virtual ~iterator() = default;

        //         /**
        //          * @brief Defines operation *.
        //          * @return The reference of value at list[i].
        //          */
        //         virtual int& operator*() = 0;

        //         /**
        //          * @brief Defines ++i.
        //          */
        //         virtual iterator& operator++() = 0;

        //         /**
        //          * @brief Defines i++.
        //          */
        //         virtual iterator operator++(int) = 0;

        //         /**
        //          * @brief Permits to compare two iterators.
        //          */
        //         virtual bool operator==(const iterator& other) const = 0;

        //         /**
        //          * @brief Permits to compare two iterators.
        //          */
        //         virtual bool operator!=(const iterator& other) const = 0;
        // };

        // /**
        //  * @brief begin() for iterator.
        //  */
        // virtual iterator begin() = 0;
        // 
        // /**
        //  * @brief end() for iterator.
        //  */
        // virtual iterator end() = 0;

         /**
         * @brief Inserts a value at a given position.
         *
         * @param index The index to insert.
         * @param value The value to set.
         */
        virtual void insert(int index, int value) = 0;

        /**
         * @brief Removes the node at a given index.
         *
         * @param index The index to remove.
         */
        virtual void remove(int index) = 0;

        /**
         * @brief Finds a giving value in the list.
         *
         * @param value The value to find.
         * @return The index of this value. -1 if not found.
         */
        virtual int find(int value) const = 0;

        /**
         * @brief Returns the size of this list.
         *
         * @return The size of this list.
         */
        virtual int getSize() const = 0;

        /**
         * @brief Checks if this list is empty.
         *
         * @return true if empty; false if not.
         */
        virtual bool isEmpty() const = 0;

        /**
         * @brief Clears the list.
         */
        virtual void clear() = 0;

        /**
         * @brief Returns the top element and deletes it.
         *
         * @return The value at the top.
         */
        virtual int pop() = 0;

        /**
         * @brief Adds a new element to the stack.
         */
        virtual void push(int value) = 0;

        /**
         * @brief Return the top element but keep it.
         *
         * @return The value at the top.
         */
        virtual int peek() const = 0;
        
};

#endif // LIST_INTERFACE_H
