# CS 225 Final Project Report Fall 2022 
Contributors: Hanpu Liu, Jake Cheng, Peter, Dekai.

## Overview

Our project uses the openflights data set from https://openflights.org/data.html to perform two main algorithms: Dijkstra and Page Rank. We first appended the airports dataset to include the flight distance at the last column. With that, we created a graph using adjacency list and implemented Breadth First Search to check if airports are connected. 


## Breadth-First Search
We chose to use BFS to traverse each of the airport to find whether two airports are connected and wrote certain test cases to test whether this function work
The file testroutes.dat is used as a make-shift test data to test whether two airports are connected. In this dataset, we provided five airports, AAA, BBB, CCC, DDD, EEE as shown below. The first three are connected, and the last two are connected. We test to find the shortest Path between AAA and DDD, which means the outputs should be false.


![BFS](BFS.jpg)

## Dijkstra


## Page Rank

## Linking back to our leading question
