#include "array.h"
#include <iostream>
#include <cassert>

int main() {
    // Test constructor
    Array arr(5);
    assert(arr.getSize() == 5);

    // Test set and get
    arr.set(0, 42);
    assert(arr.get(0) == 42);

    // Output for debugging
    std::cout << "Array[0]: " << arr.get(0) << std::endl;

    // Test out-of-range access
    try {
        arr.set(-1, 10);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught excepted exception: " << e.what() << std::endl;
    }

    try {
        int value = arr.get(5);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
