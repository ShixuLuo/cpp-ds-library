/**
 * @file test_array_list.cpp
 * @brief Unit tests of class ArrayList.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "list/list_interface.h"
#include "list/array_list.h"

ListInterface* createTestList() {
    ListInterface* list = new ArrayList({1, 2, 3, 4, 5});
    return list;
}

/**
 * @brief Tests constructor and destructor.
 */
TEST_CASE("Constructor and destructor") { 
    ListInterface* emptyList = new ArrayList(5);
    CHECK(emptyList->getSize() == 5);
    ListInterface* list = createTestList();
    CHECK(list->getSize() == 5);
}

/**
 * @brief Test operator[].
 */
TEST_CASE("Operator[]") {
    SUBCASE("Access") {
        ListInterface* list = createTestList();
        CHECK((*list)[0] == 1);
    }
    SUBCASE("Modify") {
        ListInterface* list = createTestList();
        (*list)[0] = 42;
        CHECK((*list)[0] == 42);
    }
    SUBCASE("Out of range") {
        ListInterface* list = createTestList();
        CHECK_THROWS_AS((*list)[42], std::out_of_range);
    }
    SUBCASE("Const access") {
        const ListInterface* list = new const ArrayList({1, 2, 3, 4, 5});
        CHECK((*list)[0] == 1);
    }
}

/**
 * @brief Test insert.
 */
TEST_CASE("insert()") {
    SUBCASE("to an empty list") {
        ListInterface* list = new ArrayList(0);
        list->insert(0, 42);
        CHECK((*list)[0] == 42);
    }
    SUBCASE("to a normal list") {
        ListInterface* list = createTestList();
        list->insert(3, 42);
        CHECK((*list)[3] == 42);
        CHECK((*list)[4] == 4);
        CHECK(list->getSize() == 6);
    }
    SUBCASE("to the tail") {
        ListInterface* list = createTestList();
        list->insert(list->getSize(), 42);
        CHECK((*list)[5] == 42);
    }
}

/**
 * @brief Tests remove().
 */
TEST_CASE("remove()") {
    ListInterface* list = createTestList();
    list->remove(3);
    CHECK((*list)[3] == 5);
    CHECK(list->getSize() == 4);
}

/**
 * @brief Tests clear().
 */
TEST_CASE("clear()") {
    ListInterface* list = createTestList();
    list->clear();
    CHECK(list->isEmpty() == true);
}
