/*
 *  АиСД-2, 2023, КДЗ-3
 *  ФИО: Шиндяпкин Илья Дмитриевич
 *  ГРУППА: БПИ219
 *  Среда разработки: CLion, 2021.3.4
 *  Сделано: реализованы 4 алгоритма поиска кратчайшего пути в графе с подсчетом времени и усреднением,
 *  есть возможность запустить любой алгоритм или все сразу, код прокомментирован,
 *  произведены вычисления, результаты записаны в csv файлы, построены графики, написан отчет.
 *  Не сделано: Нету, все сделано.
 * */

#include <iostream>
#include "Utils/InterfaceUtils/ConsoleInputReader.cpp"
#include "Utils/GraphAlgorithmUtils/AlgorithmExecutor.cpp"
int main() {
    srand(time(nullptr));
    std::string loop;
    do {
        // Generate strings and templates.
        printAlgorithms();
        // Choose path finding algorithm.
        int choice = readConsoleInput();
        chooseAlgorithm(choice);
        // Program loop.
        do {
            std::cout << "\nContinue? (y/n):";
            std::getline(std::cin, loop);
        } while (loop != "y" && loop != "n");
        std::cout << '\n';
    } while (loop == "y");
}
