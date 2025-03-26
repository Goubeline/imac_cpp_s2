#include "counting_sort.hpp"

void counting_sort_stable(std::vector<int>& vec, int const max)
{
    std::vector<int> counter (max + 1, 0);
    for (int i : vec)
    {
        counter[i]++;
    }

    for (int i = 1; i < counter.size(); i++)
    {
        counter[i] += counter[i - 1];
    }
    
    std::vector<int> sorted_vec (vec.size(), 0);
    for (int val : vec)
    {
        sorted_vec[counter[val] - 1] = val;
        counter[val]--;
    }
    vec = sorted_vec;
}