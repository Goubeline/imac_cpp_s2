#pragma once

#include<iostream>

enum class CardKind {
    Heart = 0,
    Diamond = 1,
    Club = 2,
    Spade = 3,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;
    size_t hash() const;
};

bool operator==(Card const& a, Card const& b)
{
    return (a.kind == b.kind && a.value == b.value);
}

size_t Card::hash() const
{
    return static_cast<int>(kind) * 13 + static_cast<int>(value);
}