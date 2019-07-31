#ifndef HELPER_COMPARISON_H_
#define HELPER_COMPARISON_H_

#include <cstdint>
#include <cstddef>

namespace helper
{

template<std::size_t AS, std::size_t BS>
int Comparison(std::uint8_t (&a)[AS], std::uint8_t (&b)[BS])
{
    for (std::size_t i = AS - 1, j = BS - 1; i < AS && j < BS;)
    {
        if (i != j)
        {
            if (i > j)
                if (a[i--] != 0) return 1;
            else
                if (b[j--] != 0) return -1;
        }
        if (a[i] == b[j]) 
        {
            --j; --i;
        }
        else return a[i] > b[j] ? 1 : -1;
    }
    return 0;
}

} //!helper

#endif //!HELPER_COMPARISON_H_
