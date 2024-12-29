#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm> 
#include <exception>

// Exception class for when the integer is not found
class NotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Value not found in the container.";
    }
};

// Template function easyfind
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    // Use std::find to search for the value
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw NotFoundException(); // Throw exception if not found
    }
    return it; // Return iterator to the found element
}

#endif // EASYFIND_HPP
