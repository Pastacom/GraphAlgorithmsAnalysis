//
// Created by shind_wvnx on 11.06.2023.
//

#include "../GraphEntity/Graph.h"
#include "AlgorithmsInfo.cpp"

/**
 * Method to check whether found path cost is valid.
 * @param start vertex which is the start of the path
 * @param end vertex which is the end of the path
 * @param graph graph object
 * @param answer result to check
 * @return whether result is correct for passed parameters
 */
static bool check(int start, int end, Graph& graph, int64_t answer) {
    return answer == getAlgorithm(1)(start, end, graph);
}