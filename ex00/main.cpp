#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

void testWithVector() {
    std::cout << "Testing with std::vector:" << std::endl;
    std::vector<int> vec = {10, 20, 30, 40, 50};

    try {
        std::cout << "Searching for 30..." << std::endl;
        auto it = easyfind(vec, 30);
        std::cout << "Found: " << *it << std::endl;

        std::cout << "Searching for 60..." << std::endl;
        it = easyfind(vec, 60); // This will throw an exception
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testWithList() {
    std::cout << "Testing with std::list:" << std::endl;
    std::list<int> lst = {100, 200, 300, 400};

    try {
        std::cout << "Searching for 200..." << std::endl;
        auto it = easyfind(lst, 200);
        std::cout << "Found: " << *it << std::endl;

        std::cout << "Searching for 500..." << std::endl;
        it = easyfind(lst, 500); // This will throw an exception
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testWithDeque() {
    std::cout << "Testing with std::deque:" << std::endl;
    std::deque<int> deq = {5, 15, 25, 35};

    try {
        std::cout << "Searching for 15..." << std::endl;
        auto it = easyfind(deq, 15);
        std::cout << "Found: " << *it << std::endl;

        std::cout << "Searching for 100..." << std::endl;
        it = easyfind(deq, 100); // This will throw an exception
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    testWithVector();
    std::cout << std::endl;

    testWithList();
    std::cout << std::endl;

    testWithDeque();
    return 0;
}
