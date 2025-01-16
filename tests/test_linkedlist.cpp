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

    // Test insertHead()
    // Input: 42
    // Expect: head = (42, nullptr)
    llist.insertHead(42);

    // Test deleteHead()
    // Expect: llist is empty, return 42
    assert(llist.deleteHead() == 42);

    // Test deleteHead()
    try {
        llist.deleteHead();
    } catch (const std::runtime_error& e) {
        std::cout << "Caught excepted exception: " << e.what() << std::endl;
    }

    // Test traverse()
    // Except: nullptr
    llist.traverse();

    // Test insertTail()
    // Case 1: Insert into an empty list
    // Input: 42
    // Expected: Head is a new node with value 42
    llist.insertTail(42);
    // Case 2: Insert into a nonempty list
    // Input 43
    // Expected: Tail is a new node with value 43
    llist.insertTail(43);
    llist.insertTail(44);
    llist.insertTail(45);
    llist.insertTail(46);

    // test traverse()
    // Expect: 42 -> 43 -> 44 -> 45 -> 46 -> nullptr
    llist.traverse();

    std::cout << "All tests passed!" << std::endl;
}
