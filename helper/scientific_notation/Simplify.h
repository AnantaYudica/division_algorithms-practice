#ifndef HELPER_SCIENTIFICNOTATION_SIMPLIFY_H_
#define HELPER_SCIENTIFICNOTATION_SIMPLIFY_H_

#include <cstddef>
#include <cstdint>

namespace helper
{
namespace scientific_notation
{

template<std::size_t N>
void Simplify(std::uint8_t (&x)[N], int & e)
{
    int i = 0;
    int b = 0;
    std::uint8_t bi = 1;
    while(i < N && x[i] == 0) ++i;
    if (i == N) return;
    while(bi != std::uint8_t(0) && (x[i] & bi) == 0)
    {
        ++b;
        bi <<= 1; 
    }
    i *= 8;
    helper::Shift(x, -(i + b));
    e += (i + b);
}

} //!scientific_notation

} //!helper

#endif //!HELPER_SCIENTIFICNOTATION_SIMPLIFY_H_
