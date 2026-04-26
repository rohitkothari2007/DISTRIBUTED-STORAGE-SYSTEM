#include "../include/server.h"

using namespace std;


// Constructor
Server::Server(int id, int capacity)
    : fileTree(3) {

    serverId = id;

    maxCapacity = capacity;

    fileCount = 0;
}


// Store File using B+ Tree
void Server::storeFile(
        string filename,
        string content) {

    if (isFull()) {

        cout << "Server "
             << serverId
             << " is FULL!\n";

        return;
    }

    fileTree.insert(
        filename,
        content
    );

    fileCount++;
}


// Retrieve File
string Server::retrieveFile(
        string filename) {

    return fileTree.search(
        filename
    );
}


// Delete File (Not implemented yet)
void Server::deleteFile(
        string filename) {

    // Future improvement
}


// Get File Count
int Server::getFileCount() {

    return fileCount;
}


// Get Server ID
int Server::getServerId() {

    return serverId;
}


// Check Capacity
bool Server::isFull() {

    return fileCount >= maxCapacity;
}


// Get Load
int Server::getLoad() {

    return fileCount;
}


//  Range Search
vector<string> Server::rangeSearch(
        string startKey,
        string endKey) {

    return fileTree.rangeSearch(
        startKey,
        endKey
    );
}