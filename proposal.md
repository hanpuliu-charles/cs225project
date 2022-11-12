## Leading Question
Provided two cities, we hope to find the shortest route between these 2 cities. We will make use of airports dataset's to compute distance between airports to use as weights in the graph. Nodes will be Airports while edges will indicate connected cities using data from routes dataset. We will also add in functions to check reachability and ability to output a list of all reachable airports from a source airport. Lastly, we will make use of pagerank rankings, to calculate the relative importance of each airport with regards to the number of unique flight destinations each airport has direct connections to.

## Dataset Acquisition
We will be using data from the datasets provided from openflights.org



## Data Format
We will use 2 dataset, the routes dataset and the airports dataset.
The data formats will be in csv files, without a headers line. This data is from openflights.org. This dataset of the number of routes between airports contains roughly 3321 airports and 67663 routes. The airports dataset contains information of over 10000 airports. Currently we are planning to use the entire route dataset, but if we run into problems with running time, we will look at reducing the dataset. We will need to trim the airports data set, to contain only airports that are present in the routes dataset. This will reduce our dataset size as the other airports are irrelevant for the purpose of this project.  


## Data Correction  
To check for correctness, we will look through the dataset and check for incomplete entries. We will remove such entries from the dataset as they are not able to be corrected. We will need to preprocess the airports data to remove airports that are not present in the route database. We will also skim through for obvious missing entries and remove them, such as routes with only one endpoint.


## Data Storage
We will use an adjacency list to store the graph, as it gives good runtime overall except when computing are adjacent. The storage cost in terms of n(number of airports) and m(number of flight path) is O(n+m). In the initialization we will preprocess the data, and calculate the distance between airports, using their latitude and longitude information stored. We will first load the airport file data into an array to facilitate retrieval of latitude and longitude data, while using a helper function to compute distance between endpoints of a route when building the graph. After building the graph, we will have no need for this airports 2D array, and we can clear it. Alternatively we are thinking of preprocessing the routes dataset with one more feature, which is the weight of the route(distance). We can write a helper program to compute and append this and it will reduce future runtime of the program as this is only computed once.

However, pagerank is typically implemented using an adjacency matrix(as it represents a transition matrix in a Markov chain). Therefore we will also need to store a copy of the graph as an adjacency matrix to speed up our pagerank runtime.

## Algorithm
As described above, we will do some preprocessing, such as appending a distance to each route in the distance dataset, which allow us to build a graph from the routes dataset. (Distance calculation requires the airports dataset to get the coordinates of each airport from their airport code). The expected output for the shortest path algorithm will be a vector containing the shortest route distance from a starting point to all other nodes in the graph. We can extract out only the airport that the user is interested in to print it out. The expected result of the pagerank algorithm is a vector containing the perceived importance score of each airport, as a probability vector. This means that all entries will sum up to one.   
  
Dijkstra algorithm: To help us find the shortest route between two airports, we have decided to use Dijkstra's algorithm. Our input would be the starting airport node and destination airport node. And lastly the output should be the shortest route between these cities. Time complexity target for this is O(mlogm+nlogm), using a priorityqueue(min heap based) and a adjacency list representation of the graph. Memory should be dominated by the graph storage O(n+m). Other than this, we also need to store the priority queue, and a vector of minimum path length, and these should be a constant multiple of O(n) so overall space complexity is still O(n+m).  
  
Pagerank algorithm: Famously known as the algorithm that started the Google search engine, pagerank algorithm can tell us how popular an airport is by the number of flights going in and out of the airport(we will consider unique destinations instead). For the transition matrix, we do not have to consider an airport with no connections as we have only kept airports that were included in the routes dataset, which means they have at least one route. We can output the airport code of each airport together with its relative importance. We will target a runtime between O(nm) and O(n+m) where n is the number of airports and m is the number of flights, but it depends on the convergence of the power iteration method to find the steady state vector(pagerank vector). In terms of memory, we will target O(n^2) as we will have to store the adjacency matrix just for computing the pagerank.  
  
BFS: We can make use of BFS algorithm to check if 2 given airports are connected(able to be reached). As an extension, we can check if 2 airports can be reached within k hops, where k is also a user input. Since BFS is a traversal, we will take O(n) time to run it, as we will not traverse to explored nodes. Memory complexity should be just dominated by the storage of the graph, which is O(n+m).  



## Timeline
Week 0: 10/31 - 11/06: Completion of Team Contract, Project Proposal, setting up of Github  
Week 1: 11/07 - 11/13: Finalize how we are going to implement our project and start working on code  
Week 2: 11/14 - 11/20: Finish up Code  
Week 3: 11/21 - 11/27: Test code  
Week 4: 11/28 - 12/04: Finish up Project