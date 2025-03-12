#include "utils.hpp"

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