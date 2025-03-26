#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

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

    int nombre;
    do
    {
        std::cout << "Saisir le nombre que vous voulez chercher: ";
        std::cin >> nombre;
        if (!std::cin.fail() && std::cin.peek() == '\n')
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "La valeur entree doit être un nombre entier.\n";
    } while(true);

    auto it = std::find(vec.begin(), vec.end(), nombre);
    if (it != vec.end())
        std::cout << "Le nombre est present dans le le vecteur." << std::endl;
    else
        std::cout << "Le nombre n'est pas present dans le le vecteur." << std::endl;

    std::cout << "Le nombre " << nombre << " est present " << std::count(vec.begin(), vec.end(), nombre) << " fois dans le vecteur." << std::endl;

    std::sort(vec.begin(), vec.end());
    std::cout << "vecteur trie: {";
    for (std::vector<int>::iterator it { vec.begin() }; it != vec.end(); ++it)
    {
        std::cout << *it << ',';
    }
    std::cout << "}" << std::endl;

    std::cout << "La somme des valeurs du vecteur est " << std::accumulate(vec.begin(), vec.end(), 0, [](int acc, int current_element) { return acc + current_element; }) << std::endl;
}