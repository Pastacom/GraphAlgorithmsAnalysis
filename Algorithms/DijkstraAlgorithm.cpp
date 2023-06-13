//
// Created by shind_wvnx on 11.06.2023.
//

#include <queue>
#include <set>
#include "DijkstraAlgorithm.h"

/**
 * Struct to store arcs' destination and weight in graph for Dijkstra algorithm.
 */
struct DijkstraAlgorithm::Arc {
public:
    int destination;
    int64_t weight;

    Arc() = default;

    Arc(int destination, int64_t weight) {
        this->destination = destination;
        this->weight = weight;
    }
};

/**
 * Perform Dijkstra algorithm based on priority queue to find path with minimal cost.
 * @param start vertex which is the start of the path
 * @param end vertex which is the end of the path
 * @param graph graph object
 * @return path with minimal cost from start to end
 */
int64_t DijkstraAlgorithm::queueDijkstra(int start, int end, Graph& graph) {
    std::vector<std::vector<Arc>> arcs = getReformatedData(graph);
    std::vector<int64_t> result(graph.vertices, INT64_MAX);
    std::priority_queue<std::pair<int64_t, int>> queue;
    result[start] = 0;
    queue.emplace(0, start);
    while (!queue.empty()) {
        int vertex = queue.top().second;
        int64_t distance = -queue.top().first;
        queue.pop();
        if (distance <= result[vertex]) {
            for (Arc& arc : arcs[vertex]) {
                if (result[vertex] + arc.weight < result[arc.destination]) {
                    result[arc.destination] = result[vertex] + arc.weight;
                    queue.emplace(-result[arc.destination], arc.destination);
                }
            }
        }
    }
    return result[end];
}

/**
 * Perform Dijkstra algorithm based on set to find path with minimal cost.
 * @param start vertex which is the start of the path
 * @param end vertex which is the end of the path
 * @param graph graph object
 * @return path with minimal cost from start to end
 */
int64_t DijkstraAlgorithm::setDijkstra(int start, int end, Graph& graph) {
    std::vector<std::vector<Arc>> arcs = getReformatedData(graph);
    std::vector<int64_t> result(graph.vertices, INT64_MAX);
    std::set<std::pair<int64_t, int>> set;
    result[start] = 0;
    set.emplace(0, start);
    while (!set.empty()) {
        int vertex = set.begin()->second;
        set.erase(set.begin());
        for (Arc& arc : arcs[vertex]) {
            if (result[vertex] + arc.weight < result[arc.destination]) {
                set.erase(std::make_pair(result[arc.destination], arc.destination));
                result[arc.destination] = result[vertex] + arc.weight;
                set.emplace(result[arc.destination], arc.destination);
            }
        }
    }
    return result[end];
}

/**
 * Reformats graph into structure used in the implementation of Dijkstra algorithm.
 * @param graph  graph object
 * @return graph representation for Dijkstra algorithm
 */
std::vector<std::vector<DijkstraAlgorithm::Arc>> DijkstraAlgorithm::getReformatedData(Graph &graph) {
    int n = graph.vertices;
    std::vector<std::vector<Arc>> arcs(n);
    auto& matrix = graph.weight_matrix;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0) {
                arcs[i].emplace_back(j, matrix[i][j]);
            }
        }
    }
    return arcs;
}