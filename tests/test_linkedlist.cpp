#include "linkedlist.h"

#include <stdexcept>
#include <iostream>
#include <cassert>

int main() {
    // Test LinkNode constructor
    // Expect: Node creates with value 5
    LinkNode node(5);
    assert(node.value == 5);

    // Test LinkedList constructor
    // Expect: LinkedList creates
    LinkedList llist;

    // Test push_front()
    // Input: 42
    // Expect: head = (42, nullptr)
    llist.push_front(42);

    // Test pop_front()
    // Expect: llist is empty, return 42
    assert(llist.pop_front() == 42);

    // Test pop_front()
    try {
        llist.pop_front();
    } catch (const std::runtime_error& e) {
        std::cout << "Caught excepted exception: " << e.what() << std::endl;
    }

    // Test dump()
    // Except: nullptr
    llist.dump();

    // Test push_back()
    // Case 1: Insert into an empty list
    // Input: 42
    // Expected: Head is a new node with value 42
    llist.push_back(42);
    // Case 2: Insert into a nonempty list
    // Input 43
    // Expected: Tail is a new node with value 43
    llist.push_back(43);
    llist.push_back(44);
    llist.push_back(45);
    llist.push_back(46);

    // test dump()
    // Expect: 42 -> 43 -> 44 -> 45 -> 46 -> nullptr
    llist.dump();

    std::cout << "All tests passed!" << std::endl;
}
