#include "route_length.h"
#include <cmath>


int routeLength(std::pair<int,int> loc1, std::pair<int,int> loc2){
    return 0;
//first convert both lat and long to radians, lat1,long2 and lat2,long2
//Use the formula d = 3963.0 * arccos[(sin(lat1) * sin(lat2)) + cos(lat1) * cos(lat2) * cos(long2 – long1)]
//haversine Formula

unsigned long lat1 = loc1.first/ (180/M_PI);
unsigned long long1 = loc1.second/ (180/M_PI);
unsigned long lat2 = loc2.first/ (180/M_PI);
unsigned long long2 = loc2.second/ (180/M_PI);

    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;
 
    long double ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    long double R = 6371;
     
    // Calculate the result
    ans = ans * R;
 
    return ans;

}