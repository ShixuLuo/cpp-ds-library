#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdexcept>
#include <string>

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

// TEST pop_back
TEST_CASE("Testing pop_back()") {
    SUBCASE("normal") {
        LinkedList llist = createTestList();
        CHECK(llist.pop_back() == 1);
        CHECK(llist.getSize() == 4);
    }
    
    SUBCASE("size == 1") {
        LinkedList llist;
        llist.push_back(1);
        CHECK(llist.pop_back() == 1);
        CHECK(llist.getSize() == 0);
        CHECK(llist.isEmpty());
    }
}

// TEST insert
TEST_CASE("Testing insert()") {
    SUBCASE("normal") {
        LinkedList llist = createTestList();
        llist.insert(2, 42);
        CHECK(llist.get(2) == 42);
        CHECK(llist.get(3) == 3);
        CHECK(llist.getSize() == 6);
    }

    SUBCASE("head") {
        LinkedList llist = createTestList();
        llist.insert(0, 42);
        CHECK(llist.get(0) == 42);
        CHECK(llist.get(1) == 5);
        CHECK(llist.getSize() == 6);
    }
}

// TEST remove
TEST_CASE("Testing remove()") {
    SUBCASE("normal") {
        LinkedList llist = createTestList();
        llist.remove(2);
        CHECK(llist.get(2) == 2);
        CHECK(llist.getSize() == 4);
    }
    SUBCASE("head") {
        LinkedList llist = createTestList();
        llist.remove(0);
        CHECK(llist.get(0) == 4);
        CHECK(llist.getSize() == 4);
    }
}

// TEST find
TEST_CASE("Testing find()") {
    SUBCASE("Normally found") {
        LinkedList llist = createTestList();
        CHECK(llist.find(4) == 1);
    }
    SUBCASE("Normally not found") {
        LinkedList llist = createTestList();
        CHECK(llist.find(42) == -1);
    }
    SUBCASE("Not found in empty") {
        LinkedList llist;
        CHECK(llist.find(42) == -1);
    }
}

// TEST clear
TEST_CASE("Testing clear()") {
    SUBCASE("Normal clear") {
        LinkedList llist = createTestList();
        llist.clear();
        CHECK("llist.isEmpty() == true");
    }
    SUBCASE("Clear empty") {
        LinkedList llist;
        llist.clear();
        CHECK("llist.isEmpty() == true");
    }
}

// TEST traverse
TEST_CASE("Testing traverse()") {
    SUBCASE("sum") {
        LinkedList llist = createTestList();
        int sum = 0;
        llist.traverse([&sum](int i) {
                sum = sum + i;
                });
        CHECK(sum == 15);
    }
    SUBCASE("print") {
        LinkedList llist = createTestList();
        std::string dump = "";
        std::string expect = "5->4->3->2->1->nullptr";
        llist.traverse([&dump](int i) {
                std::string i_s = std::to_string(i);
                dump = dump + i_s + "->";
                });
        dump += "nullptr";
        CHECK(dump == expect);
    }
}
