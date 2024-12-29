#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Type aliases for iterator types from the underlying container
    using iterator = typename std::stack<T>::container_type::iterator;
    using const_iterator = typename std::stack<T>::container_type::const_iterator;
    using reverse_iterator = typename std::stack<T>::container_type::reverse_iterator;
    using const_reverse_iterator = typename std::stack<T>::container_type::const_reverse_iterator;

    MutantStack() : std::stack<T>() {}
    MutantStack(const std::stack<T>& other) : std::stack<T>(other) {}
    MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
    MutantStack<T>& operator=(const MutantStack<T>& other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }
    ~MutantStack() {}

    // Iterator support
    iterator begin() { return this->c.begin(); }
    const_iterator begin() const { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator end() const { return this->c.end(); }

    // Reverse iterator support
    reverse_iterator rbegin() { return this->c.rbegin(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
