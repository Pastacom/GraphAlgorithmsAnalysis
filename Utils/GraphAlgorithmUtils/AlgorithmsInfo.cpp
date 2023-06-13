//
// Created by shind_wvnx on 11.06.2023.
//
#pragma once

#include <map>
#include <functional>
#include <string>
#include "../../Algorithms/DijkstraAlgorithm.h"
#include "../../Algorithms/BellmanFordAlgorithm.h"
#include "../../Algorithms/FloydWarshallAlgorithm.h"

typedef std::function <int64_t(int, int, Graph&)> function;

// Algorithms data
static std::map<int, std::pair<function, std::string>>
algorithmsData {
{1, std::make_pair(DijkstraAlgorithm::setDijkstra,
                   "Set based dijkstra's algorithm")},
{2, std::make_pair(DijkstraAlgorithm::queueDijkstra,
                   "Queue based dijkstra's algorithm")},
{3, std::make_pair(BellmanFordAlgorithm::bellmanFord,
                   "Bellman-Ford algorithm")},
{4, std::make_pair(FloydWarshallAlgorithm::floydWarshall,
                   "Floyd-Warshall algorithm")}
};

/**
 * Return path finding algorithm.
 * @param choice id of algorithm in data map
 * @return path finding algorithm
 */
static function getAlgorithm(int choice) {
    return algorithmsData[choice].first;
}
/**
 * Get string representation of path finding algorithm.
 * @param choice id of algorithm in data map
 * @return algorithm's name
 */
static std::string getName(int choice) {
    return algorithmsData[choice].second;
}