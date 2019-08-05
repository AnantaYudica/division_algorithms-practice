#ifndef HELPER_SCIENTIFICNOTATION_ROUND_H_
#define HELPER_SCIENTIFICNOTATION_ROUND_H_

#include <cstddef>
#include <cstdint>
#include <cstring>

#include "../Additon.h"
#include "../Shift.h"

namespace helper
{
namespace scientific_notation
{

template<std::size_t N>
void Round(std::uint8_t (&x)[N], int & e, std::size_t p)
{
    static std::uint8_t one[] = {1};
    const std::size_t prec = p * 3;
    if (e >= 0 || std::size_t(-e) <= prec) return;
    const std::size_t d = std::size_t(-e) - prec, bf = d - 1;
    const std::size_t i = d / 8, ibf = bf / 8;
    const std::size_t b = d % 8, bbf = bf % 8;
    const std::uint8_t bi = 1 << b, bibf = 1 << bbf;
    const bool r = (x[ibf] & bibf) == bibf;
    helper::Shift(x, -d);
    e += d;
    if (r) helper::Addition(x, one);
}

} //!scientific_notation

} //!helper

#endif //!HELPER_SCIENTIFICNOTATION_ROUND_H_
