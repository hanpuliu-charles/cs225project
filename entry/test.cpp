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
    RouteFinder R("../data/testroutes.dat");
    std::cout << R.isConnectedBFS("AAA", "BBB") <<std::endl; // should be true
    std::cout << R.isConnectedBFS("AAA", "EEE") <<std::endl; // should be false
    std::cout << R.isConnectedBFS("EEE", "DDD") <<std::endl; // should be false, directed graph
    std::cout << R.isConnectedBFS("DDD", "EEE") <<std::endl; // should be true, directed graph

    std::cout << "Testing Shortest Path, expected 20" << std::endl;
    std::cout << R.shortestPath("AAA", "CCC").first << std::endl;
    for (std::string a : R.shortestPath("AAA", "CCC").second) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    std::cout << "Testing Shortest Path unconnected" << std::endl;
    // std::cout << R.shortestPath("AAA", "DDD") << std::endl;


    //More testing on Dijkstra
    RouteFinder D("../data/dijtest.dat");
    std::cout << "Testing Dijkstra 1"<< std::endl;
    std::cout << D.shortestPath("DDD", "AAA").first << std::endl; //should be 20 and D,E,C,A
    for (std::string a : D.shortestPath("DDD", "AAA").second) {
        std::cout << a << " ";
    }

    std::cout << "Testing Dijkstra 2"<< std::endl;
    std::cout << D.shortestPath("BBB", "AAA").first << std::endl; //should be 20 and B,C,A
    for (std::string a : D.shortestPath("BBB", "AAA").second) {
        std::cout << a << " ";
    }

//Testing on Page rank
    RouteFinder P("../data/pageranktest.dat");
    std::cout << "Testing Page Rank 1"<< std::endl;
    for (std::string a : P.mostPopularAirport(1)){
    std::cout << a << " "<< std::endl; //should be A 
    }

    std::cout << "Testing Page Rank 2"<< std::endl;
    for (std::string a : P.mostPopularAirport(2)){
    std::cout << a << " "<< std::endl; //should be A , B
    }



}
