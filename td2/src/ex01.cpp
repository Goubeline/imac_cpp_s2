#include "utils.hpp"

bool is_operator (std::string const& s)
{
    return (s.size() == 1 && (s[0] == '+' || s[0] == '*' || s[0] == '/' || s[0] == '-' || s[0] == '^'));
}

bool npi_operate_str(std::stack<float>& pile, std::string& operate)
{
    if (pile.size() < 2)
    {
        return false;
    }
    
    float right = pile.top();
    pile.pop();
    float left = pile.top();
    pile.pop();
    switch (operate[0])
    {
    case '+':
        pile.push(left + right);
        break;
    
    case '-':
        pile.push(left - right);
        break;

    case '/':
        pile.push(left / right);
        break;

    case '*':
        pile.push(left * right);
        break;

    case '^':
        pile.push(std::pow(left, right));
        break;
    
    default:
        return false;
        break;
    }
    return true;
}


std::optional<float> npi_evaluate_str(std::vector<std::string> const& tokens)
{
    std::stack<float> pile;
    for (std::string token : tokens)
    {
        if (is_floating(token))
        {
            pile.push(std::stof(token));
        }
        else if (is_operator(token))
        {
            if(!npi_operate_str(pile, token))
            {
                std::cout << "Il n'y a pas assez de nombres pour la quantite d'operandes de votre operation" << std::endl;
                return std::nullopt;
            }
        }
        else
        {
            std::cout << '"' << token << '"' << " n'est ni un nombre ni un operateur" << std::endl;
            return std::nullopt;
        }
    }
    if (pile.size() > 1)
    {
        std::cout << "Il y a trop de nombres pour la quantite d'operandes de votre operation" << std::endl;
        return std::nullopt;
    }
    return pile.top();
}

int main()
{
    std::string npi;
    std::cout << "Donnez votre expression NPI a calculer :" << std::endl;
    std::getline(std::cin, npi);
    
    std::vector<std::string> tokens = split_string(npi);

    std::optional<float> result = npi_evaluate_str(tokens);
    if (result.has_value())
    {
        std::cout << "Le resultat est: " << result.value() << std::endl;
        return 0;
    }
    return 1;
}