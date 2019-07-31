#ifndef HELPER_SHIFT_H_
#define HELPER_SHIFT_H_

#include <cstdint>
#include <cstddef>

namespace helper
{

template<std::size_t N>
void Shift(std::uint8_t (&a)[N], int s)
{
    if (s == 0) return;
    if (s > 0)
    {
        for (std::size_t i = N - 1, j = N - s; i >= N;)
        {
            if (j >= N)
                a[i--] = 0;
            else
                a[i--] = a[j--];
        }
    }
    else
    {
        for (std::size_t i = 0, j = -s; i < N;)
        {
            if (j >= N)
                a[i++] = 0;
            else
                a[i++] = a[j++];
        }
    }
}

} //!helper

#endif //!HELPER_SHIFT_H_
