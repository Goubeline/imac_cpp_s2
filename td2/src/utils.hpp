#pragma once

#include <cmath>
#include <iostream>
#include <iterator>
#include <optional>
#include <string>
#include <sstream>
#include <stack>
#include <variant>
#include <vector>

enum Operator { ADD = 10, SUB = 11, MUL = 20, DIV = 21, OPEN_PAREN = 0, CLOSE_PAREN = 40, POW = 30};
struct Token {
    std::variant<float, Operator> element;
};

Token make_token(float value);
Token make_token(Operator op);
std::vector<std::string> split_string(std::string const& s);
bool is_floating(std::string const& s);
bool npi_operate(std::stack<Token>& pile);
std::optional<float> npi_evaluate(std::vector<Token> const& tokens);