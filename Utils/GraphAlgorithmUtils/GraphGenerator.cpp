//
// Created by shind_wvnx on 11.06.2023.
//

#include <cstdlib>
#include "../GraphEntity/Graph.h"

/**
 * Method to generate complete graph.
 * @param vertices number of vertices in generated graph
 * @return graph object
 */
static Graph generateCompleteGraph(int vertices) {
    Graph graph(vertices);

    for (int i = 0; i < vertices; ++i) {
        for (int j = i + 1; j < vertices; ++j) {
            graph.addEdge(i, j, rand() % 10 + 1);
        }
    }
    return graph;
}

/**
 * Method to generate connected graph with density ~0.45.
 * @param vertices number of vertices in generated graph
 * @return graph object
 */
static Graph generateConnectedGraph(int vertices) {
    Graph graph(vertices);

    int vertex = rand() % vertices;
    int maxEdges = vertices * (vertices - 1) / 2;
    int edges = static_cast<int>(0.45 * maxEdges) - (vertices - 1);
    for (int i = 0; i < vertices; ++i) {
        if (i != vertex) {
            graph.addEdge(i, vertex, rand() % 10 + 1);
        }
    }
    while (edges > 0) {
        int u = rand() % vertices;
        int v = rand() % vertices;

        if (u != v && graph.weight_matrix[u][v] == 0) {
            graph.addEdge(u, v, rand() % 10 + 1);
            --edges;
        }
    }
    return graph;
}

/**
 * Method to generate sparse graph that is also a connected tree.
 * @param vertices number of vertices in generated graph
 * @return graph object
 */
static Graph generateSparseGraph(int vertices) {
    Graph graph(vertices);

    for (int i = 1; i < vertices; ++i) {
        graph.addEdge(rand() % i, i, rand() % 10 + 1);
    }
    return graph;
}

/**
 * Chooses type of graph generation.
 * @param choice user's choice
 * @param vertices number of vertices in generated graph
 * @return graph object
 */
static Graph generateGraph(int choice, int vertices) {
    switch (choice) {
        case 1:
            return generateCompleteGraph(vertices);
        case 2:
            return generateConnectedGraph(vertices);
        case 3:
            return generateSparseGraph(vertices);
        default:
            return Graph(0);
    }
}