#include "../include/graph.h"
#include <climits>
#include <algorithm>   //  required for reverse()

using namespace std;


// ===============================
// Add Edge
// ===============================

void Graph::addEdge(
        string from,
        string to,
        int weight) {

    adjList[from].push_back(
        {to, weight}
    );

    adjList[to].push_back(
        {from, weight}
    );
}


// ===============================
// Dijkstra Shortest Path
// ===============================

void Graph::shortestPath(
        string start) {

    map<string,int> dist;

    priority_queue<
        pair<int,string>,
        vector<pair<int,string>>,
        greater<pair<int,string>>
    > pq;

    // Initialize distances
    for (auto &node : adjList) {

        dist[node.first] = INT_MAX;
    }

    dist[start] = 0;

    pq.push({0, start});


    while (!pq.empty()) {

        string current =
            pq.top().second;

        int currentDist =
            pq.top().first;

        pq.pop();


        for (auto &neighbor :
             adjList[current]) {

            string next =
                neighbor.first;

            int weight =
                neighbor.second;

            if (dist[next] >
                currentDist + weight) {

                dist[next] =
                    currentDist + weight;

                pq.push(
                    {dist[next], next}
                );
            }
        }
    }


    // Display shortest paths

    cout << "\nShortest Paths from "
         << start << ":\n";

    for (auto &node : dist) {

        cout << start
             << " -> "
             << node.first
             << " = "
             << node.second
             << endl;
    }
}


// ===============================
// File Transfer Using Dijkstra
// ===============================

void Graph::transferFile(
        string source,
        string destination) {

    map<string,int> dist;
    map<string,string> parent;

    priority_queue<
        pair<int,string>,
        vector<pair<int,string>>,
        greater<pair<int,string>>
    > pq;

    // Initialize distances
    for (auto &node : adjList) {

        dist[node.first] = INT_MAX;
    }

    dist[source] = 0;

    pq.push({0, source});


    while (!pq.empty()) {

        string current =
            pq.top().second;

        int currentDist =
            pq.top().first;

        pq.pop();


        for (auto &neighbor :
             adjList[current]) {

            string next =
                neighbor.first;

            int weight =
                neighbor.second;

            if (dist[next] >
                currentDist + weight) {

                dist[next] =
                    currentDist + weight;

                parent[next] =
                    current;

                pq.push(
                    {dist[next], next}
                );
            }
        }
    }


    // Display Transfer Simulation

    cout << "\nTransferring file from "
         << source
         << " to "
         << destination
         << endl;

    vector<string> path;

    string current = destination;

    // Build path
    while (current != source) {

        path.push_back(current);

        current = parent[current];
    }

    path.push_back(source);

    reverse(
        path.begin(),
        path.end()
    );


    cout << "Shortest route:\n";

    for (int i = 0;
         i < path.size();
         i++) {

        cout << path[i];

        if (i != path.size()-1)

            cout << " -> ";
    }

    cout << endl;

    cout << "Total latency: "
         << dist[destination]
         << " ms\n";
}