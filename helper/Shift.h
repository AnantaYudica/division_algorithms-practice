#ifndef HELPER_SHIFT_H_
#define HELPER_SHIFT_H_

#include <cstdint>
#include <cstddef>

namespace helper
{

template<std::size_t N>
void Shift(std::uint8_t (&a)[N], int s)
{
    constexpr int bsize = sizeof(std::uint8_t) * 8;
    std::uint8_t c = 0;
    int b = (s % bsize);
    s = (s / bsize);
    if (s > 0 || b > 0)
    {
        for (std::size_t i = N - 1, j = N - (s + 1); i < N;)
        {
            if (b == 0)
                a[i--] = (j >= N ? 0 : a[j--]);
            else
                a[i--] = std::uint8_t(a[j--] << b) | ((j >= N) ? std::uint8_t(0) : 
                    std::uint8_t(a[j] >> (8 - b)));
        }
    }
    else if (s < 0 || b < 0)
    {
        for (std::size_t i = 0, j = -s; i < N;)
        {
            if (b == 0)
                a[i++] = (j >= N ? 0 : a[j++]);
            else
                a[i++] = std::uint8_t(a[j++] >> -b) | ((j >= N) ? std::uint8_t(0) : 
                    std::uint8_t(a[j] << (8 + b)));
        }
    }
}

} //!helper

#endif //!HELPER_SHIFT_H_
