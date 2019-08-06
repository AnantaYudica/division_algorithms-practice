#ifndef HELPER_SCIENTIFICNOTATION_ROUND_H_
#define HELPER_SCIENTIFICNOTATION_ROUND_H_

#include <cstddef>
#include <cstdint>
#include <cstring>

#include "../Additon.h"
#include "../Multiplication.h"
#include "../Shift.h"

namespace helper
{
namespace scientific_notation
{

template<std::size_t N>
void Round(std::uint8_t (&x)[N], int & e, std::size_t p)
{
    static std::uint8_t one[] = {1}, ten[] = {0x0A};
    std::uint8_t sum[N], mul[N];
    const std::size_t prec = p * 3;
    if (e >= 0 || std::size_t(-e) <= prec) return;
    std::memcpy(sum, x, N);
    for (std::size_t i = 0; i < p; ++i)
    {
        std::memset(mul, 0, N);
        helper::Multiplication(sum, ten, mul);
        std::memcpy(sum, mul, N);
    }
    const std::size_t abs_e = std::size_t(-e), prev_e = abs_e - 1;
    const std::size_t d = abs_e - prec;
    const std::size_t i = prev_e / 8;
    const std::size_t b = prev_e % 8;
    const std::uint8_t bi = 1 << b;
    const bool r = (sum[i] & bi) == bi;
    helper::Shift(x, -d);
    e += d;
    if (r) helper::Addition(x, one);
}

} //!scientific_notation

} //!helper

#endif //!HELPER_SCIENTIFICNOTATION_ROUND_H_
