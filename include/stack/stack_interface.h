#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H
/**
 * @file stack_interface.h
 * @brief Defines APIs for stacks.
 */

/**
 * @class StackInterface
 * @brief Defines APIs for stacks.
 */
class StackInterface {
    public:
        virtual ~StackInterface() = default;

        /**
         * @brief Return the stack top and remove it.
         *
         * @return The value at top.
         */
        virtual int pop() = 0;

        /**
         * @brief Return the stack top and keep it.
         *
         * @return The value at top.
         */
        virtual int peek() const = 0;

        /**
         * @brief Adds an element to the stack.
         *
         * @param value The value to push.
         */
        virtual void push(int value) = 0;

        /**
         * @brief clear the stack.
         */
        virtual void clear() = 0;

        /**
         * @brief Checks if the stack is empty.
         *
         * @return true if is, false otherwise.
         */
        virtual bool isEmpty() const = 0;

        /**
         * @brief Returns the number of elements in the stack.
         *
         * @return The number of elements.
         */
        virtual int getSize() const = 0;
};

#endif // STACK_INTERFACE_H
