#pragma once
#include <string>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

// This is the main part of the project
class RouteFinder {
    public:
    RouteFinder(std::string filename);
    private:

    // We should use a string...
    // class Airport{
    //     std::string airportName_;
    //     Airport(std::string airportName):airportName_{airportName}{
    //         // dont have to do anything?
    //     }

    // };
    class Route{
        // Simplied model of a route

        // parameterized constructor
        Route(std::string airline, std::string origin, std::string dest, int dist):airline_{airline}, origin_{origin}, dest_{dest}, dist_{dist}{
            // do something??? idk
        }

        std::string airline_; // Airline code 
        std::string origin_; // Airport code
        std::string dest_; // Airport code
        int dist_;

    };
    std::unordered_map<std::string, int> airport_to_int_;
    std::unordered_set<std::string> airports_;

    std::vector<std::list<std::pair<int,int>>> adj_list_;


    
};

