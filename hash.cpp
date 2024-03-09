#include "hash.h"

HashTable::HashTable(int size) : numSlots(size) {
    table = new Node*[numSlots]();
}

HashTable::~HashTable() {
    for (int i = 0; i < numSlots; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] table;
}

int hash_function(string text) {
    int hashValue = 0;
    for (char &c : text) {
        hashValue += c;
    }
    return hashValue;
}

void HashTable::insert(string key) {
    int index = hash_function(key) % numSlots;
    Node* newNode = new Node(key);
    newNode->next = table[index];
    table[index] = newNode;
}

void HashTable::printFirstSlots(int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Slot " << i << ":";
        for (Node* current = table[i]; current != nullptr; current = current->next) {
            cout << " " << current->key;
        }
        cout << endl;
    }
}

void HashTable::printSlotLengths() {
    for (int i = 0; i < numSlots; ++i) {
        int length = 0;
        for (Node* current = table[i]; current != nullptr; current = current->next) {
            length++;
        }
        cout << "Slot " << i << ": " << length << endl;
    }
}

float HashTable::calculateStandardDeviation() {
    float mean = 0;
    int totalElements = 0;
    for (int i = 0; i < numSlots; ++i) {
        int length = 0;
        for (Node* current = table[i]; current != nullptr; current = current->next) {
            length++;
        }
        totalElements += length;
    }
    mean = static_cast<float>(totalElements) / numSlots;

    float variance = 0;
    for (int i = 0; i < numSlots; ++i) {
        int length = 0;
        for (Node* current = table[i]; current != nullptr; current = current->next) {
            length++;
        }
        variance += (length - mean) * (length - mean);
    }
    variance /= numSlots;

    return sqrt(variance);
}

