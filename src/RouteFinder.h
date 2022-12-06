#pragma once
#include <string>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>

// This is the main part of the project
class RouteFinder {
    public:
    RouteFinder(std::string filename);
    bool isConnectedBFS(std::string origin, std::string dest);
    int shortestPath(std::string origin, std::string dest);
    
    private:

    // We should use a string...
    // class Airport{
    //     std::string airportName_;
    //     Airport(std::string airportName):airportName_{airportName}{
    //         // dont have to do anything?
    //     }

    // };

    // Haven't used it
    // class Route{
    //     // Simplied model of a route

    //     // parameterized constructor
    //     Route(std::string airline, std::string origin, std::string dest, int dist):airline_{airline}, origin_{origin}, dest_{dest}, dist_{dist}{
    //         // do something??? idk
    //     }

    //     std::string airline_; // Airline code 
    //     std::string origin_; // Airport code
    //     std::string dest_; // Airport code
    //     int dist_;

    // };
    std::unordered_map<std::string, int> airport_to_int_;
    std::unordered_set<std::string> airports_;
    std::unordered_map<int, std::string> int_to_airport_;

    //first value is airport number, second value is distance
    std::vector<std::list<std::pair<int,int>>> adj_list_;

    
    
};

