#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <string>
#include <vector>   //  REQUIRED
#include "../include/bplustree.h"

using namespace std;

class Server {

private:

    int serverId;

    int maxCapacity;

    int fileCount;

    // B+ Tree Storage
    BPlusTree fileTree;

public:

    // Constructor
    Server(int id, int capacity);

    // Store file
    void storeFile(
        string filename,
        string content
    );

    // Retrieve file
    string retrieveFile(
        string filename
    );

    // Delete file
    void deleteFile(
        string filename
    );

    // Get file count
    int getFileCount();

    // Get server ID
    int getServerId();

    // Check capacity
    bool isFull();

    // Get load
    int getLoad();

    //  Range Search
    vector<string> rangeSearch(
        string startKey,
        string endKey
    );

};

#endif