//
// Created by shind_wvnx on 11.06.2023.
//

#pragma once

#include <cstdint>
#include <vector>
#include "../Utils/GraphEntity/Graph.h"

struct BellmanFordAlgorithm {

    struct Arc;

    static int64_t bellmanFord(int start, int end, Graph& graph);

private:
    static std::vector<Arc> getReformatedData(Graph& graph);
};


