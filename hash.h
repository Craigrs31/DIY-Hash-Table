#ifndef HASH_H
#define HASH_H

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int hash_function(string text);

struct Node {
    string key;
    Node* next;
    Node(string key) : key(key), next(nullptr) {}
};

class HashTable {
private:
    Node** table; // Dynamic array of pointer to Node
    int numSlots; // Number of slots in the hash table

public:
    HashTable(int size);
    ~HashTable();
    void insert(string key);
    void printFirstSlots(int n);
    void printSlotLengths();
    float calculateStandardDeviation();
};

#endif // HASH_H

