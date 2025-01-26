#ifndef STACK_H
#define STACK_H

/**
 * @file stack.h
 * @brief Implement of the stack.
 */

#include <initializer_list>

#include "stack/stack_interface.h"
#include "list/list_interface.h"

class Stack : public StackInterface {
    private:
        ListInterface* data; ///< The data of the stack.

    public:
        Stack(ListInterface* initialData);

        Stack(std::initializer_list<int> initialData);

        Stack();

        ~Stack();

        int pop() override;

        int peek() const override;

        void push(int value) override;

        void clear() override;

        bool isEmpty() const override;

        int getSize() const override;
};      

#endif // STACK_H
