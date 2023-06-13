//
// Created by shind_wvnx on 11.06.2023.
//

#include <string>
#include <iostream>

/**
 * Read numbers from console to launch path finding.
 * @return user's parsed input
 */
static int readConsoleInput() {
    std::string input;
    int ans;
    do {
        std::cout << "Input number of shortest path finding algorithm:";
        std::getline(std::cin, input);
        try {
            ans = std::stoi(input);
        } catch (std::exception& ex) {
            ans = 0;
        }
        if (ans < 1 || ans > 5) {
            std::cout << "Incorrect input or number of algorithm, try again!\n";
        }
    } while (ans < 1 || ans > 5);
    return ans;
}

