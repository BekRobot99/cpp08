#include "Span.hpp"

Span::Span(unsigned int maxSize) : _maxSize(maxSize) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

// Add a single number
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::overflow_error("Span is already full. Cannot add more numbers.");
    }
    _numbers.push_back(number);
}

// Find the shortest span
int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to calculate the span.");
    }

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = INT_MAX;
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        minSpan = std::min(minSpan, span);
    }
    return minSpan;
}

// Find the longest span
int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to calculate the span.");
    }

    int minElement = *std::min_element(_numbers.begin(), _numbers.end());
    int maxElement = *std::max_element(_numbers.begin(), _numbers.end());
    return maxElement - minElement;
}

void Span::printContents() const {
    std::cout << "Current Span contents (" << _numbers.size() << "/" << _maxSize << "): ";
    for (int num : _numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
