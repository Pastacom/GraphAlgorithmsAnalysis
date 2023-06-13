//
// Created by shind_wvnx on 11.06.2023.
//

#include "FloydWarshallAlgorithm.h"

/**
 * Perform Floyd-Warshall algorithm based on set to find path with minimal cost.
 * @param start vertex which is the start of the path
 * @param end vertex which is the end of the path
 * @param graph graph object
 * @return path with minimal cost from start to end
 */
int64_t FloydWarshallAlgorithm::floydWarshall(int start, int end, Graph &graph) {
    std::vector<std::vector<int64_t>> result = getReformatedData(graph);
    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result.size(); ++j) {
            for (size_t l = 0; l < result.size(); ++l) {
                if (result[i][l] != INT64_MAX && result[j][i] != INT64_MAX) {
                    result[j][l] = std::min(result[j][l], result[i][l] + result[j][i]);
                }
            }
        }
    }
    return result[start][end];
}

/**
 * Reformats graph into structure used in the implementation of Floyd-Warshall algorithm.
 * @param graph  graph object
 * @return graph representation for Floyd-Warshall algorithm
 */
std::vector<std::vector<int64_t>> FloydWarshallAlgorithm::getReformatedData(Graph &graph) {
    int n = graph.vertices;
    std::vector<std::vector<int64_t>> result(n);
    auto& matrix = graph.weight_matrix;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0) {
                result[i].push_back(matrix[i][j]);
            } else {
                if (i != j) {
                    result[i].push_back(INT64_MAX);
                } else {
                    result[i].push_back(0);
                }
            }
        }
    }
    return result;
}