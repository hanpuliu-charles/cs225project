#include "route_length.h"
#include <cmath>
#include <string>
#include <unordered_map>
#include <fstream>
#include "utils/misc.h"
#include <utility>
#include <iostream>

int main(){
    std::string airports_filename = "";
    std::string routes_filename = "";
    std::ifstream ifs;
    ifs.open(airports_filename);
    std::unordered_map<std::string, std::pair<long double, long double>> airportToCoord;
    std::string line;
    while(ifs>>line){
        std::vector<std::string> brokenUpString = delimitString(line,',');
        std::string airport_code = brokenUpString[4].substr(1, brokenUpString[4].length()-2);
        long double lat = std::stold(brokenUpString[6]);
        long double lon = std::stold(brokenUpString[7]);
        airportToCoord[airport_code]=std::make_pair(lat, lon);
    }

    // Now we have all coord of airports, we can go through routes list
    
    ifs.open(routes_filename);
    while(ifs>>line){
        std::vector<std::string> brokenUpString = delimitString(line,',');
        std::string origin = brokenUpString[2]; // NOTE: all airport using 3 letter IATA names in routes
        std::string dest = brokenUpString[4];
        std::cout << routeLength(airportToCoord[origin], airportToCoord[dest]) << std::endl;
        // airportToCoord[airport_code]=std::make_pair(lat, lon);
    }
}
int routeLength(std::pair<long double,long double> loc1, std::pair<long double, long double> loc2){
    return 0;
//first convert both lat and long to radians, lat1,long2 and lat2,long2
//Use the formula d = 3963.0 * arccos[(sin(lat1) * sin(lat2)) + cos(lat1) * cos(lat2) * cos(long2 – long1)]
//haversine Formula

    long double lat1 = loc1.first/ (180/M_PI);
    long double long1 = loc1.second/ (180/M_PI);
    long double lat2 = loc2.first/ (180/M_PI);
    long double long2 = loc2.second/ (180/M_PI);

    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;

    //long double a = pow(sin)
    long double a = (pow(sin(dlat / 2), 2)) + cos(lat1)*cos(lat2)*pow(sin(dlong / 2), 2);

    a = 2 * atan2(sqrt(a), sqrt(1-a));
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    long double R = 6371;
        
    // Calculate the result
    a = a * R;

    return a;

}