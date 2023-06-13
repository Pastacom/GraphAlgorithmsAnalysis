//
// Created by shind_wvnx on 11.06.2023.
//
#include <map>
#include <string>
#include <vector>
#include <fstream>

/**
 * Write registered data to csv file.
 * @param data average time for different options
 */
static void writeResults(std::map<std::string, std::vector<int64_t>> data) {
    std::ofstream stream("RawData.csv");
    for (auto [key, value] : data) {
        stream << key << ';';
    }
    stream << '\n';
    int i = 0;
    while (i < data["Vertices number"].size()) {
        for (auto [key, value] : data) {
            stream << data[key][i] << ';';
        }
        stream << '\n';
        ++i;
    }
    stream.close();

}