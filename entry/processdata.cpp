#include <string>
#include <vector>
#include "../src/utils/route_length.h"
#include "../src/utils/misc.h"
#include <unordered_map>
#include <utility>
#include <iostream>
#include <fstream>

int main(){
    std::string airports_filename = "../data/airports_raw.dat";
    std::string routes_filename = "../data/routes_raw.dat";
    std::ifstream ifs;
    ifs.open(airports_filename);
    std::unordered_map<std::string, std::pair<long double, long double>> airportToCoord;
    std::string line;
    while(std::getline(ifs,line)){
        std::vector<std::string> brokenUpString = delimitString(line,',');
        
        // if (brokenUpString.size() < 7) {
        //     std::cout << brokenUpString[0] << std::endl;
        // }
        std::string airport_code = brokenUpString[4];//.substr(1, brokenUpString[4].length()-2);
        if (airport_code == "\\N") {
            continue;
        }
        // std::cout << "LINE " << brokenUpString[0] << std::endl;
        // if (brokenUpString[0]=="641") {
        //     for (std::string w : brokenUpString) {
        //         std::cout << w << std::endl;
        //     }
        // }
        // std::cout << brokenUpString[6] << std::endl;
        // std::cout << brokenUpString[7] << std::endl;
        long double lat = std::stold(brokenUpString[6]);
        long double lon = std::stold(brokenUpString[7]);
        airportToCoord[airport_code]=std::make_pair(lat, lon);
        // std::cout << "airport code " << airport_code << std::endl;
    }
    // std::cout << airportToCoord.size();
    
    // Now we have all coord of airports, we can go through routes list
    ifs.close();
    ifs.open(routes_filename);  
    while(std::getline(ifs,line)){
        // std::cout << 1 << std::endl;
        std::vector<std::string> brokenUpString = delimitString(line,',');
        std::string origin = brokenUpString[2]; // NOTE: all airport using 3 letter IATA names in routes

        std::string dest = brokenUpString[4];
        std::cout << "origin " << airportToCoord[origin].first << " " << airportToCoord[origin].second << " dest " << airportToCoord[dest].first << " " << airportToCoord[dest].second << std::endl;
        std::cout << routeLength(airportToCoord[origin], airportToCoord[dest]) << std::endl;
        // airportToCoord[airport_code]=std::make_pair(lat, lon);
    }
}