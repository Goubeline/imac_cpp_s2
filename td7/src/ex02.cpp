#include "graphe.hpp"

int main()
{
    std::vector<std::vector<float>> adjacency_matrix = {{0, 0, 1.1},
                                                        {2, 0, 3},
                                                        {0, 5, 0}};
    Graph::WeightedGraph graph1 = Graph::build_from_adjacency_matrix(adjacency_matrix);

    graph1.print_BFS(1);
    graph1.print_DFS(1);

}