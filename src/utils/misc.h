// Miscelleneous utilities

#pragma once
#include <vector>
#include <string>
#include <sstream>
std::vector<std::string> delimitString(std::string input, char delimiter){
    std::vector<std::string> output;
    // use string stream to make our life easier
    std::stringstream strstream(input);
    std::string item;
    while(std::getline(strstream, item, delimiter)){
        output.push_back(item);
    }
    return output;
}