#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BPlusNode {

public:

    bool isLeaf;

    vector<string> keys;

    vector<string> values;

    vector<BPlusNode*> children;

    BPlusNode* next;

    BPlusNode* parent;   // ⭐ NEW

    BPlusNode(bool leaf);

};


class BPlusTree {

private:

    BPlusNode* root;

    int maxKeys;

public:

    BPlusTree(int order = 3);

    void insert(string key, string value);

    string search(string key);

    void display();

    vector<string> rangeSearch(
    string startKey,
    string endKey
);

};

#endif