#ifndef TRABALHOAED2_AIRLINE_H
#define TRABALHOAED2_AIRLINE_H
#include "Flight.h"
#include <string>
#include <list>

using namespace std;

class Airline {
public:
    Airline(string code, string name, string callsign, list<Flight> flights); // Constructor
    Airline();  // Default Constructor
    string getCode() const; // Returns the code of the airline
    string getName() const; // Returns the name of the airline
    string getCallSign() const; // Returns the callsign of the airline
    list<Flight> getFlights() const; // Returns the list of flights of the airline

private:
    string code_; // Code of the airline
    string name_; // Name of the airline
    string callsign_; // Callsign of the airline
    list<Flight> flights_; // List of flights of the airline
};


#endif //TRABALHOAED2_AIRLINE_H