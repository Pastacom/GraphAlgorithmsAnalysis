//
// Created by shind_wvnx on 11.06.2023.
//

#pragma once

#include <cstdint>
#include <vector>
#include "../Utils/GraphEntity/Graph.h"

struct FloydWarshallAlgorithm {

    static int64_t floydWarshall(int start, int end, Graph& graph);

private:
    static std::vector<std::vector<int64_t>> getReformatedData(Graph& graph);
};


