# CS 225 Final Project Fall 2022
Contributors: Hanpu Liu, Jake Cheng, Peter, Dekai.

## Overview

Our project uses the openflights data set from https://openflights.org/data.html to perform two main algorithms: Dijkstra and Page Rank. We first appended the airports dataset to include the flight distance at the last column. With that, we created a graph using adjacency list and implemented Breadth First Search to check if airports are connected. 


## Github Ogranisation
#### data: data sets and test data sets
#### entry: process data and main function
#### src: routefinder(construct graph, bfs and dijkstra), utils(routelength to compute length)
#### tests: test cases


## Running Instructions
1. cmake..
2. make
3. ./test
