#include "RouteFinder.h"
#include "utils/misc.h"
#include <utility>
#include <queue>
// constructor
RouteFinder::RouteFinder(std::string filename){
    // constructor
    std::ifstream ifs;
    ifs.open(filename);
    std::string line;
    int airports_counter = 0;
    while(ifs >> line){
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
        }
        if (!airports_.count(dest)) {
            airports_.insert(dest);
            airport_to_int_[dest]=airports_counter++;
        }

        

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
        // mark as visited
        visited.insert(cur);
        // visit cur in adj list and enqueue its neighbors
        std::list<std::pair<int,int>>::iterator iter = adj_list_[cur].begin();
        while(iter != adj_list_[cur].end()){
            int newnode = iter->first;
            q.push(newnode);
            if (newnode == destNumber) {
                // we found it
                return true;
            }
        }
    }

    return false;
}
int RouteFinder::shortestPath(std::string origin, std::string dest){
    // TODO
    int originNumber = airport_to_int_[origin];
    int destNumber = airport_to_int_[dest];

    // Initialize data structure with MAX INT for unconnected?

    return -1; // Not connected;
}

// What sort of data do we want to output for 


