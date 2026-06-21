#include "easyfind.hpp"

template <typename T>
typename T::const_iterator easyfind(const T& con, int value)
{
    typename T::const_iterator it = std::find(con.begin(), con.end(), value);

    if (it == con.end())
        throw std::runtime_error("Value not found");

    return it;
}
