# CS 225 Final Project Report Fall 2022 
Contributors: Hanpu Liu, Jake Cheng, Peter, Dekai.

## Overview

Our project uses the openflights data set from https://openflights.org/data.html to perform two main algorithms: Dijkstra and Page Rank. We first appended the airports dataset to include the flight distance at the last column. With that, we created a graph using adjacency list and implemented Breadth First Search to check if airports are connected. 


## Breadth-First Search
We chose to use BFS to traverse each of the airport to find whether two airports are connected and wrote certain test cases to test whether this function work
The file testroutes.dat is used as a make-shift test data to test whether two airports are connected. In this dataset, we provided five airports, AAA, BBB, CCC, DDD, EEE as shown below. The first three are connected, and the last two are connected. We test to find the shortest Path between AAA and DDD, which means the outputs should be false. Firstly, we test it with our own test case with the graph as shown below:


![BFS](BFS.jpg)

<br>


And these are the test cases:

![BFS Full Scale Run](image.png) <br>

This is the output we got and it is correct.
![BFS Full Scale Run](bfs3.jpg) <br>

## Dijkstra
The Dijkstra Algorithm is chosen to find the shortest path between 2 airports and returns a pair of <shortestDistance, vector of intermediate airports>. To do this, we first use a priority queue to update the shortest distance and while doing it, we use a backtracking algorithm to store the previous airports.
<br>
First, we test it with our own test cases with this graph:
<br>
![DIJ](dijk.jpg)
<br>
The first test case is testing the path from DDD to AAA. The actual output should be DDD CCC EEE AAA <br>
The second test case is testing the path from BBB to AAA. The actual output should be BBB CCC AAA <br>
![test DIJ](testdij.jpg) <br>

Lastly, we test it with the real dataset. For this, we gave our input origin airport as sin (Singapore) to lax (Los Angeles), the return output is:
![test DIJ](dij3.jpg) <br>
With Singaporean teammates on our team, we can in fact attest to this that this is the shortest path. In fact, one of them is flying back to Singapore this winter via this path!




## Page Rank
The Page Rank Algorithm is chosen to find a vector containing first n popular airports, given a number n. The Page Rank is first done by normalizing the adjacency matrix of the gragh and then we iterarate through the matrix. After numerous attempts, we found out that the Page Rank Matrix of the dataset converge after 280 iterations.

First, we test it with our own test cases with this graph: <br>
![test pagerank](pagerank.jpg) <br>
Clearly, if given 1 or 2, the actual output would be AAA and AAA BBB respectively as seen: <br>
![test pagerank](pagerank2.jpg) <br>

Lastly, testing with the actual output and listing out the first 10 most popular airports: <br>
![test DIJ](pagerank3.jpg)


## Linking back to our leading question
We answered our question to find the shortest path as explained in our Dijkstra and shortestPath Algorithm <br>
To end our project off, we would like to point out an interesting finding. The world's busiest airport is Atlantla International Airport! It is not in Chicago, nor New York, nor San Francisco but Atlantla! According to data collected by Hartsfield-Jackson Airport, Atlanta is located within a two-hour flight of 80% of the US population, making the city a major port of entry into the US and a logical stopover for travel within the expansive country.

