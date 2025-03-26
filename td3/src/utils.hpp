#pragma once

#include <iostream>
#include <optional>
#include <vector>
#include <cstdlib>
#include <algorithm>


template<typename T> void print_vec(std::vector<T> const& vec)
{
    std::cout << '[';
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[vec.size() - 1] << ']' << std::endl;   
}
bool is_sorted(std::vector<int> const& vec);
bool is_sorted(std::vector<float> const& vec);
std::vector<int> generate_random_vector_int(size_t const size, int const max = 100);
std::vector<float> generate_random_vector_float(size_t const size, int const max = 100);