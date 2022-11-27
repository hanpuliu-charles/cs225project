#pragma once
#include <string>

using namespace std; // Try not to do this, might pollute the namespace
class Airport{

public:
    Airport();
    Airport(const Airport& other);
    Airport(unsigned ID, string name, string IATAcode, double latitude, double longitude, string city, string country, double altitude);
    ~Airport();

    unsigned getAirportID() const;
    string getAirportName() const;
    string getAirportIATACode() const;
    bool operator==(const Airport& other) const;
private:
    unsigned airport_ID;    
    string airport_name;    
    string airport_IATAcode;    
};

