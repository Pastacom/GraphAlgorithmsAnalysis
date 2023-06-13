//
// Created by shind_wvnx on 11.06.2023.
//

#include <map>
#include <vector>
#include "../TimeUtils/TimerGuard.h"
#include "GraphGenerator.cpp"
#include "ResultChecker.cpp"
#include "../InterfaceUtils/InfoPrinter.cpp"
#include "../FileUtils/CSVWriter.cpp"

// Average time for different options.
static std::map<std::string, std::vector<int64_t>> time_data;

/**
 * Method to prepare keys in map before putting time results.
 * @param i graph type
 */
static void prepareMaps(int i) {
    for (int j = 1; j < 4; ++j) {
        std::string name = getName(i) + " " + getGraphType(j);
        time_data.insert(std::make_pair(name, std::vector<int64_t>()));
    }
}

/**
 * Method to prepare vector sizes in measurements data.
 */

static void prepareSizes() {
    time_data.insert(std::make_pair("Vertices number", std::vector<int64_t>()));
    for (int i = 10; i <= 1010; i += 50) {
        time_data["Vertices number"].push_back(i);
    }

    for (int j = 1; j < 4; ++j) {
        std::string name = getGraphType(j) + " edges number";
        time_data.insert(std::make_pair(name, std::vector<int64_t>()));
    }
}

/**
 * Method to perform path finding algorithm and register average time.
 * @param algorithm finding algorithm
 * @param name table name
 * @param start vertex which is the start of the path
 * @param end vertex which is the end of the path
 * @param graph graph object
 */
static void runAlgorithm(const function& algorithm, const std::string& name, int start, int end, Graph& graph) {
    std::chrono::duration<double> total = std::chrono::duration<double>::zero();
    // Averaging finding time
    int64_t cost;
    for (int i = 0; i < 5; ++i) {
        {
            TimerGuard timer(&total);
            // Performing algorithm.
            cost = algorithm(start, end, graph);
        }
        // TimerGuard destructor triggered and time is added to total value.
    }

    // Compute average value.
    int64_t result = std::chrono::duration_cast<std::chrono::nanoseconds>(total / 5.0).count();
    std::cout << "Time for path finding elapsed: " << result << " nanoseconds\n";
    std::cout << '[' << (check(start, end, graph, cost) ? "Correct" : "Incorrect") << "] ";
    std::cout << "Minimal path cost: " << cost << '\n';
    time_data[name].push_back(result);
}

/**
 * Method to iterate over different options of graph type, algorithms and measure elapsed time.
 * @param algorithms path finding algorithms to launch
 */
static void algorithmIterator(const std::vector<std::pair<function, int>>& algorithms) {
    for (int i = 10; i <= 1010; i += 50) {
        for (int j = 1; j < 4; ++j) {
            std::string type = getGraphType(j);
            Graph graph = generateGraph(j, i);
            std::cout << "=========================================================";
            std::cout << '\n' << type << " | vertices = " << graph.vertices <<
            " | edges = " << graph.edges  << '\n';
            std::cout << "=========================================================\n";
            int start = rand() % graph.vertices;
            int end;
            do {
                end = rand() % graph.vertices;
            } while (end == start);
            for (auto [algorithm, id] : algorithms) {
                std::cout << '\n' << getName(id) << '\n';
                runAlgorithm(algorithm, getName(id) + " " + getGraphType(j), start, end, graph);
            }
            std::cout << '\n';
            time_data[getGraphType(j) + " edges number"].push_back(graph.edges);
        }
    }
}

/**
 * Method to choose algorithms to perform path finding.
 * @param choice user's choice
 */
static void chooseAlgorithm(int choice) {

    prepareSizes();
    std::vector<std::pair<function, int>> algorithms;
    if (choice == 5) {
        // Perform all algorithms.
        for (int i = 1; i <= 4; ++i) {
            algorithms.emplace_back(getAlgorithm(i), i);
            prepareMaps(i);
        }
    } else {
        // Single option.
        algorithms.emplace_back(getAlgorithm(choice), choice);
        prepareMaps(choice);
    }
    algorithmIterator(algorithms);
    writeResults(time_data);
    // Clearing data.
    time_data.clear();
}