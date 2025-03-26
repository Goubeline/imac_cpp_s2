#include "ex02.hpp"

// size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot);
// void quick_sort(std::vector<float> & vec, size_t const left, size_t const right);
// void quick_sort(std::vector<float> & vec) {
//     quick_sort(vec, 0, vec.size() - 1);
// }

void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right)
{
    std::vector<float> temp;
    size_t min_left = left;;
    size_t min_right = middle;
    while (true)
    {
        if (vec[min_left] < vec[min_right])
        {
            temp.push_back(vec[min_left]);
            min_left ++;
            if (min_left == middle)
            {
                break;
            }
        }
        else
        {
            temp.push_back(vec[min_right]);
            min_right ++;
            if (min_right == right)
            {
                break;
            }
        }
    }
    
    while (min_left < middle)
    {
        temp.push_back(vec[min_left]);
        min_left++;
    }

    // copie de temp dans vec
    std::copy(temp.begin(), temp.end(), vec.begin() + left);}

void merge_sort(std::vector<float> & vec, size_t const left, size_t const right)
{
    if (right - left < 1)
    {
        return;
    }
    merge_sort(vec, left + (right - left) / 2 + 1, right);
    merge_sort(vec, left, left + (right - left) / 2);
    merge_sort_merge(vec, left, left + (right - left) / 2 + 1, right + 1);
}

void merge_sort(std::vector<float> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}