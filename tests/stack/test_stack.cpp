/**
 * @file test_stack.cpp
 * @brief Test code for stack.h
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "stack/stack_interface.h"
#include "stack/stack.h"
#include "list.h"

/**
 * @brief Tests constructor and destructor.
 */
TEST_CASE("Constructor and destructor") {
    SUBCASE("arraylist") {
        Stack s({1,2,3,4,5});
    }
    SUBCASE("linkedlist") {
        ListInterface* data = new LinkedList({1,2,3,4,5});
        Stack s(data);
    }
}

/**
 * @brief Integrated test.
 */
TEST_CASE("integrated test") {
    SUBCASE("arraylist") {
        ListInterface* data = new ArrayList({1,2,3,4,5});
        StackInterface* stack = new Stack(data);
        stack->push(6);
        CHECK(stack->getSize() == 6);
        CHECK(stack->pop() == 6);
        CHECK(stack->peek() == 5);
        stack->clear();
        CHECK(stack->isEmpty() == true);
    }
    SUBCASE("linked list") {
        ListInterface* data = new LinkedList({5,4,3,2,1});
        StackInterface* stack = new Stack(data);
        stack->push(6);
        CHECK(stack->getSize() == 6);
        CHECK(stack->pop() == 6);
        CHECK(stack->peek() == 5);
        stack->clear();
        CHECK(stack->isEmpty() == true);
    }
    SUBCASE("empty") {
        StackInterface* stack = new Stack;
        stack->push(6);
        CHECK(stack->getSize() == 1);
        CHECK(stack->peek() == 6);
        CHECK(stack->pop() == 6);
        stack->clear();
        CHECK(stack->isEmpty() == true);
    }
}
