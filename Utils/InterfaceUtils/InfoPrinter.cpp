//
// Created by shind_wvnx on 11.06.2023.
//

#include <iostream>
#include "../GraphAlgorithmUtils/AlgorithmsInfo.cpp"

/**
 * Method to output algorithms' names.
 */
static void printAlgorithms() {
    for (int i = 1; i < 5; ++i) {
        std::cout << i << ". " + getName(i) << '\n';
    }
    std::cout << "5. Perform all algorithms." << '\n';
}

/**
 * Method to get graph type.
 * @param choice type to return
 * @return graph type
 */
static std::string getGraphType(int choice) {
    switch (choice) {
        case 1:
            return "Complete Graph";
        case 2:
            return "Connected Graph";
        case 3:
            return "Sparse Graph";
        default:
            return "";
    }
}