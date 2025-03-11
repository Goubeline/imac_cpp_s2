#include "ex02.hpp"

#include <cmath>
#include <iostream>
#include <iterator>
#include <optional>
#include <string>
#include <sstream>
#include <stack>
#include <vector>

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

std::optional<Operator> is_operator (std::string const& s)
{
    if (s.size() != 1)
    {
        return std::nullopt;
    }
    switch (s[0])
    {
    case '+':
        return Operator::ADD;
        break;
    
    case '-':
        return Operator::SUB;
        break;

    case '*':
        return Operator::MUL;
        break;

    case '/':
        return Operator::DIV;
        break;

    case '^':
        return Operator::POW;
        break;

    default:
        return std::nullopt;
        break;
    }
}

std::optional<std::vector<Token>> tokenize(std::vector<std::string> const& words)
{
    std::vector<Token> tokens;
    for (std::string word : words)
    {
        if (is_floating(word))
        {
            tokens.push_back(make_token(std::stof(word)));
            continue;
        }
        
        std::optional<Operator> op = is_operator(word);
        if (op.has_value())
        {
            tokens.push_back(make_token(op.value()));
        }
        else
        {
            std::cout << '"' << word << '"' << " n'est ni un operateur ni un nombre" << std::endl;
            return std::nullopt;
        }
    }
    return tokens;
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

int main()
{
    std::string npi;
    std::cout << "Donnez votre expression NPI a calculer :" << std::endl;
    std::getline(std::cin, npi);
    
    std::vector<std::string> words = split_string(npi);

    std::optional<std::vector<Token>> maybe_tokens = tokenize(words);
    if (!maybe_tokens.has_value())
    {
        return 1;
    }
    std::vector<Token> tokens = maybe_tokens.value();

    std::optional<float> result = npi_evaluate(tokens);
    if (result.has_value())
    {
        std::cout << "Le resultat est: " << result.value() << std::endl;
        return 0;
    }
    return 1;
}