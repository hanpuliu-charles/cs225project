#include "RouteFinder.h"
#include "utils/misc.h"
#include <utility>
#include <queue>
#include <functional>
#include <iostream>
#include <limits>

// constructor
RouteFinder::RouteFinder(std::string filename){
    // constructor
    std::ifstream ifs;
    ifs.open(filename);
    std::string line;
    int airports_counter = 0;
    while(std::getline(ifs, line)){
        // Do something
        std::vector<std::string> delimitedString = delimitString(line, ',');
        std::string origin = delimitedString[2]; // NOTE: all airport using 3 letter IATA names in routes
        std::string dest = delimitedString[4];
        std::string airline = delimitedString[0];
        int dist = std::stoi(delimitedString[9]);
        // I want to use airport class, but the routes file only provide the IATA code for the airport so its pointless to create a another class.
        if (!airports_.count(origin)){
            airports_.insert(origin);
            airport_to_int_[origin]=airports_counter++;
            // We also need to add one entry in adj_list vector
            adj_list_.push_back(std::list<std::pair<int,int>>());
        }
        if (!airports_.count(dest)) {
            airports_.insert(dest);
            airport_to_int_[dest]=airports_counter++;
            adj_list_.push_back(std::list<std::pair<int,int>>());
        }

        
        std::cout << origin << " " << dest << " " << dist << std::endl;
        // insert into graph too
        adj_list_[airport_to_int_[origin]].push_front(std::make_pair(airport_to_int_[dest], dist));
        

    }
}
bool RouteFinder::isConnectedBFS(std::string origin, std::string dest){
    // TODO
    std::unordered_set<int> visited;
    std::queue<int> q;
    int destNumber = airport_to_int_[dest];
    // enqueue origin
    q.push(airport_to_int_[origin]);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if (visited.count(cur) == 1){
            continue;
        }
        // std::cout << "currently processing node " << cur << std::endl;
        // mark as visited
        visited.insert(cur);
        // visit cur in adj list and enqueue its neighbors
        std::list<std::pair<int,int>>::iterator iter = adj_list_[cur].begin();
        while(iter != adj_list_[cur].end()){
            // std::cout
            int newnode = iter->first;
            q.push(newnode);
            if (newnode == destNumber) {
                // we found it
                return true;
            }
            iter++;
        }
    }

    return false;
}

// Should we change to output pair<int, vector<string>>, int is the length and vector contains all airports from start to end of the shortest path?
int RouteFinder::shortestPath(std::string origin, std::string dest){
    // TODO
    int originNumber = airport_to_int_[origin];
    int destNumber = airport_to_int_[dest];
    std::vector<int> distances(adj_list_.size(), std::numeric_limits<int>::max()); // Replace with max int
    std::vector<int> previousAirport(adj_list_.size(), -1);
    
    // Initialize data structure with MAX INT for unconnected?

    // create priority Queue pQ
    auto cmp = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
    {
    return lhs.second > rhs.second;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pQ(cmp);


    // pQ.push(adj_list_[originNumber].front());  //Incorrect
    pQ.push(std::make_pair(originNumber, 0));
    distances[originNumber] = 0;

    while(!pQ.empty()){
        int cur = pQ.top().first;
        pQ.pop();
        std::cout << "Dijkstra" << cur << std::endl;
        
        for (std::list<std::pair<int,int>>::iterator it = adj_list_[cur].begin(); it != adj_list_[cur].end(); it++){
            int v = it->first;
            int dist = it->second;

            // only consider this if 
            if (distances[v]> distances[cur] + dist){
                distances[v] = distances[cur] + dist;
                pQ.push(std::make_pair(v,distances[v])); // Should be decrease priority?


                // Update node before
                // previousAirport...
                previousAirport[v] = cur; // Update the previous airport of v for shortest path

            }
        }
    }
    

    //std::priority_queue minq2(adj_list_[originNumber].begin(), adj_list_[destNumber].end(), std::greater<int>());
    return distances[destNumber]; // Not connected;
}

// What sort of data do we want to output for 


