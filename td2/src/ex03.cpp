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

    case '(':
        return Operator::OPEN_PAREN;
        break;

    case ')':
        return Operator::CLOSE_PAREN;
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

bool operator_priority(std::vector<Token>& npi, std::stack<Token>& ope_stack, Token& op)
{
    if (std::get<Operator>(op.element) == Operator::CLOSE_PAREN)
    {
        if (ope_stack.size() == 0)
        {
            return false;
        }
        
        while (std::get<Operator>(ope_stack.top().element) != Operator::OPEN_PAREN)
        {
            npi.push_back(ope_stack.top());
            ope_stack.pop();
            if (ope_stack.size() == 0)
            {
                std::cout << "Une parenthèse fermante n'a pas de parenthèse ouvrante la précédant" << std::endl;
                return false;
            }
        }
        ope_stack.pop();
        return true;
    }

    if (std::get<Operator>(op.element) != Operator::OPEN_PAREN && std::get<Operator>(op.element) != Operator::POW)
    {
        while (ope_stack.size() > 0 && std::get<Operator>(ope_stack.top().element) / 10 >=
                                        std::get<Operator>(op.element) / 10)
        {
            npi.push_back(ope_stack.top());
            ope_stack.pop();
        }
    }
    ope_stack.push(op);
    return true;    
}

std::optional<std::vector<Token>> shutting_yard(std::vector<Token>& tokens)
{
    std::vector<Token> npi;
    std::stack<Token> ope_stack;
    for (Token token : tokens)
    {
        if (std::holds_alternative<float>(token.element))
        {
            npi.push_back(token);
        }
        else
        {
            if (!operator_priority(npi, ope_stack, token))
            {
                return std::nullopt;
            }
        }
    }

    while (ope_stack.size() != 0)
    {
        if (std::get<Operator>(ope_stack.top().element) == Operator::OPEN_PAREN)
        {
            std::cout << "Il y a trop de parenthèses ouvrantes dans votre expression" << std::endl;
            return std::nullopt;
        }
        npi.push_back(ope_stack.top());
        ope_stack.pop();
    }
    return npi;
}

int main()
{
    std::string infixe;
    std::cout << "Donnez votre expression en notation infixe a calculer :" << std::endl;
    std::getline(std::cin, infixe);
    
    std::vector<std::string> words = split_string(infixe);

    std::optional<std::vector<Token>> maybe_tokens = tokenize(words);
    if (!maybe_tokens.has_value())
    {
        return 1;
    }
    std::vector<Token> tokens = maybe_tokens.value();

    std::optional<std::vector<Token>> maybe_npi = shutting_yard(tokens);
    if (!maybe_npi.has_value())
    {
        return 1;
    }    
    std::vector<Token> npi = maybe_npi.value();

    for (Token token : npi)
    {
        if (std::holds_alternative<float>(token.element))
        {
            std::cout << std::get<float>(token.element) << std::endl;
        }
        else
        {
            std::cout << "operateur: " << std::get<Operator>(token.element) << std::endl;
        }
        
    }
    
    std::optional<float> result = npi_evaluate(npi);
    if (result.has_value())
    {
        std::cout << "Le resultat est: " << result.value() << std::endl;
        return 0;
    }
    return 1;
}