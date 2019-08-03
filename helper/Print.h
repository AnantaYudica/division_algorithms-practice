#ifndef HELPER_PRINT_H_
#define HELPER_PRINT_H_

#include <cstdint>
#include <cstddef>
#include <cstdio>

namespace helper
{

template<std::size_t N>
void Print(std::uint8_t (&a)[N])
{
    printf("0x");
    bool f = false;
    for (std::size_t i = N - 1; i < N; --i)
    {
        printf("%02X", a[i]);
    }
}

template<std::size_t N>
void Print(std::uint8_t (&a)[N], const int & e)
{
    Print(a);
    if (e != 0) printf("E%c%d", e > 0 ? '+':'-', e);
}

} //!helper

#endif //!HELPER_PRINT_H_
