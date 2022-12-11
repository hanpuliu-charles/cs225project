#include "RouteFinder.h"
#include <iostream>
int main(int argc, char **argv){
    // Entry point for main function
    std::string filepath;
    std::cout << "Please input the file path relative to current working directory, enter default for default" << std::endl;
    std::cin>>filepath;
    if (filepath == "default"){
        filepath = "../data/processed_routes.dat";
    }
    RouteFinder r(filepath);
    while(true){
        std::string input;
        do{
            std::cout << "Options: Press CTRL+C to exit" << std::endl;
            std::cout << "1: Find if 2 airports are connected using BFS" << std::endl;
            std::cout << "2: Find the shortest path between 2 airports" << std::endl;
            std::cout << "3: Find the N most popular airports using PageRank" << std::endl;
            std::cin >> input;
        } while (input != "1" && input != "2" && input != "3");
        // std::cout << "OUT" << std::endl;
        if (input == "1"){
            std::string origin;
            std::string dest;
            do{
                std::cout << "Please input the origin airport code" << std::endl;
                // std::cout << "1: Find if 2 airports are connected using BFS" << std::endl;
                std::cin >> origin;
                
                for (auto & c: origin) c = toupper(c);
            } while(origin.length() != 3);
            do{
                std::cout << "Please input the destination airport code" << std::endl;
                // std::cout << "1: Find if 2 airports are connected using BFS" << std::endl;
                std::cin >> dest;
                
                for (auto & c: dest) c = toupper(c);
            } while(dest.length() != 3);
            if (r.isConnectedBFS(origin,dest)){
                std::cout << "They are connected!" << std::endl;
            } else{
                std::cout << "They are not connected!" << std::endl;
            }
        }    
        if (input == "2"){
            
            std::string origin;
            std::string dest;
            do{
                std::cout << "Please input the origin airport code" << std::endl;
                // std::cout << "1: Find if 2 airports are connected using BFS" << std::endl;
                std::cin >> origin;
                
                for (auto & c: origin) c = toupper(c);
            } while(origin.length() != 3);
            do{
                std::cout << "Please input the destination airport code" << std::endl;
                // std::cout << "1: Find if 2 airports are connected using BFS" << std::endl;
                std::cin >> dest;
                
                for (auto & c: dest) c = toupper(c);
            } while(dest.length() != 3);

            std::pair<int, std::vector<std::string>> output = r.shortestPath(origin, dest);
            std::cout << "Shortest route from " << origin << " to " << dest << " is " << output.first << " km long." << std::endl;
            std::cout << "The path is: ";
            for (std::string airport : output.second){
                std::cout << airport << " ";
            }
            std::cout << std::endl;
        }
        if (input == "3"){
            std::string numstring;
            bool validInput=true;
            do{
                validInput=true;
                std::cout << "Please input number of highest rank airports for Pagerank, this might take a while" << std::endl;
                // std::cout << "1: Find if 2 airports are connected using BFS" << std::endl;
                std::cin >> numstring;

                for (char c : numstring){
                    if (!isdigit(c)){
                        validInput=false;
                    }
                }
                // for (auto & c: origin) c = toupper(c);
            } while(!validInput);
            std::vector<std::string> output = r.mostPopularAirport(std::stoi(numstring));
            std::cout << "The most popular airports in descending order are: " << std::endl;
            for (std::string airport : output){
                std::cout << airport << std::endl;
            }
        }
        
    }
}