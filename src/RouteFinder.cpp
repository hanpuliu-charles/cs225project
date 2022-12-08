#include "RouteFinder.h"
#include "utils/misc.h"
#include <utility>
#include <queue>
#include <functional>
#include <iostream>
#include <limits>
#include <stack>

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

        
        std::cout << origin << " " << dest << " " << dist << std::endl;
        // insert into graph too
        adj_list_[airport_to_int_[origin]].push_front(std::make_pair(airport_to_int_[dest], dist));
        

    }
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
        std::cout << "Dijkstra" << cur << std::endl;
        
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
    for (size_t i = route_airport_int.size() - 1; i >= 0; i--) {
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




// Didn't include damping yet? should we?
std::vector<float> powerIteration(std::vector<std::vector<float>> m, std::vector<float> v, int n) {
    size_t m_size = m.size(); // M should be square
    for (int times = 0; times < n; times++){
        // Repeat n times
        std::vector<float> temp(0.0, m_size);
        for (int row = 0; row < m_size; row++){
            float accumulator = 0.0;
            for (int row = 0; row < m_size; row++){
                accumulator += m[row][col] * v[col];
            }
            temp[row] = accumulator;

        }
        v = temp;
    }
    return v;
}

void normalizeMatrix(std::vector<std::vector<float>>& input ) {
    std::vector<float> denominator;
    for (size_t col = 0; col < input.size(); col++){
        float accumulator = 0;
        for (size_t row = 0; row < input.size(); row++){
            accumulator += input[row][col];
        }
        denominator.push_back(accumulator);
    }
    for (size_t row = 0; row < input.size(); row++{
        for (size_t col = 0; col < input.size(); col++){
            if (denominator[col != 0]){
                input[row][col] /= denominator[col];
            } else {
                input[row][col] = 1.0/(float)input.size();
            }

        }
    }
}

