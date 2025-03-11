#pragma once

#include <variant>

enum class Operator { ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN, POW};
struct Token {
    std::variant<float, Operator> element;
};