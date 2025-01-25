#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdexcept>
#include <string>

#include "list.h"

List createTestList() {
    List list;
    for (int i = 0; i < 5; ++i) {
        list.set(i, i+1);
    }
    return list;
}

// Test constructor
TEST_CASE("Testing constructor") {
    List list = createTestList();
    CHECK(list.get(0) == 1);
    CHECK(list.getCapacity() == 10);
}

// Test set
TEST_CASE("Testing set()") {
    SUBCASE("set without extension") {
        List list = createTestList();
        CHECK(list.getSize() == 5);
    }
    
    SUBCASE("set with extension") {
        List list = createTestList();
        list.set(5, 42);
        CHECK(list.get(5) == 42);
    }

    SUBCASE("set at max capacity") {
        List list = createTestList();
        list.set(9, 42);
        CHECK(list.get(9) == 42);
        CHECK(list.getSize() == 10);
        CHECK(list.getCapacity() == 10);
    }
}

// Test extend
TEST_CASE("Testing extend()") {
    List list = createTestList();
    list.extend();
    CHECK(list.get(4) == 5);
    CHECK(list.getSize() == 5);
    CHECK(list.getCapacity() == 20);
}

// Test insert
TEST_CASE("Testing insert()") {
    SUBCASE("insert without extension") {
        List list = createTestList();
        list.insert(3,42);
        CHECK(list.get(3) == 42);
        CHECK(list.get(4) == 4);
        CHECK(list.getSize() == 6);
    }

    SUBCASE("insert with extension") {
        List list = createTestList();
        list.set(9, 10);
        list.insert(3, 42);
        CHECK(list.get(3) == 42);
        CHECK(list.get(4) == 4);
        CHECK(list.get(10) == 10);
        CHECK(list.getSize() == 11);
    }
}

// Test remove
TEST_CASE("Testing remove()") {
    List list = createTestList();
    list.remove(2);
    CHECK(list.get(2) == 4);
    CHECK(list.getSize() == 4);
}

// Integrated test
TEST_CASE("Integrated test") {
    List list = createTestList();
    CHECK(list.find(3) == 2);
    CHECK(list.isEmpty() == false);
    list.clear();
    CHECK(list.isEmpty() == true);
    CHECK(list.getSize() == 0);
    list.set(0, 100);
    for (int i=99; i>0; --i) {
        list.insert(0, i);
    }
    CHECK(list.getSize() == 100);
    
    std::string expect = "";
    for (int i=0; i<100; i++) {
        expect += std::to_string(i+1) + " ";
    }

    std::string dump = "";
    list.traverse([&dump](int j) {
            dump += std::to_string(j) + " ";
            });
    CHECK(dump == expect);
}
