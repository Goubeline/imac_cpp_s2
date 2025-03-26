#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

int vec_square_sum(std::vector<int> const& v)
{
    return { std::accumulate(v.begin(), v.end(), 0, [](int acc, int current_element) { return acc + current_element*current_element; }) };
}

int vec_even_mult(std::vector<int> const& v)
{
    return { std::accumulate(v.begin(), v.end(), 1, [](int acc, int current_element) { return acc * (((current_element/2*2) == current_element) ? current_element : 1); }) };
}

int main()
{
    std::srand(time(NULL));
    std::vector<int> vec;
    for (size_t i = 0; i < 10; i++)
    {
        vec.push_back(std::rand()%100);
    }
    
    std::cout << "vecteur: {";
    for (std::vector<int>::iterator it { vec.begin() }; it != vec.end(); ++it)
    {
        std::cout << *it << ',';
    }
    std::cout << "}" << std::endl;

    std::cout << "la somme des carres des elements du veteur est: " << vec_square_sum(vec) << std::endl;

    std::cout << "le produit des elements pairs du veteur est: " << vec_even_mult(vec) << std::endl;

}