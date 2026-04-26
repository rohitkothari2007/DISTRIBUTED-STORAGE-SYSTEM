#include "../include/hash_ring.h"
#include <functional>
#include <climits>
#include <set>   //  REQUIRED for duplicate removal

using namespace std;


// Default capacity per server
int DEFAULT_CAPACITY = 10;


// ===============================
// Hash Function
// ===============================

int HashRing::hashFunction(string key) {

    hash<string> hasher;

    return hasher(key) % 1000;
}


// ===============================
// Add Server
// ===============================

void HashRing::addServer(string serverName) {

    for (int i = 0; i < virtualNodes; i++) {

        string virtualNodeName =
            serverName + "_VN_" + to_string(i);

        int hashKey =
            hashFunction(virtualNodeName);

        Server* newServer =
            new Server(hashKey, DEFAULT_CAPACITY);

        ring[hashKey] = newServer;

        cout << "Virtual node added at position: "
             << hashKey
             << " for "
             << serverName
             << endl;
    }
}


// ===============================
// Remove Server
// ===============================

void HashRing::removeServer(string serverName) {

    cout << "\nRemoving server: "
         << serverName << endl;

    for (int i = 0; i < virtualNodes; i++) {

        string virtualNodeName =
            serverName + "_VN_" + to_string(i);

        int hashKey =
            hashFunction(virtualNodeName);

        auto it =
            ring.find(hashKey);

        if (it != ring.end()) {

            Server* removedServer =
                it->second;

            delete removedServer;

            ring.erase(it);

            cout << "Removed virtual node at position: "
                 << hashKey << endl;
        }
    }

    cout << "Redistribution handled by greedy logic.\n";
}


// ===============================
// Get Primary Server
// ===============================

Server* HashRing::getServer(string filename) {

    int hashKey =
        hashFunction(filename);

    auto it =
        ring.lower_bound(hashKey);

    if (it == ring.end()) {

        it = ring.begin();
    }

    return it->second;
}


// ===============================
// Get Backup Server
// ===============================

Server* HashRing::getNextServer(int hashKey) {

    auto it =
        ring.upper_bound(hashKey);

    if (it == ring.end()) {

        it = ring.begin();
    }

    return it->second;
}


// ===============================
// Greedy Load Balancing
// ===============================

Server* HashRing::getLeastLoadedServer() {

    Server* bestServer = nullptr;

    int minLoad = INT_MAX;

    for (auto &entry : ring) {

        Server* current =
            entry.second;

        if (!current->isFull()) {

            int load =
                current->getLoad();

            if (load < minLoad) {

                minLoad = load;

                bestServer = current;
            }
        }
    }

    return bestServer;
}


// ===============================
// Store File with Replication
// ===============================

void HashRing::storeFileWithReplication(
        string filename,
        string content) {

    Server* primary =
        getLeastLoadedServer();

    if (primary == nullptr) {

        cout << "All servers FULL!" << endl;

        return;
    }

    primary->storeFile(
        filename,
        content
    );

    int hashKey =
        hashFunction(filename);

    Server* backup =
        getNextServer(hashKey);

    if (backup != primary &&
        !backup->isFull()) {

        backup->storeFile(
            filename,
            content
        );
    }

    cout << "\nFile stored: "
         << filename << endl;

    cout << "Primary Server ID: "
         << primary->getServerId()
         << endl;

    cout << "Backup Server ID: "
         << backup->getServerId()
         << endl;
}


// ===============================
// Display Ring
// ===============================

void HashRing::displayRing() {

    cout << "\nCurrent Hash Ring:\n";

    for (auto &entry : ring) {

        cout << entry.first << " ";
    }

    cout << endl;
}


// ===============================
// Display Loads
// ===============================

void HashRing::displayServerLoads() {

    cout << "\nServer Load Status:\n";

    for (auto &entry : ring) {

        Server* server =
            entry.second;

        cout << "Server "
             << server->getServerId()
             << " -> "
             << server->getLoad()
             << " files"
             << endl;
    }
}


// ===============================
// Distributed Range Search (FINAL)
// ===============================

vector<string> HashRing::distributedRangeSearch(
        string startKey,
        string endKey) {

    //  Use set to remove duplicates

    set<string> uniqueFiles;

    for (auto &entry : ring) {

        Server* server =
            entry.second;

        vector<string> results =
            server->rangeSearch(
                startKey,
                endKey
            );

        for (auto &file : results) {

            uniqueFiles.insert(file);
        }
    }

    // Convert set → vector

    vector<string> finalResults(
        uniqueFiles.begin(),
        uniqueFiles.end()
    );

    return finalResults;
}


// ===============================
// Dummy Redistribution Function
// ===============================

void HashRing::redistributeFiles(
        Server* removedServer) {

    // Not used currently

}