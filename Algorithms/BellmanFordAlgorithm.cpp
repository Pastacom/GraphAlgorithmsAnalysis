//
// Created by shind_wvnx on 11.06.2023.
//

#include "BellmanFordAlgorithm.h"
/**
 * Struct to store arcs between vertices in graph for Bellman-Ford algorithm.
 */
struct BellmanFordAlgorithm::Arc {
public:
    int first, second;
    int64_t weight;

    Arc() = default;

    Arc(int first, int second, int64_t weight) {
        this->first = first;
        this->second = second;
        this->weight = weight;
    }
};

/**
 * Perform Bellman-Ford algorithm to find path with minimal cost.
 * @param start vertex which is the start of the path
 * @param end vertex which is the end of the path
 * @param graph graph object
 * @return path with minimal cost from start to end
 */
int64_t BellmanFordAlgorithm::bellmanFord(int start, int end, Graph& graph) {
    std::vector<Arc> arcs = getReformatedData(graph);
    int n = graph.vertices;
    std::vector<int64_t> result(n, INT64_MAX);
    result[start] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (Arc &arc : arcs) {
            if (result[arc.first] < INT64_MAX &&
                result[arc.second] > result[arc.first] + arc.weight) {
                result[arc.second] = result[arc.first] + arc.weight;
            }
        }
    }
    return result[end];
}

/**
 * Reformats graph into structure used in the implementation of Bellman-Ford algorithm.
 * @param graph  graph object
 * @return graph representation for Bellman-Ford algorithm
 */
std::vector<BellmanFordAlgorithm::Arc> BellmanFordAlgorithm::getReformatedData(Graph &graph) {
    std::vector<Arc> arcs;
    auto& matrix = graph.weight_matrix;
    for (int i = 0; i < graph.vertices; ++i) {
        for (int j = 0; j < graph.vertices; ++j) {
            if (matrix[i][j] != 0) {
                arcs.emplace_back(i, j, matrix[i][j]);
            }
        }
    }
    return arcs;
}