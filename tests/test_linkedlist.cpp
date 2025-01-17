#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdexcept>

#include "linkedlist.h"

// TEST constructor
TEST_CASE("Testing constructor") {
    LinkedList llist;
}

LinkedList createTestList() {
    LinkedList llist;
    for (int i = 0; i < 5; i++) {
        llist.push_front(i+1);
    }
    return llist;
}

// TEST get
TEST_CASE("Testing get()") {
    SUBCASE("normal") {
        LinkedList llist = createTestList();
        CHECK(llist.get(2) == 3);
    }
    SUBCASE("exception") {
        LinkedList llist;
        CHECK_THROWS_AS(llist.get(-1), std::out_of_range);
    }
}

// TEST set
TEST_CASE("Testing set()") {
    LinkedList llist = createTestList();
    llist.set(2, 42);
    CHECK(llist.get(2) == 42);
}

// TEST pop_front
TEST_CASE("Testing pop_front()") {
    SUBCASE("normal") {
        LinkedList llist = createTestList();
        CHECK(llist.pop_front() == 5);
        CHECK(llist.getSize() == 4);
    }
    
    SUBCASE("exception") {
        LinkedList llist;
        CHECK_THROWS_AS(llist.pop_front(), std::runtime_error);
    }
}

// TEST push_back
TEST_CASE("Testing push_back()") {
    LinkedList llist = createTestList();
    llist.push_back(42);
    CHECK(llist.get(5) == 42);
    CHECK(llist.getSize() == 6);
}
