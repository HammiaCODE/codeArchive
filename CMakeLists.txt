cmake_minimum_required(VERSION 3.28)
project(projectSFML)

set(CMAKE_CXX_STANDARD 17)

# Set the path to your SFML installation
set(SFML_DIR "C:/Users/hanes/Desktop/SFML-2.6.2-windows-gcc-13.1.0-mingw-64-bit (1)/SFML-2.6.2/lib/cmake/SFML") # Replace with your actual SFML path

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Add your executable
add_executable(projectSFML main.cpp
        BubbleSort.h
        binarySearch.h
        linearSearch.h
        selectionSort.h
        insertionSort.h
        mergeSort.h
        quickSort.h
        stack.h
        queues.h
        linkedLists.h
        AVL.h
        DFS.h
        BFS.h
        DIJKSTRA.h)

# Link SFML libraries
target_link_libraries(projectSFML sfml-system sfml-window sfml-graphics)