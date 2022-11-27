#include "RouteFinder.h"
#include "utils/misc.h"
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
        if (!airports_.count(origin)){
            airports_.insert(origin);
            airport_to_int_[origin]=airports_counter++;
        }
        if (!airports_.count(dest)) {
            airports_.insert(dest);
            airport_to_int_[dest]=airports_counter++;
        }

        // insert into graph too

        

    }
}


