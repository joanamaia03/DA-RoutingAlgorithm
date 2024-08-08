cmake_minimum_required(VERSION 3.10)

project(DA_Project)

include_directories(src)

set(SOURCE
main.cpp
menu.cpp
menu.h
data_structures/Graph.cpp
data_structures/Graph.h
data_structures/components.cpp
data_structures/components.h
data_structures/reader.cpp
data_structures/reader.h
data_structures/MutablePriorityQueue.h
menu.cpp
menu.h
)

add_executable(${PROJECT_NAME} ${SOURCE})

add_definitions("-g")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)