#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

bool is_palindrom(std::string const& phrase)
{
    return std::equal(phrase.begin(), phrase.end(), phrase.rbegin(), phrase.rend());
}

int main()
{
    std::string phrase;
    do
    {
        std::cout << "Saisir un palindrome: ";
        std::getline(std::cin, phrase);
        if (!std::cin.fail() && phrase.size() != 0)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "La phrase doit etre non vide.\n";
    } while(true);

    if (is_palindrom(phrase))
    {
        std::cout << "C'est un palidrome." << std::endl;
    }
    else
    {
        std::cout << "Ce n'est pas un palidrome." << std::endl;
    }
}