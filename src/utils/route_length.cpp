#include "route_length.h"
#include <cmath>
#include <string>
#include <unordered_map>
#include <fstream>
#include "misc.h"
#include <utility>


int routeLength(std::pair<long double,long double> loc1, std::pair<long double, long double> loc2){
    
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
    long double R = 6371;
        
    a = a * R;

    return a;

}