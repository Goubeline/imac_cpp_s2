#pragma once

#include <vector>

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };
    void insert(int value);
    bool is_leaf() const;
    int height() const;
    void delete_children();
    void display_infix() const;
    std::vector<Node const*> prefix() const;
    std::vector<Node const*> postfix() const;
    int min() const;
    int max() const;
};

Node* create_node(int value);
Node*& most_left(Node*& node);
bool remove(Node*& node, int value);
void delete_tree(Node* node);