#include "ex01.hpp"

void bubble_sort(std::vector<int> & vec);
void selection_sort(std::vector<int> & vec)
{
    int min;
    int buf;
    size_t pos;
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        min = vec[i];
        pos = i;
        for (size_t j = i + 1; j < vec.size(); j++)
        {
            if (min > vec[j])
            {
                min = vec[j];
                pos = j;
            }
        }
        buf = vec[i];
        vec[i] = min;
        vec[pos] = buf;
    }
    
}