# CS 225 Final Project Fall 2022
Contributors: Hanpu Liu, Jake Cheng, Peter, Dekai.

## Overview

Our project uses the openflights data set from https://openflights.org/data.html to perform two main algorithms: Dijkstra and Page Rank. We first appended the airports dataset to include the flight distance at the last column. With that, we created a graph using adjacency list and implemented Breadth First Search to check if airports are connected. 


## Github Respository Organization
#### data: data sets and test data sets (default processed routes dataset is named processed_routes.dat)
#### entry: processdata.cpp to process data, main.cpp as main entry point, test.cpp as tests for correctness
#### src: routefinder(Class that represents the data, construct graph, BFS and Dijkstra, PageRank are all functions in routefinder), utils(routelength.h to compute length, misc.cpp contains functions such as string parsing)


## Running Instructions
1. Clone the repository
2. Make a build directory in the main project folder
3. Run ```cmake ..``` in the build directory to generate the makefiles
4. Run ```make``` to make all entry points, or ```make main```/```make test```/```make processdata``` to make the individual entrypoints
