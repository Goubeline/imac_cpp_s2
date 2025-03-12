#include "utils.hpp"

Token make_token(float value)
{
    Token e;
    e.element = value;
    return e;
}
Token make_token(Operator op)
{
    Token e;
    e.element = op;
    return e;
}

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s)
{
    bool is_decimal = false;
    for (char c : s)
    {
        if (c == '.')
        {
            if (!is_decimal)
            {
                is_decimal = true;
            }
            else
            {
                return false;
            }
            continue;
        }
        
        if (!std::isdigit(c))
        {
            return false;
        }
    }
    return true;
}

bool npi_operate(std::stack<Token>& pile)
{
    Operator op = std::get<Operator>(pile.top().element);
    pile.pop();
    if (pile.size() < 2)
    {
        return false;
    }
    
    float right = std::get<float>(pile.top().element);
    pile.pop();
    float left = std::get<float>(pile.top().element);
    pile.pop();

    switch (op)
    {
    case Operator::ADD:
        pile.push(make_token(left + right));
        break;
    
    case Operator::SUB:
        pile.push(make_token(left - right));
        break;

    case Operator::MUL:
        pile.push(make_token(left * right));
        break;

    case Operator::DIV:
        pile.push(make_token(left / right));
        break;

    case Operator::POW:
        pile.push(make_token(std::pow(left, right)));
        break;
    
    default:
        return false;
        break;
    }
    return true;
}


std::optional<float> npi_evaluate(std::vector<Token> const& tokens)
{
    std::stack<Token> pile;
    for (Token token : tokens)
    {
        pile.push(token);
        if (std::holds_alternative<Operator>(token.element))
        {
            if(!npi_operate(pile))
            {
                std::cout << "Il n'y a pas assez de nombres pour la quantite d'operandes de votre operation" << std::endl;
                return std::nullopt;
            }
        }
    }
    if (pile.size() > 1)
    {
        std::cout << "Il y a trop de nombres pour la quantite d'operandes de votre operation" << std::endl;
        return std::nullopt;
    }
    return std::get<float>(pile.top().element);;
}