#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *array, const size_t lenght, void(*f)(T &)){
    for (size_t i = 0; i < lenght; i++){
        f(array[i]);
    }
}

template <typename T>
void iter(const T *array, const size_t lenght, void(*f)(T const &)){
    for (size_t i = 0; i < lenght; i++){
        f(array[i]);
    }
}


#endif