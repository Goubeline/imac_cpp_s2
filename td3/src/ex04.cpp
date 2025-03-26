#include "ex04.hpp"

std::optional<size_t> search(std::vector<int>& vec, int const val, size_t const left, size_t const right)
{
    if (left - right < 1)
    {
        if (vec[left] == val)
        {
            return left;
        }
        else
        {
            return std::nullopt;
        }
    }
    
    size_t mid = (left + right) / 2;
    if (vec[mid] < val)
    {
        return search(vec, val, mid + 1, right);
    }
    else
    {
        return search(vec, val, left, mid);
    }
}


std::optional<size_t> search(std::vector<int>& vec, int const val)
{
    return search(vec, val, 0, vec.size() - 1);
}