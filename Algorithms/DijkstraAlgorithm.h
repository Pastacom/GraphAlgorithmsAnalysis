//
// Created by shind_wvnx on 11.06.2023.
//

#pragma once

#include <vector>
#include <cstdint>
#include "../Utils/GraphEntity/Graph.h"

struct DijkstraAlgorithm {
    struct Arc;

    static int64_t queueDijkstra(int start, int end, Graph& graph);

    static int64_t setDijkstra(int start, int end, Graph& graph);

private:
    static std::vector<std::vector<Arc>> getReformatedData(Graph& graph);
};

