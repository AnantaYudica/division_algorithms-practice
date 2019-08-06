#ifndef ALGORITHM_NEWTONRAPHSON_DEVIDE_H_
#define ALGORITHM_NEWTONRAPHSON_DEVIDE_H_

#include <algorithm>
#include <cstring>
#include <cstdint>
#include "../helper/Comparison.h"
#include "../helper/Shift.h"
#include "../helper/Subtraction.h"
#include "../helper/Additon.h"
#include "../helper/Multiplication.h"
#include "../helper/Set.h"
#include "../helper/scientific_notation/Round.h"
#include "../helper/scientific_notation/exponent/Equalize.h"

namespace algorithm
{
namespace newton_raphson
{

template<std::size_t NRS, std::size_t DS, std::size_t QS>
void Divide(std::uint8_t (&n_r)[NRS], std::uint8_t (&d)[DS],
    std::uint8_t (&q)[QS])
{
    constexpr std::size_t p = (NRS * 8) / 3; 
    constexpr std::size_t size = (NRS * 2);
    std::uint8_t x0[size], x[size], xn[size], bx[size], c2[size];
    int x0_e = -1, x_e = 0, xn_e = -((DS * 8) / 3), c2_e = 1, bx_e = 0;
    helper::Set(xn, 0x01);
    helper::Set(c2, 0x01);
    do
    {
        std::memcpy(x0, xn, size);
        x0_e = xn_e;
        std::memcpy(x, c2, size);
        x_e = c2_e;
        std::memset(bx, 0, size);
        helper::Multiplication(x0, d, bx);
        bx_e = x0_e;
        helper::scientific_notation::exponent::Equalize(x, x_e, bx, bx_e);
        helper::Subtraction(x, bx);
        std::memset(xn, 0, size);
        helper::Multiplication(x0, x, xn);
        xn_e = x0_e + x_e;
        helper::scientific_notation::Round(xn, xn_e, p);
        helper::scientific_notation::exponent::Equalize(xn, xn_e, x0, x0_e);
    } while(helper::Comparison(x0, xn) != 0);
    helper::Multiplication(n_r, x0, xn);
    helper::Shift(xn, xn_e);
    std::memcpy(q, xn, QS);
    std::memset(xn, 0, size);
    helper::Multiplication(q, d, xn);
    helper::Subtraction(n_r, xn);
}

} //!newton_raphson

} //!algorithm

#endif //!ALGORITHM_NEWTONRAPHSON_DEVIDE_H_
