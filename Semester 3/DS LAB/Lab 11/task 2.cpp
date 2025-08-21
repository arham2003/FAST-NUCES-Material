#include <iostream>
using namespace std;
const int MAX_SIZE = 100000;

class HashTable {
private:
    struct Node {
        int key;
        int count;
        Node* next;

        Node(int k) : key(k), count(1), next(NULL) {}
    };

    Node* table[MAX_SIZE];

    int hash(int key) {
        return key % MAX_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            table[i] = NULL;
        }
    }

    void insert(int key) {
        int index = hash(key);
        Node* newNode = new Node(key);

        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            Node* current = table[index];
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Count the number of occurrences of a key in the hash table
    int count(int key) {
        int index = hash(key);
        Node* current = table[index];

        while (current != NULL) {
            if (current->key == key) {
                return current->count;
            }
            current = current->next;
        }

        return 0; // Key not found
    }

    void incrementCount(int key) {
        int index = hash(key);
        Node* current = table[index];

        while (current != NULL) {
            if (current->key == key) {
                current->count++;
                return;
            }
            current = current->next;
        }
    }

    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != NULL) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int PairsWithSum(int arr[], int N, int K) {
    HashTable hashTable;

    int countPairs = 0;

    for (int i = 0; i < N; i++) {
        int complement = K - arr[i];

        countPairs += hashTable.count(complement);

        hashTable.incrementCount(arr[i]);

        hashTable.insert(arr[i]);
    }

    return countPairs;
}

int main() {
    int arr[] = {2, 9, 7, 4, 5, 6, 10, 0};
    int N = 8;
    int K = arr[0]+arr[1];

    int result = PairsWithSum(arr, N, K);

    cout << "Number of pairs with sum " << K << ": " << result << endl;

    return 0;
}

