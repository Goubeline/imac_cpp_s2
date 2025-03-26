#include "utils.hpp"

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }
bool is_sorted(std::vector<float> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

std::vector<int> generate_random_vector_int(size_t const size, int const max) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

std::vector<float> generate_random_vector_float(size_t const size, int const max) {
    std::vector<float> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return static_cast<float>(std::rand() % max) / max;} );
    return vec;
}