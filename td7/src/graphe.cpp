#include "graphe.hpp"

#include<queue>
#include <iostream>
#include<set>
#include<stack>

namespace Graph{
    ////////////            EX01            ////////////////
    void WeightedGraph::add_vertex(int const id)
    {
        if(adjacency_list.find(id) != adjacency_list.end())
            return; 
        
        adjacency_list.insert({id, {}});
    }

    void WeightedGraph::add_directed_edge(int const from, int const to, float const weight)
    {
        add_vertex(to);
        auto edge = adjacency_list.find(from);
        if(edge == adjacency_list.end())
        {
            std::vector<WeightedGraphEdge> value = {};
            edge = adjacency_list.insert(std::make_pair(from, value)).first;
        }
        std::vector<WeightedGraphEdge>& adjacent = std::get<1>(*edge);
        adjacent.emplace_back(to, weight);       
    }

    void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight)
    {
        add_directed_edge(from, to, weight);
        add_directed_edge(to, from, weight);
    }
    WeightedGraph build_from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix)
    {
        WeightedGraph graph;
        for (size_t i = 0; i < adjacency_matrix.size(); i++)
        {
            graph.add_vertex(i);
        }

        for (size_t i = 0; i < adjacency_matrix.size(); i++)
        {
            for (size_t j = 0; j < adjacency_matrix.size(); j++)
            {
                if (adjacency_matrix[i][j] != 0)
                {
                    graph.add_directed_edge(i, j, adjacency_matrix[i][j]);
                }   
            }
        }
        return graph;
    }


    ////////////            EX02            ////////////////
    void WeightedGraph::print_DFS(int const start) const
    {
        std::stack<int> to_visit{};
        std::set<int> visited;
        visited.insert(start);
        to_visit.push(start);
        while (!to_visit.empty())
        {
            int current = to_visit.top();
            auto edge_adjacent = *(adjacency_list.find(current));
            to_visit.pop();

            std::cout << current << std::endl;
            for (WeightedGraphEdge adjacent : std::get<1>(edge_adjacent))
            {
                if (!visited.contains(adjacent.to))
                {
                    to_visit.push(adjacent.to);
                    visited.insert(adjacent.to);
                }
            }
        }
    }

    void WeightedGraph::print_BFS(int const start) const
    {
        std::queue<int> to_visit{};
        std::set<int> visited;
        visited.insert(start);
        to_visit.push(start);
        while (!to_visit.empty())
        {
            int current = to_visit.front();
            auto edge_adjacent = *(adjacency_list.find(current));
            to_visit.pop();

            std::cout << current << std::endl;
            for (WeightedGraphEdge adjacent : std::get<1>(edge_adjacent))
            {
                if (!visited.contains(adjacent.to))
                {
                    to_visit.push(adjacent.to);
                    visited.insert(adjacent.to);
                }
            }
        }
    }
}