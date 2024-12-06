#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <climits>

class Span {
private:
    unsigned int _maxSize;       
    std::vector<int> _numbers;

public:
    Span(unsigned int maxSize);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const; 
    int longestSpan() const; 

    // Add a range of numbers using iterators
    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end) {
        if (std::distance(begin, end) > static_cast<int>(_maxSize - _numbers.size())) {
            throw std::overflow_error("Adding this range would exceed the maximum size of the Span.");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }
};

#endif 
