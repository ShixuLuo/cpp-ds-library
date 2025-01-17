#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdexcept>
#include <string> // For test traverse

#include "array.h"

// TEST constructor
TEST_CASE("Testing array constructor") {
    SUBCASE("Normal") {
        Array arr(5);
        CHECK(arr.getSize() == 5);
        for (int i = 0; i < arr.getSize(); ++i) {
            CHECK(arr.get(i) == 0);
        }
    }

    SUBCASE("Exception: size = -1") {
        CHECK_THROWS_AS(Array(-1), std::invalid_argument);
    }
}

// TEST set
TEST_CASE("Testing array.set()") {
    SUBCASE("Normal") {
        Array arr(5);
        arr.set(3, 5);
        CHECK(arr.get(3) == 5);
    }

    SUBCASE("Exception: index = -1") {
        Array arr(5);
        CHECK_THROWS_AS(arr.set(-1, 5), std::out_of_range);
    }
}

// TEST get
TEST_CASE("Testing array.get()") {
    SUBCASE("Normal") {
        Array arr(5);
        arr.set(3, 5);
        CHECK(arr.get(3) == 5);
    }

    SUBCASE("Exception: index = -1") {
        Array arr(5);
        CHECK_THROWS_AS(arr.get(-1), std::out_of_range);
    }
}

// TEST getSize
TEST_CASE("Testing getSize()") {
    Array arr(5);
    CHECK(arr.getSize() == 5);
}
// TEST insert
Array createTestArray() {
    Array arr(5);
    for (int i = 0; i < 5; ++i) {
        arr.set(i, i+1);
    }
    return arr;
}

TEST_CASE("Testing insert()") {
    SUBCASE("Insert head") {
        Array arr = createTestArray();
        arr.insert(0, 42);
        CHECK(arr.get(0) == 42);
        CHECK(arr.get(4) == 4);
    }
    
    SUBCASE("Insert middle") {
        Array arr = createTestArray();
        arr.insert(2, 42);
        CHECK(arr.get(2) == 42);
        CHECK(arr.get(4) == 4);
    }

    SUBCASE("Insert tail") {
        Array arr = createTestArray();
        arr.insert(4, 42);
        CHECK(arr.get(4) == 42);
    }
}

// TEST remove
TEST_CASE("Testing remove()") {
    Array arr = createTestArray();
    arr.remove(2);
    for (int i = 0; i < 5; ++i) {
        if (i < 2) {
            CHECK(arr.get(i) == i+1);
        } else if (i < 4) {
            CHECK(arr.get(i) == i+2);
        } else {
            CHECK(arr.get(i) == 0);
        }
    }
}

// TEST traverse
TEST_CASE("Testing traverse()") {
    SUBCASE("Sum of elements") {
        Array arr = createTestArray();
        int sum = 0;
        arr.traverse([&sum](int i) {
            sum = sum + i;
        });
        CHECK(sum == 15);
    }

    SUBCASE("Print to string") {
        Array arr = createTestArray();
        std::string dump = "";
        std::string expect = "1 2 3 4 5 ";
        arr.traverse([&dump](int i) {
            std::string i_s = std::to_string(i);
            dump = dump + i_s + " ";
        });
        CHECK(dump == expect);
    }
}

// TEST find
TEST_CASE("Testing find()") {
    SUBCASE("Found") {
        Array arr = createTestArray();
        CHECK(arr.find(2) == 1);
    }

    SUBCASE("Not found") {
        Array arr = createTestArray();
        CHECK(arr.find(42) == -1);
    }
}
        
// TEST isEmpty
TEST_CASE("Testing isEmpty()") {
    SUBCASE("Empty") {
        Array arr(5);
        CHECK(arr.isEmpty() == true);
    }

    SUBCASE("Not empty") {
        Array arr = createTestArray();
        CHECK(arr.isEmpty() == false);
    }
}

// TEST clear
TEST_CASE("Testing clear()") {
    Array arr = createTestArray();
    arr.clear();
    CHECK(arr.isEmpty() == true);
}
