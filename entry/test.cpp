#include "RouteFinder.h"
#include <iostream>
// int main(int argc, char **argv){
//     RouteFinder R("../data/testroutes.dat");
//     std::cout << R.isConnectedBFS("AAA", "BBB") <<std::endl; // should be true
//     std::cout << R.isConnectedBFS("AAA", "EEE") <<std::endl; // should be false
//     std::cout << R.isConnectedBFS("EEE", "DDD") <<std::endl; // should be false, directed graph
//     std::cout << R.isConnectedBFS("DDD", "EEE") <<std::endl; // should be true, directed graph

//     std::cout << "Testing Shortest Path, expected 20" << std::endl;
//     std::cout << R.shortestPath("AAA", "CCC").first << std::endl;
//     for (std::string a : R.shortestPath("AAA", "CCC").second) {
//         std::cout << a << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "Testing Shortest Path unconnected" << std::endl;
//     std::cout << R.shortestPath("AAA", "DDD").first << std::endl;
// }

// Test with real data
int main(int argc, char **argv){
    RouteFinder R("../data/routes_raw.dat");
    // std::cout << R.isConnectedBFS("AAA", "BBB") <<std::endl; // should be true
    // std::cout << R.isConnectedBFS("AAA", "EEE") <<std::endl; // should be false
    // std::cout << R.isConnectedBFS("EEE", "DDD") <<std::endl; // should be false, directed graph
    // std::cout << R.isConnectedBFS("DDD", "EEE") <<std::endl; // should be true, directed graph

    // std::cout << "Testing Shortest Path, expected 20" << std::endl;
    // std::cout << R.shortestPath("AAA", "CCC").first << std::endl;
    // for (std::string a : R.shortestPath("AAA", "CCC").second) {
    //     std::cout << a << " ";
    // }
    // std::cout << std::endl;

    std::cout << "Testing Shortest Path unconnected" << std::endl;
    std::cout << R.shortestPath("AAA", "DDD") << std::endl;


    //More testing on Dijkstra
    RouteFinder D("../data/dijtest.dat");
    std::cout << "Testing Dijkstra"<< std::endl;\
    std::cout << D.shortestPath("DDD", "AAA") << std::endl; //should be 20 and D,E,C,A
    std::cout << D.shortestPath("BBB", "AAA") << std::endl; //should be 20 and B,C,A

    RouteFinder P("../data/pageranktest.dat");
    std::cout << "Testing Page Rank"<< std::endl;\
    std::cout << P.mostPopularAirport(1) << std::endl; //should be A 
    std::cout << P.mostPopularAirport(2) << std::endl; //should be A, B



}
