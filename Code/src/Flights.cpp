#include "../Include/Flights.h"
#include <iostream>
#include <queue>

void Flights::addEdge(Airport source, Airport target, string airline) {
    if(sources.find(source.getCode())==sources.end()){
        sources[source.getCode()]={};
    }
    if(sources.find(target.getCode())==sources.end()){
        sources[target.getCode()]={};
    }
    sources[source.getCode()].targets.push_back({target.getCode(),airline, calculateDistance(source,target)});
}

void Flights::bfs(string source) {
    for (auto& s:sources){
        s.second.visited=false;
        s.second.dist=-1;
    }
    queue<string> q;
    q.push(source);
    sources[source].visited = true;
    sources[source].dist=0;
    while (!q.empty()) {
        string u = q.front(); q.pop();
        for (auto e : sources[u].targets) {
            string w = e.target;
            if (!sources[w].visited) {
                q.push(w);
                sources[w].dist=sources[u].dist+1;
                sources[w].visited = true;
            }
        }
    }
}

int Flights::distance(string s, string t){
    bfs(s);
    return sources[t].dist;
}

double Flights::calculateDistance(Airport airport1, Airport airport2) {
    float long1 = airport1.getLongitude();
    float lat1 = airport1.getLatitude();
    lat1 = (lat1) * M_PI / 180.0;

    float long2 = airport2.getLongitude();
    float lat2 = airport2.getLatitude();
    lat2 = (lat2) * M_PI / 180.0;

    float dLat = (lat2 - lat1) * M_PI / 180.0;
    float dLong = (long2 - long1) * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) * pow(sin(dLong / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

//I want a function that returns how many flights are there starting from a given airport

int Flights::getFlightsFromAirport(string airportCode) {
    int count = 0;
    for (auto& s:sources){
        for (auto& t:s.second.targets){
            if (t.target == airportCode){
                count++;
            }
        }
    }
    return count;
}
