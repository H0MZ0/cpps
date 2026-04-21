#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "MutantStack test:" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    MutantStack<int> b(mstack);
    MutantStack<int> c;
    c = b;

    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "Const iterator test:" << std::endl;
    const MutantStack<int> constStack(mstack);
    MutantStack<int>::const_iterator cit = constStack.begin();
    MutantStack<int>::const_iterator cite = constStack.end();
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }

    std::cout << "std::list equivalent test:" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::stack<int> s(mstack);
    return 0;
}
