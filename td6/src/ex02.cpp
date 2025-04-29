#include "node.hpp"

#include<iostream>

int main()
{
    Node* arbre = create_node(5);
    arbre->insert(3);
    arbre->insert(7);
    arbre->insert(2);
    arbre->insert(4);
    arbre->insert(6);
    arbre->insert(8);
    arbre->insert(1);
    arbre->insert(9);
    arbre->insert(0);

    arbre->display_infix();

    std::cout << "max: " << arbre->max() << std::endl;
    std::cout << "min: " << arbre->min() << std::endl;

    std::vector<Node const*> pref = arbre->prefix();

    int sum = 0;
    for (Node const* node : pref)
    {
        sum += node->value;
    }
    std::cout << "Somme des valeurs des noeuds: " << sum << std::endl;

    std::cout << "Hauteur de l'arbre: " << arbre->height() << std::endl;
}