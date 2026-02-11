#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <exception>

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {};

template <typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n){
    if (_size == 0)
        return;
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = T();
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &other){
    if (this == &other)
        return *this;
    delete[] _array;
    _size = other._size;
    _array = (_size > 0) ? new T[_size] : NULL;

    for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
    return *this;
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _array(NULL), _size(other._size){
    if (_size > 0){
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int i){
    if (i >= _size)
        throw std::exception();
    return _array[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const{
    if (i >= _size)
        throw std::exception();
    return _array[i];
}

template <typename T>
unsigned int Array<T>::size() const {return _size;}

#endif