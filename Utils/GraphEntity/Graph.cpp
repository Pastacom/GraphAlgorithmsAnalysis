//
// Created by shind_wvnx on 12.06.2023.
//

#include "Graph.h"

/**
 * Constructor to initialize adjacency matrix with weights and number of vertices.
 * @param vertices number of vertices in graph
 */
Graph::Graph(int vertices) {
    this->vertices = vertices;
    weight_matrix.resize(vertices, std::vector<int64_t>(vertices, 0));
}

/**
 * Adds edge in the graph.
 * @param from source vertex
 * @param to destination vertex
 * @param weight weight of edge
 */
void Graph::addEdge(int from, int to, int64_t weight) {
    ++edges;
    weight_matrix[from][to] = weight;
    weight_matrix[to][from] = weight;
}