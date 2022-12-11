#include "RouteFinder.h"
#include "utils/misc.h"
#include <utility>
#include <queue>
#include <functional>
#include <iostream>
#include <limits>
#include <stack>
#include <algorithm>

// constructor
RouteFinder::RouteFinder(std::string filename){
    // constructor
    std::ifstream ifs;
    ifs.open(filename);
    std::string line;
    int airports_counter = 0;
    while(std::getline(ifs, line)){
        // Do something
        std::vector<std::string> delimitedString = delimitString(line, ',');
        std::string origin = delimitedString[2]; // NOTE: all airport using 3 letter IATA names in routes
        std::string dest = delimitedString[4];
        std::string airline = delimitedString[0];
        int dist = std::stoi(delimitedString[9]);
        // I want to use airport class, but the routes file only provide the IATA code for the airport so its pointless to create a another class.
        if (!airports_.count(origin)){
            airports_.insert(origin);
            airport_to_int_[origin]=airports_counter;
            int_to_airport_[airports_counter++] = origin;
            // We also need to add one entry in adj_list vector
            adj_list_.push_back(std::list<std::pair<int,int>>());
        }
        if (!airports_.count(dest)) {
            airports_.insert(dest);
            airport_to_int_[dest]=airports_counter;
            int_to_airport_[airports_counter++] = dest;
            adj_list_.push_back(std::list<std::pair<int,int>>());
        }

        
        // std::cout << origin << " " << dest << " " << dist << std::endl;
        // insert into graph too
        adj_list_[airport_to_int_[origin]].push_front(std::make_pair(airport_to_int_[dest], dist));
        

    }

    // Build Adj_Matrix
    adj_matr_= std::vector<std::vector<float>>(airports_counter,std::vector<float>(airports_counter,0));
    for(int originAirport = 0; originAirport < airports_counter; originAirport++ ){
        for (std::list<std::pair<int,int>>::iterator iter2 = adj_list_[originAirport].begin(); iter2 != adj_list_[originAirport].end(); iter2++){
            adj_matr_[iter2->first][originAirport] += 1;
        }
    }
    normalizeMatrix();

}
bool RouteFinder::isConnectedBFS(std::string origin, std::string dest){
    // TODO
    std::unordered_set<int> visited;
    std::queue<int> q;
    int destNumber = airport_to_int_[dest];
    // enqueue origin
    q.push(airport_to_int_[origin]);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if (visited.count(cur) == 1){
            continue;
        }
        // std::cout << "currently processing node " << cur << std::endl;
        // mark as visited
        visited.insert(cur);
        // visit cur in adj list and enqueue its neighbors
        std::list<std::pair<int,int>>::iterator iter = adj_list_[cur].begin();
        while(iter != adj_list_[cur].end()){
            // std::cout
            int newnode = iter->first;
            q.push(newnode);
            if (newnode == destNumber) {
                // we found it
                return true;
            }
            iter++;
        }
    }

    return false;
}

// Should we change to output pair<int, vector<string>>, int is the length and vector contains all airports from start to end of the shortest path?
std::pair<int, std::vector<std::string>> RouteFinder::shortestPath(std::string origin, std::string dest){
    // TODO
    int originNumber = airport_to_int_[origin];
    int destNumber = airport_to_int_[dest];
    std::vector<int> distances(adj_list_.size(), std::numeric_limits<int>::max()); // Replace with max int
    std::vector<int> previousAirport(adj_list_.size(), -1);
    
    // Initialize data structure with MAX INT for unconnected?

    // create priority Queue pQ
    auto cmp = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
    {
    return lhs.second > rhs.second;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pQ(cmp);


    // pQ.push(adj_list_[originNumber].front());  //Incorrect
    pQ.push(std::make_pair(originNumber, 0));
    distances[originNumber] = 0;

    while(!pQ.empty()){
        int cur = pQ.top().first;
        pQ.pop();
        // std::cout << "Dijkstra" << cur << std::endl;
        
        for (std::list<std::pair<int,int>>::iterator it = adj_list_[cur].begin(); it != adj_list_[cur].end(); it++){
            int v = it->first;
            int dist = it->second;

            // only consider this if 
            if (distances[v]> distances[cur] + dist){
                distances[v] = distances[cur] + dist;
                pQ.push(std::make_pair(v,distances[v])); // Should be decrease priority?


                // Update node before
                // previousAirport...
                previousAirport[v] = cur; // Update the previous airport of v for shortest path

            }
        }
    }

    // Not found case check
    if (previousAirport[destNumber]==-1){
        return std::make_pair(-1,std::vector<std::string>());
    }

    //Find the airport on the way to destination
    int back_track = destNumber;
    std::vector<int> route_airport_int;
    route_airport_int.push_back(destNumber);
    while(back_track != originNumber) {
        back_track = previousAirport[back_track];
        route_airport_int.push_back(back_track);
    }
     
    //Changes the Number to Name of airport and reverse the order
    std::vector<std::string> route_airport_string;
    for (int i = route_airport_int.size() - 1; i >= 0; i--) {
        route_airport_string.push_back(int_to_airport_[route_airport_int.at(i)]);
    }
    
    /*** 
     *  this is the original return
     * 
     *  std::priority_queue minq2(adj_list_[originNumber].begin(), adj_list_[destNumber].end(), std::greater<int>());
     *  return distances[destNumber]; // Not connected;
    */

   //first is the distance to dest, second is the passing by airport 
    std::pair<int, std::vector<std::string>> to_return = std::make_pair(distances[destNumber], route_airport_string);
    return to_return;
}

// What sort of data do we want to output for 

std::vector<std::string> RouteFinder::mostPopularAirport(int n){
    std::vector<double> input(adj_matr_.size(),1.0/adj_matr_.size());
    // std::cout << input[0] << std::endl;
    std::vector<double> steadyStateProbabilty = powerIteration(input,260); // Top 100 airport is stable at 260 iterations
    // for (size_t i = 0; i < adj_matr_.size(); i++){
    //     std::cout << steadyStateProbabilty[i] << std::endl;
    // }
    std::vector<std::string> output(n,"");
    for (int i = 0; i < n; i++){
        output[i] = int_to_airport_[ std::distance(steadyStateProbabilty.begin(), std::max_element(steadyStateProbabilty.begin(), steadyStateProbabilty.end()))];
        *(std::max_element(steadyStateProbabilty.begin(), steadyStateProbabilty.end()))=-1;
    }
    return output;
}


// Didn't include damping yet? should we?
std::vector<double> RouteFinder::powerIteration(std::vector<double> v, int n) {
    size_t m_size = adj_matr_.size(); // M should be square
    for (int times = 0; times < n; times++){
        // std::cout << "Times: " << times << std::endl;
        // Repeat n times
        std::vector<double> temp(m_size,0.0);
        for (size_t row = 0; row < m_size; row++){
            double accumulator = 0.0;
            for (size_t col = 0; col < m_size; col++){
                accumulator += adj_matr_[row][col] * v[col];
            }
            temp[row] = accumulator;

        }
        v = temp;
    }
    return v;
}

void RouteFinder::normalizeMatrix() {
    std::vector<double> denominator;
    for (size_t col = 0; col < adj_matr_.size(); col++){
        float accumulator = 0;
        for (size_t row = 0; row < adj_matr_.size(); row++){
            accumulator += adj_matr_[row][col];
        }
        denominator.push_back(accumulator);
    }
    for (size_t row = 0; row < adj_matr_.size(); row++){
        for (size_t col = 0; col < adj_matr_.size(); col++){
            if (denominator[col] != 0){
                adj_matr_[row][col] /= denominator[col];
            } else {
                adj_matr_[row][col] = 1.0/(float)adj_matr_.size();
            }

        }
    }
    // For debugging, will print out
    // for (size_t i = 0; i < adj_matr_.size(); i++){
    //     for (size_t j = 0; j < adj_matr_.size(); j++){
    //         std::cout << adj_matr_[i][j] << "\t";
    //     }
    //     std::cout << std::endl;
    // }

}

