#include "../include/bplustree.h"

using namespace std;


// ===============================
// Node Constructor
// ===============================

BPlusNode::BPlusNode(bool leaf) {

    isLeaf = leaf;

    next = nullptr;

    parent = nullptr;
}


// ===============================
// Tree Constructor
// ===============================

BPlusTree::BPlusTree(int order) {

    root = nullptr;

    maxKeys = order;
}


// ===============================
// Insert Function (Correct Multi-Level Version)
// ===============================

void BPlusTree::insert(
        string key,
        string value) {

    // Case 1: Empty Tree

    if (root == nullptr) {

        root = new BPlusNode(true);

        root->keys.push_back(key);

        root->values.push_back(value);

        return;
    }

    // Case 2: Navigate to correct leaf

    BPlusNode* leaf = root;

    while (!leaf->isLeaf) {

        int i = 0;

        while (i < leaf->keys.size() &&
               key > leaf->keys[i]) {

            i++;
        }

        leaf = leaf->children[i];
    }

    // Insert into leaf (sorted)

    int i = 0;

    while (i < leaf->keys.size() &&
           key > leaf->keys[i]) {

        i++;
    }

    leaf->keys.insert(
        leaf->keys.begin() + i,
        key
    );

    leaf->values.insert(
        leaf->values.begin() + i,
        value
    );

    // ===============================
    // Overflow Check
    // ===============================

    if (leaf->keys.size() > maxKeys) {

        cout << "Node overflow detected - splitting...\n";

        // Create new leaf

        BPlusNode* newLeaf =
            new BPlusNode(true);

        int mid =
            leaf->keys.size() / 2;

        // Move half keys

        for (int j = mid;
             j < leaf->keys.size();
             j++) {

            newLeaf->keys.push_back(
                leaf->keys[j]
            );

            newLeaf->values.push_back(
                leaf->values[j]
            );
        }

        // Resize original leaf

        leaf->keys.resize(mid);

        leaf->values.resize(mid);

        // Link leaves

        newLeaf->next = leaf->next;

        leaf->next = newLeaf;

        // ===============================
        // Root Split Case
        // ===============================

        if (leaf == root) {

            BPlusNode* newRoot =
                new BPlusNode(false);

            newRoot->keys.push_back(
                newLeaf->keys[0]
            );

            newRoot->children.push_back(leaf);

            newRoot->children.push_back(newLeaf);

            leaf->parent = newRoot;

            newLeaf->parent = newRoot;

            root = newRoot;

            cout << "New root created.\n";
        }

        cout << "Split completed.\n";
    }
}


// ===============================
// Search Function
// ===============================

string BPlusTree::search(string key) {

    if (root == nullptr)
        return "File not found";

    BPlusNode* current = root;

    // Move to leaf

    while (!current->isLeaf) {

        int i = 0;

        while (i < current->keys.size() &&
               key > current->keys[i]) {

            i++;
        }

        current =
            current->children[i];
    }

    // Search leaf

    while (current != nullptr) {

        for (int i = 0;
             i < current->keys.size();
             i++) {

            if (current->keys[i] == key) {

                return current->values[i];
            }
        }

        current = current->next;
    }

    return "File not found";
}


// ===============================
// Display Tree (Leaf Traversal)
// ===============================

void BPlusTree::display() {

    if (root == nullptr) {

        cout << "Tree empty\n";

        return;
    }

    cout << "\nB+ Tree Contents:\n";

    BPlusNode* current = root;

    // Move to first leaf

    while (!current->isLeaf) {

        current =
            current->children[0];
    }

    // Print all leaves

    while (current != nullptr) {

        for (int i = 0;
             i < current->keys.size();
             i++) {

            cout << current->keys[i]
                 << " ";
        }

        current = current->next;
    }

    cout << endl;
}


// ===============================
// Range Search
// ===============================

vector<string> BPlusTree::rangeSearch(
        string startKey,
        string endKey) {

    vector<string> result;

    if (root == nullptr)
        return result;

    BPlusNode* current = root;

    // Move to leaf level

    while (!current->isLeaf) {

        current =
            current->children[0];
    }

    // Traverse leaves

    while (current != nullptr) {

        for (int i = 0;
             i < current->keys.size();
             i++) {

            if (current->keys[i] >= startKey &&
                current->keys[i] <= endKey) {

                result.push_back(
                    current->keys[i]
                );
            }
        }

        current = current->next;
    }

    return result;
}