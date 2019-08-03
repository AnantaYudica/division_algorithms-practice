#ifndef HELPER_MULTIPLICATION_H_
#define HELPER_MULTIPLICATION_H_

#include <cstdint>
#include <cstddef>

#include "Shift.h"
#include "Additon.h"

namespace helper
{

template<std::size_t AS, std::size_t BS, std::size_t RS>
void Multiplication(std::uint8_t (&a)[AS], std::uint8_t (&b)[BS],
    std::uint8_t (&r)[RS])
{
    for (std::size_t i = 0; i < BS; ++i)
    {
        std::uint8_t mul[RS];
        std::uint16_t c = 0;
        std::uint8_t * cc = reinterpret_cast<std::uint8_t *>(&c);
        std::size_t j;
        for (j = 0; j < AS; ++j)
        {
            std::uint16_t val = a[j];
            val *= b[i];
            std::uint8_t * pval = reinterpret_cast<std::uint8_t *>(&val);
            if (val == 0 && c == 0) break;
            c += pval[0];
            mul[j] = cc[0];
            c >>= sizeof(std::uint8_t) * 8;
            c += pval[1];
        }
        if (j < RS)  mul[j] = cc[0];
        if ((j + 1) < RS) mul[j + 1] = cc[1];
        Shift(mul, i * 8);
        Addition(r, mul);
    }
}

} //!helper

#endif //!HELPER_MULTIPLICATION_H_
