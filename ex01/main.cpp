#include "Span.hpp"
#include <iostream>
#include <vector>

// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }


//MORE TESTS
int main() {
    try {
        // Create a Span with a maximum size of 10
        Span sp(10);

        // Test single number addition
        std::cout << "Adding single numbers:\n";
        sp.addNumber(5);
        sp.addNumber(10);
        sp.addNumber(15);
        sp.printContents();

        // Test adding a range of numbers
        std::cout << "\nAdding a range of numbers:\n";
        std::vector<int> rangeToAdd = {20, 25, 30, 35, 40};
        sp.addNumbers(rangeToAdd.begin(), rangeToAdd.end());
        sp.printContents();

        // Test edge case: Adding a range that would exceed capacity
        std::cout << "\nAttempting to add a range that exceeds capacity:\n";
        std::vector<int> exceedingRange = {45, 50, 55};
        sp.addNumbers(exceedingRange.begin(), exceedingRange.end());
        sp.printContents();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}

