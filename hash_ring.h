#ifndef HASH_RING_H
#define HASH_RING_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "server.h"

using namespace std;

class HashRing {

private:

    map<int, Server*> ring;

    int virtualNodes = 3;

    int hashFunction(string key);

public:

    void addServer(string serverName);

    void removeServer(string serverName);

    Server* getServer(string filename);

    Server* getNextServer(int hashKey);

    Server* getLeastLoadedServer();

    // ONLY DECLARE here
    void storeFileWithReplication(
        string filename,
        string content
    );

    void displayRing();

    void redistributeFiles(Server* removedServer);

    void displayServerLoads();

    vector<string> distributedRangeSearch(
    string startKey,
    string endKey
);

};

#endif