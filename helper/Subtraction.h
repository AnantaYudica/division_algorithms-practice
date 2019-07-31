#ifndef HELPER_SUBTRACTION_H_
#define HELPER_SUBTRACTION_H_

#include <cstdint>
#include <cstddef>

namespace helper
{

template<std::size_t MS, std::size_t SS>
void Subtraction(std::uint8_t (&m)[MS], std::uint8_t (&s)[SS])
{
    std::uint8_t c = 0;
    std::size_t i = 0;
    for (; i < MS && i < SS; ++i)
    {
        std::uint16_t val = m[i];
        val -= s[i];
        val -= c;
        std::uint8_t * pval = reinterpret_cast<std::uint8_t *>(&val);
        c = (~pval[1] + std::uint8_t(1));
        m[i] = pval[0];
    }
    for (; c != 0 && i < MS; ++i)
    {
        std::uint16_t val = m[i];
        val -= c;
        std::uint8_t * pval = reinterpret_cast<std::uint8_t *>(&val);
        c = (~pval[1] + std::uint8_t(1));
        m[i] = pval[0];
    }
}

} //!helper

#endif //!HELPER_SUBTRACTION_H_
