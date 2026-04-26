#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

class Graph {

private:

    // Adjacency List
    map<string,
        vector<pair<string,int>>> adjList;

public:

    // Add connection
    void addEdge(
        string from,
        string to,
        int weight
    );

    // Dijkstra shortest path
    void shortestPath(
        string start
    );

    // REQUIRED — Add this
    void transferFile(
        string source,
        string destination
    );

};

#endif