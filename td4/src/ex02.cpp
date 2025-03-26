#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int nb_lettres_premier_mot(std::string const& phrase)
{
    auto espace = std::find(phrase.begin(), phrase.end(), ' ');

    return std::distance(phrase.begin(), espace);

}

std::vector<std::string> split_string(std::string const& str)
{
    std::vector<std::string> v;
    auto current = str.begin();
    auto start = current;
    std::string mot;
    while (current != str.end())
    {
        mot = "";
        current = std::find_if(start, str.end(), [](char letter){ return letter == ' '; });
        std::copy(start, current, std::back_insert_iterator(mot));
        v.push_back(mot);
        start = current + 1;
    }
    return v;
}

int main()
{
    std::string phrase;
    do
    {
        std::cout << "Saisir une phrase: ";
        std::getline(std::cin, phrase);
        if (!std::cin.fail() && phrase.size() != 0)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "La phrase doit etre non vide.\n";
    } while(true);

    std::cout << "il y a " << nb_lettres_premier_mot(phrase) << " lettres dans le premier mot de la phrase." << std::endl;

    for (std::string mot : split_string(phrase))
    {
        std::cout << mot << std::endl;
    }
    
}