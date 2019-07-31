#ifndef ALGORITHM_REPEATEDSUBTRACTION_DEVIDE_H_
#define ALGORITHM_REPEATEDSUBTRACTION_DEVIDE_H_

#include <algorithm>
#include <cstring>
#include <cstdint>
#include "../helper/Comparison.h"
#include "../helper/Shift.h"
#include "../helper/Subtraction.h"
#include "../helper/Additon.h"

namespace algorithm
{
namespace repeated_subtraction
{

template<std::size_t NRS, std::size_t DS, std::size_t QS>
void Divide(std::uint8_t (&n_r)[NRS], std::uint8_t (&d)[DS],
    std::uint8_t (&q)[QS])
{
    static std::uint8_t one[1]{0x01};
    while(helper::Comparison(n_r, d) >= 0)
    {
        helper::Subtraction(n_r, d);
        helper::Addition(q, one);
    }
}

} //!repeated_subtraction

} //!algorithm

#endif //!ALGORITHM_REPEATEDSUBTRACTION_DEVIDE_H_
