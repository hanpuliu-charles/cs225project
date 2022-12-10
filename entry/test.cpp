#include "RouteFinder.h"
#include <iostream>
int main(int argc, char **argv){
    RouteFinder R("../data/testroutes.dat");
    std::cout << R.isConnectedBFS("AAA", "BBB") <<std::endl; // should be true
    std::cout << R.isConnectedBFS("AAA", "EEE") <<std::endl; // should be false
    std::cout << R.isConnectedBFS("EEE", "DDD") <<std::endl; // should be false, directed graph
    std::cout << R.isConnectedBFS("DDD", "EEE") <<std::endl; // should be true, directed graph

    std::cout << "Testing Shortest Path, expected 20" << std::endl;
    std::cout << R.shortestPath("AAA", "CCC") << std::endl;

    std::cout << "Testing Shortest Path unconnected" << std::endl;
    std::cout << R.shortestPath("AAA", "DDD") << std::endl;


    //More testing on Dijkstra
    RouteFinder D("../data/dijtest.dat");
    std::cout << "Testing Dijkstra"<< std::endl;\
    std::cout << D.shortestPath("DDD", "AAA") << std::endl; //should be 20 and D,E,C,A
}