#include "airport.h"


Airport::Airport() {}

Airport::~Airport() {
    airport_ID = 0;
    airport_name = "";
    airport_IATAcode = "";
    //airport_location 
    //airport_position 

}

Airport::Airport(const Airport& other) {
    airport_ID = other.getAirportID();
    airport_name = other.getAirportName();
    airport_IATAcode = other.getAirportIATACode();
    //airport_position 
    //airport_location 
}

Airport::Airport(unsigned ID, string name, string IATAcode, double latitude, double longitude, string city = "", string country = "", double altitude = 0) {
    airport_ID = ID;
    airport_name = name;
    airport_IATAcode = IATAcode;
    //airport_position 
    //airport_location 
    //airport_altitude 
}

unsigned Airport::getAirportID() const {
    return airport_ID;
}

string Airport::getAirportName() const {
    return airport_name;
}
    
