template <class T, class container>
MutantStack<T, container>::MutantStack() : std::stack<T, container>() {}

template <class T, class container>
MutantStack<T, container>::MutantStack(const MutantStack& obj){
    *this = obj;
}

template <class T, class container>
MutantStack<T, container>& MutantStack<T, container>::operator=(const MutantStack& obj)
{
    if (this != &obj)
        this->c = obj.c;
    return *this;
}

template <class T, class container>
MutantStack<T, container>::~MutantStack() {}

template <class T, class container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::begin(){
    return this->c.begin();
}

template <class T, class container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::end(){
    return this->c.end();
}

template <class T, class container>
typename MutantStack<T, container>::const_iterator MutantStack<T, container>::begin() const{
    return this->c.begin();
}

template <class T, class container>
typename MutantStack<T, container>::const_iterator MutantStack<T, container>::end() const{
    return this->c.end();
}

template <class T, class container>
typename MutantStack<T, container>::reverse_iterator MutantStack<T, container>::rbegin(){
    return this->c.rbegin();
}

template <class T, class container>
typename MutantStack<T, container>::reverse_iterator MutantStack<T, container>::rend(){
    return this->c.rend();
}

template <class T, class container>
typename MutantStack<T, container>::const_reverse_iterator MutantStack<T, container>::rbegin() const{
    return this->c.rbegin();
}

template <class T, class container>
typename MutantStack<T, container>::const_reverse_iterator MutantStack<T, container>::rend() const{
    return this->c.rend();
}