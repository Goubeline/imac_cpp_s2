#include "utils.hpp"
#include "ex01.hpp"
#include "ex02.hpp"
#include "ex04.hpp"
#include "counting_sort.hpp"
#include "ScopedTimer.hpp"

int main()
{
    std::vector<int> test_int;
    std::vector<float> test_float;
    bool work = true;

    std::cout << "Test de selection sort:" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        test_int = generate_random_vector_int(10);
        selection_sort(test_int);
        if (!is_sorted(test_int))
        {
            std::cout << "Le tableau n'est pas trie:" << std::endl;
            print_vec<int>(test_int);
            work = false;
        }
    }
    if (work)
    {
        std::cout << "le tri marche" << std::endl << std::endl;
    }
    else
    {
        work = true;
    }
    

    std::cout << "Test de merge sort:" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        test_float = generate_random_vector_float(10);
        merge_sort(test_float);
        if (!is_sorted(test_float))
        {
            std::cout << "Le tableau n'est pas trie:" << std::endl;
            print_vec<float>(test_float);
            work = false;
        }
    }
    if (work)
    {
        std::cout << "le tri marche" << std::endl << std::endl;
    }
    else
    {
        work = true;
    }

    test_int = generate_random_vector_int(10000);
    {
        ScopedTimer timer("selection sort");
        selection_sort(test_int);
    }

    std::vector<float> save = generate_random_vector_float(10000);
    test_float = save;
    {
        ScopedTimer timer("merge sort");
        merge_sort(test_float);
    }

    test_float = save;
    {
        ScopedTimer timer("std::sort");
        std::sort(test_float.begin(), test_float.end());
    }

    
    std::cout << std::endl;
    test_int = {1, 2, 2, 3, 4, 8, 12}; 
    std::optional<size_t> pos = search(test_int, 8);
    if (pos.has_value())
    {
        std::cout << "8 est a la position " << pos.value() << std::endl;
    }
    else
    {
        std::cout << "8 n'est pas dans le vecteur" << std::endl;

    }
    
    test_int = {1, 2, 3, 3, 6, 14, 12, 15}; 
    pos = search(test_int, 15);
    if (pos.has_value())
    {
        std::cout << "15 est a la position " << pos.value() << std::endl;
    }
    else
    {
        std::cout << "15 n'est pas dans le vecteur" << std::endl;

    }

    test_int = {2, 2, 3, 4, 5, 8, 12, 15, 16}; 
    pos = search(test_int, 16);
    if (pos.has_value())
    {
        std::cout << "16 est a la position " << pos.value() << std::endl;
    }
    else
    {
        std::cout << "16 n'est pas dans le vecteur" << std::endl;

    }

    test_int = {5, 6, 7, 8, 9, 10, 11, 12, 13}; 
    pos = search(test_int, 6);
    if (pos.has_value())
    {
        std::cout << "6 est a la position " << pos.value() << std::endl;
    }
    else
    {
        std::cout << "6 n'est pas dans le vecteur" << std::endl;

    }

    test_int = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    pos = search(test_int, 10);
    if (pos.has_value())
    {
        std::cout << "10 est a la position " << pos.value() << std::endl;
    }
    else
    {
        std::cout << "10 n'est pas dans le vecteur" << std::endl;

    }

    std::cout << std::endl << "Test de counting sort:" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        test_int = generate_random_vector_int(10, 20);
        counting_sort_stable(test_int, 19);
        if (!is_sorted(test_int))
        {
            std::cout << "Le tableau n'est pas trie:" << std::endl;
            print_vec<int>(test_int);
            work = false;
        }
    }
    if (work)
    {
        std::cout << "le tri marche" << std::endl << std::endl;
    }
    else
    {
        work = true;
    }
}