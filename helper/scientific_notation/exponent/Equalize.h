#ifndef HELPER_SCIENTIFICNOTATION_EXPONENT_EQUALIZE_H_
#define HELPER_SCIENTIFICNOTATION_EXPONENT_EQUALIZE_H_

#include <cstddef>
#include <cstdint>

#include "../../Shift.h"

namespace helper
{
namespace scientific_notation
{
namespace exponent
{

template<std::size_t AS, std::size_t BS>
void Equalize(std::uint8_t (&a)[AS], int & a_e,
    std::uint8_t (&b)[BS], int & b_e)
{
    if (a_e > b_e)
    {
        helper::Shift(a, a_e - b_e);
        a_e = b_e;
    }
    else if (a_e < b_e)
    {
        helper::Shift(b, b_e - a_e);
        b_e = a_e;
    }
}

} //!exponent

} //!scientific_notation

} //!helper

#endif //!HELPER_SCIENTIFICNOTATION_EXPONENT_EQUALIZE_H_
