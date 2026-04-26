#include <iostream>
#include <vector>
#include "../include/hash_ring.h"
#include "../include/graph.h"

using namespace std;

int main() {

    cout << "Distributed Storage System Started\n";

    HashRing ring;

    // ============================
    // Add Servers
    // ============================

    ring.addServer("ServerA");
    ring.addServer("ServerB");
    ring.addServer("ServerC");

    ring.displayRing();


    // ============================
    // Store Files
    // ============================

    cout << "\n--- Storing Files ---\n";

    ring.storeFileWithReplication("file1.txt","Data 1");
    ring.storeFileWithReplication("file2.txt","Data 2");
    ring.storeFileWithReplication("file3.txt","Data 3");
    ring.storeFileWithReplication("file4.txt","Data 4");
    ring.storeFileWithReplication("file5.txt","Data 5");
    ring.storeFileWithReplication("file6.txt","Data 6");
    ring.storeFileWithReplication("file7.txt","Data 7");
    ring.storeFileWithReplication("file8.txt","Data 8");


    // ============================
    // Display Loads
    // ============================

    cout << "\n--- Server Loads After Storage ---\n";

    ring.displayServerLoads();


    // ============================
    // Distributed Range Search
    // ============================

    cout << "\n--- Distributed Range Search Test ---\n";

    vector<string> results =
        ring.distributedRangeSearch(
            "file2.txt",
            "file6.txt"
        );

    cout << "Files between file2.txt and file6.txt:\n";

    for (auto &file : results) {

        cout << file << endl;
    }


    // ============================
    // Graph Network Simulation
    // ============================

    cout << "\n--- Server Network Simulation (Dijkstra) ---\n";

    Graph network;

    // Add connections (latency in ms)

    network.addEdge("ServerA","ServerB",10);

    network.addEdge("ServerA","ServerC",20);

    network.addEdge("ServerB","ServerC",5);

    network.addEdge("ServerB","ServerD",15);

    network.addEdge("ServerC","ServerD",10);


    // Run Dijkstra

    network.shortestPath("ServerA");


    //  NEW FEATURE — File Transfer Simulation

    network.transferFile(
        "ServerA",
        "ServerD"
    );


    // ============================
    // Remove Server Simulation
    // ============================

    cout << "\n--- Removing ServerB ---\n";

    ring.removeServer("ServerB");

    ring.displayRing();


    cout << "\n--- Server Loads After Removal ---\n";

    ring.displayServerLoads();


    cout << "\nSystem Execution Completed\n";

    return 0;
}