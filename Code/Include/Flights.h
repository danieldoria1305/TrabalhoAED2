
#ifndef TRABALHOAED2_FLIGHTS_H
#define TRABALHOAED2_FLIGHTS_H

#include "Airport.h"
#include "Airline.h"
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <set>

class Flights {
    struct Target {
        string target;
        string airline;
        double distance;
    };

    struct Source {
        list<Target> targets;
        bool visited=false;
        int dist;
        double realDistance;
    };

    unordered_map<string,Source> sources; // Unordered map of Airports being represented

public:
    void addEdge(Airport source, Airport target, string airline);
    void bfs(string source);
    double calculateDistance(Airport airport1, Airport airport2); // Calculates the distance between two coordinates using the Haversine formula
    vector<string> dijkstra(string src, string dest, std::set<string> airlines);
    unordered_map<string,Source> getSources();
    vector<pair<string, pair<int, double>>> howFar(int i);

    vector<pair<string, double>> howFar(int i, string src);
};


#endif //TRABALHOAED2_FLIGHTS_H
