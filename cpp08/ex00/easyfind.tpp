#include "easyfind.hpp"

template <typename T>
void    easyfind(const T& con, int value){
    typename T::const_iterator it =
    std::find(con.begin(), con.end(), value);

    if (it == con.end())
        throw std::exception();

}