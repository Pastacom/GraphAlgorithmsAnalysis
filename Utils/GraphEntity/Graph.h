//
// Created by shind_wvnx on 12.06.2023.
//

#pragma once

#include <vector>
#include <cstdint>

struct Graph {
    int vertices{};
    int edges{};
    std::vector<std::vector<int64_t>> weight_matrix;

    Graph() = default;

    explicit Graph(int vertices);

    ~Graph() = default;

    void addEdge(int from, int to, int64_t weight);
};
