#include "graphe.hpp"

#include <iostream>

int main()
{
    Graph::WeightedGraph graph2;
    graph2.add_directed_edge(1, 0, 2);
    graph2.add_directed_edge(1, 2, 3);
    graph2.add_directed_edge(0, 2, 1.1);
    graph2.add_directed_edge(2, 1, 5);
    std::vector<std::vector<float>> adjacency_matrix = {{0, 0, 1.1},
                                                        {2, 0, 3},
                                                        {0, 5, 0}};
    Graph::WeightedGraph graph1 = Graph::build_from_adjacency_matrix(adjacency_matrix);
    if (graph1 == graph2)
    {
        std::cout << "C'est bon" << std::endl;
    }
    else
    {
        std::cout << "Graphes différents" << std::endl;
    }
    
}