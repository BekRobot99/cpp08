#include "MutantStack.hpp"

int main(void)
{
    // Test MutantStack functionality
    std::cout << "--- Testing MutantStack ---" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(-12);
    mstack.push(0);

    std::cout << "Iterating through MutantStack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    std::cout << "MutantStack test complete." << std::endl;

    std::cout << "--- Testing std::vector ---" << std::endl;
    std::vector<int> vecStack;

    vecStack.push_back(5);
    vecStack.push_back(17);

    std::cout << "Top element: " << *(vecStack.end() - 1) << std::endl;

    vecStack.pop_back();

    std::cout << "Size after pop: " << vecStack.size() << std::endl;

    vecStack.push_back(3);
    vecStack.push_back(5);
    vecStack.push_back(737);
    vecStack.push_back(-12);
    vecStack.push_back(0);

    std::cout << "Iterating through std::vector:" << std::endl;
    std::vector<int>::iterator vecIt = vecStack.begin();
    std::vector<int>::iterator vecIte = vecStack.end();

    ++vecIt;
    --vecIt;
    while (vecIt != vecIte)
    {
        std::cout << *vecIt << std::endl;
        ++vecIt;
    }

    std::cout << "std::vector test complete." << std::endl;
    std::cout << "Copied stack top element: " << s.top() << std::endl;
    return 0;
}
