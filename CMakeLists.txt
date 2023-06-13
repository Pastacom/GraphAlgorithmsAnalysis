cmake_minimum_required(VERSION 3.21)
project(GraphAlgorithmsAnalysis)

set(CMAKE_CXX_STANDARD 20)

add_executable(GraphAlgorithmsAnalysis main.cpp Algorithms/DijkstraAlgorithm.cpp Algorithms/DijkstraAlgorithm.h Algorithms/BellmanFordAlgorithm.cpp Algorithms/BellmanFordAlgorithm.h Algorithms/FloydWarshallAlgorithm.cpp Algorithms/FloydWarshallAlgorithm.h Utils/GraphAlgorithmUtils/AlgorithmsInfo.cpp Utils/GraphAlgorithmUtils/GraphGenerator.cpp Utils/GraphAlgorithmUtils/AlgorithmExecutor.cpp Utils/FileUtils/CSVWriter.cpp Utils/InterfaceUtils/ConsoleInputReader.cpp Utils/InterfaceUtils/InfoPrinter.cpp Utils/TimeUtils/TimerGuard.cpp Utils/TimeUtils/TimerGuard.h  Utils/GraphAlgorithmUtils/ResultChecker.cpp Utils/GraphEntity/Graph.cpp Utils/GraphEntity/Graph.h)
