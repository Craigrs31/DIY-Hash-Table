#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"

using namespace std;

int main() {
    int k = 0;
    string texts[500];
    int n = 0;

    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n++] = line;
    }

    HashTable myHashTable(k);

    for (int i = 0; i < n; ++i) {
        myHashTable.insert(texts[i]);
    }

    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    myHashTable.printFirstSlots(5);

    cout << "==== Printing the slot lengths ====" << endl;
    myHashTable.printSlotLengths();

    cout << "==== Printing the standard variance ====" << endl;
    cout << fixed << setprecision(4) << myHashTable.calculateStandardDeviation() << endl;

    return 0;
}

