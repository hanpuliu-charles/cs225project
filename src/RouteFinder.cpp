#include "RouteFinder.h"
#include "utils/misc.h"
#include <utility>
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
    return false;
}
int RouteFinder::shortestPath(std::string origin, std::string dest){
    return -1;
}


