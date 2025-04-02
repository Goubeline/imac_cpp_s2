#include <iostream>

size_t folding_string_hash(std::string const& s, size_t max)
{
    size_t hash = 0;
    for (char lettre : s)
    {
        hash += lettre;
    }
    hash %= max;
    return hash;   
}

size_t folding_string_ordered_hash(std::string const& s, size_t max)
{
    size_t hash = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        hash += s[i] * i;
    }
    hash %= max;
    return hash; 
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m)
{
    size_t hash = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        hash += s[i] * p;
        hash %= m;
        p *= p;
    }

    return hash;  
}