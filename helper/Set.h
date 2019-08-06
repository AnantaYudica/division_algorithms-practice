#ifndef HELPER_SET_H_
#define HELPER_SET_H_

#include <cstdint>
#include <cstddef>
#include <cstring>

namespace helper
{

template<std::size_t AS, std::size_t BS>
void Set(std::uint8_t (&a)[AS], std::uint8_t (&b)[BS])
{
    std::memset(a, 0, AS);
    for (std::size_t i = 0; i < AS && i < BS; ++i)
        a[i] = b[i];
}

template<std::size_t N>
void Set(std::uint8_t (&a)[N], std::uint8_t  b)
{
    std::memset(a, 0, N);
    a[0] = b;
}

} //!helper

#endif //!HELPER_SET_H_
