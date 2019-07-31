
#include <cstdio>
#include <cstdint>
#include <chrono>
#include <iostream>

#include "algorithm/RepeatedSubtraction.h"
#include "helper/Print.h"
#include "helper/Comparison.h"

template<std::size_t NRS, std::size_t DS, std::size_t QS>
void Test(
    const char * name_fun,
    std::uint8_t (&n_r)[NRS], 
    std::uint8_t (&d)[DS],
    std::uint8_t (&q)[QS], 
    void (&fun)(std::uint8_t (&)[NRS], std::uint8_t (&)[DS], std::uint8_t (&)[QS]),
    std::uint8_t (&t_q)[QS],
    std::uint8_t (&t_r)[NRS])
{
    std::cout << "-----------BEGIN_TEST-----------------" << std::endl;
    std::cout << "Algorithm : " << name_fun << std::endl;
    std::cout << "Input:" << std::endl;
    std::cout << " N : "; helper::Print(n_r); std::cout << std::endl;
    std::cout << " D : "; helper::Print(d); std::cout << std::endl;
    auto start = std::chrono::steady_clock::now();
    fun(n_r, d, q);
	auto end = std::chrono::steady_clock::now();
    std::cout << "Result:" << std::endl;
    std::cout << " Q : "; helper::Print(q); std::cout << std::endl;
    std::cout << " R : "; helper::Print(n_r); std::cout << std::endl;
	std::cout << "Elapsed time : " 
		<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
		<< " ms" << std::endl;
    
    std::cout << "Test : ";
    if (helper::Comparison(n_r, t_r) == 0 && 
        helper::Comparison(t_q, q) == 0 ) std::cout << "Pass";
    else std::cout << "Failed";
    std::cout << std::endl;
    std::cout << "-------------END_TEST-----------------" << std::endl << std::endl;
}

int main()
{
    std::uint8_t n0[2]{0x00, 0x01}; // 256
    std::uint8_t d0[2]{0x08, 0x00}; //8
    std::uint8_t q0[2]{0x00, 0x00}; //0
    std::uint8_t res_q0[2]{0x20, 0x00}; //32
    std::uint8_t res_r0[2]{0x00, 0x00}; //0

    Test("repeated_subtraction", n0, d0, q0, 
        algorithm::repeated_subtraction::Divide,
        res_q0, res_r0);

    
    std::uint8_t n1[4]{0x01, 0x00, 0x00, 0x80}; // 2147483649
    std::uint8_t d1[4]{0x08, 0x00, 0x00, 0x00}; //8
    std::uint8_t q1[4]{0x00, 0x00, 0x00, 0x00}; //0
    std::uint8_t res_q1[4]{0x00, 0x00, 0x00, 0x10}; //268435456
    std::uint8_t res_r1[4]{0x01, 0x00, 0x00, 0x00}; //1
    Test("repeated_subtraction", n1, d1, q1, 
        algorithm::repeated_subtraction::Divide,
        res_q1, res_r1);
    return 0;
}
