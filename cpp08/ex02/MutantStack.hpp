#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <iostream>

template <class T, class container  = std::deque<T> >
class MutantStack : public std::stack<T, container> {
    public:
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack();

        typedef typename container::iterator iterator;
        typedef typename container::const_iterator const_iterator;
        iterator        begin();
        iterator	    end();
        const_iterator  begin() const;
        const_iterator  end() const;

        typedef typename container::reverse_iterator reverse_iterator;
        typedef typename container::const_reverse_iterator const_reverse_iterator;
        reverse_iterator        rbegin();
        reverse_iterator	    rend();
        const_reverse_iterator  rbegin() const;
        const_reverse_iterator  rend() const;
};

#include "MutantStack.tpp"

#endif