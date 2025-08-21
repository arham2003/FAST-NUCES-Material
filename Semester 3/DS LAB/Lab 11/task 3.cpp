#include <iostream>
#include <cmath>
using namespace std;
const int MAX_SIZE = 100000;

class HashTable {
private:
    struct HashNode {
        int key;
        HashNode* next;

        HashNode(int k) : key(k), next(nullptr) {}
    };

    HashNode* table[MAX_SIZE];

    int hash(int key) {
        // Ensure non-negative hash values
        return (key % MAX_SIZE + MAX_SIZE) % MAX_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    void insert(int key) {
        int index = hash(key);
        HashNode* newNode = new HashNode(key);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            HashNode* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Check if a key exists in the hash table
    bool contains(int key) {
        int index = hash(key);
        HashNode* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            HashNode* current = table[i];
            while (current != nullptr) {
                HashNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int ZeroTriplets(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        HashTable hashTable;

        for (int j = i + 1; j < n; j++) {
            int complement = -(arr[i] + arr[j]);

            // Check if the complement exists in the hash table
            if (hashTable.contains(complement)) {
                return 1; 
            }

            
            hashTable.insert(arr[j]);
        }
    }

    return 0;
}

int main() {
    int arr[] = {0, -1, 2, -3, 1};
    int n = 5;

    int tripletExists = ZeroTriplets(arr, n);

    cout << "Output: " << tripletExists << endl;

    return 0;
}

