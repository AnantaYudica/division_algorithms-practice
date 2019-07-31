#ifndef HELPER_ADDITION_H_
#define HELPER_ADDITION_H_

#include <cstdint>
#include <cstddef>

namespace helper
{

template<std::size_t AS, std::size_t BS>
void Addition(std::uint8_t (&a)[AS], std::uint8_t (&b)[BS])
{
    std::uint8_t c = 0;
    std::size_t i = 0;
    for (; i < AS && i < BS; ++i)
    {
        std::uint16_t val = c;
        val += a[i];
        val += b[i];
        std::uint8_t * pval = reinterpret_cast<std::uint8_t *>(&val);
        c = pval[1];
        a[i] = pval[0];
    }
    for (; i < AS && c != 0; ++i)
    {
        std::uint16_t val = c;
        val += a[i];
        std::uint8_t * pval = reinterpret_cast<std::uint8_t *>(&val);
        c = pval[1];
        a[i] = pval[0];
    }
}

} //!helper

#endif //!HELPER_ADDITION_H_
