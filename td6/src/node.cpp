#include "node.hpp"

#include <iostream>
#include <stack>

Node* create_node(int value)
{
    Node* root { new Node {value, nullptr, nullptr}};
    return root;
}

bool Node::is_leaf() const
{
    return (left == nullptr && right == nullptr);    
}

void Node::insert(int value)
{
    Node** fils;
    if (value < this->value)
    {
        fils = &left;      
    }
    else
    {
        fils = &right;      
    }
    
    if (*fils == nullptr)
    {
        *fils = create_node(value);
        return;
    }
    (*fils)->insert(value);   
}

int Node::height() const
{
    if (left != nullptr)
    {
        int l_height = left->height();
        if (right != nullptr)
        {
            int r_height = right->height();
            if (l_height > r_height)
            {
                return l_height + 1;
            }
            return r_height + 1;
        }
        return l_height + 1;
    }
    if (right != nullptr)
    {
        return right->height() + 1;
    }
    return 1;
}

void Node::delete_children()
{
    if (right != nullptr)
    {
        right->delete_children();
        delete right;
        right = nullptr;
    }
    if (left != nullptr)
    {
        left->delete_children();
        delete left;
        left = nullptr;
    }
}

void Node::display_infix() const
{
    if (left != nullptr)
    {
        left->display_infix();
    }
    std::cout << this->value << std::endl;
    if (right != nullptr)
    {
        right->display_infix();
    }    
}

std::vector<Node const*> Node::prefix() const
{
    std::vector<Node const*> nodes = {};
    std::vector<Node const*> left_nodes = {};
    std::vector<Node const*> right_nodes = {};
    if (left != nullptr)
    {
        left_nodes = {left->prefix()};
    }

    if (right != nullptr)
    {
        right_nodes = {right->prefix()};
    }    
    
    nodes.push_back(this);
    nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    return nodes;
}

std::vector<Node const*> Node::postfix() const
{
    std::vector<Node const*> nodes = {};
    std::stack<Node const*> to_add;
    Node const* current;
    to_add.push(this);
    while (!to_add.empty())
    {
        current = to_add.top();
        to_add.pop();
        if (current->left != nullptr)
        {
            to_add.push(current->left);
        }
        if (current->right != nullptr)
        {
            to_add.push(current->right);
        }
        nodes.insert(nodes.begin(), current);
    }
    return nodes;   
}

Node*& most_left(Node*& node)
{
    if (node->left == nullptr)
    {
        return node;
    }
    return most_left(node);
}

void deleteNode(Node*& node)
{
    if (node->is_leaf())
    {
        delete node;
        node = nullptr;
        return;
    }
    if (node->left == nullptr)
    {
        delete node;
        node = node->right;
        return;
    }
    if (node->right == nullptr)
    {
        delete node;
        node = node->left;
        return;
    } 

    Node* suppr = most_left(node->right);
    node->value = suppr->value;
    deleteNode(suppr);
}

bool remove(Node*& node, int value)
{
    if (node->value == value)
    {
        deleteNode(node);
        return true;
    }

    Node* fils;
    if (node->value > value)
    {
        fils = node->left;
    }
    else
    {
        fils = node->right;
    }
    
    if (fils == nullptr)
    {
        return false;
    }
    return remove(fils, value);   
}

void delete_tree(Node* node)
{
    node->delete_children();
    delete node;
}

int Node::min() const
{
    if (left != nullptr)
    {
        return left->min();
    }
    return value;
}

int Node::max() const
{
    if (right != nullptr)
    {
        return right->max();
    }
    return value;
}