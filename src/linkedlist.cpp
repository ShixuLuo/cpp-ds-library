#include "linkedlist.h"

#include <stdexcept>
#include <iostream>

LinkNode::LinkNode(int value) : value(value), next(nullptr) {}

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    LinkNode* current = head;
    while (current != nullptr) {
        LinkNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

void LinkedList::push_front(int value) {
    LinkNode* temp = head;
    head = new LinkNode(value);
    head->next = temp;
}

int LinkedList::pop_front() {
    if (head == nullptr) {
        throw std::runtime_error("Attempt to delete an element from "
                                 "an empty linked list");
    }
    int value = head->value;
    head = head->next;
    return value;
}

void LinkedList::push_back(int value) {
    if (head == nullptr) {
        head = new LinkNode(value);
    } else {
        LinkNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new LinkNode(value);
    }
}

void LinkedList::dump() const {
    LinkNode* current = head;
    while (current != nullptr) {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}
