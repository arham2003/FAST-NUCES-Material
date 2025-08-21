#include <iostream>
using namespace std;
const int TABLE_SIZE = 10;

class HashNode {
public:
    int key;
    int data;
    HashNode* next;

    HashNode(int k, int d) : key(k), data(d), next(NULL) {}
};

class UniqueHashTable {
private:
    HashNode** hashTable;

    // Double hash function
    int doubleHash(int key, int i) {
        const int prime = 7;  
        return (key % TABLE_SIZE + i * (prime - (key % prime))) % TABLE_SIZE;
    }

public:
    UniqueHashTable() {
        hashTable = new HashNode*[TABLE_SIZE]();
    }

    void insert(int key, int data) {
        int index = key % TABLE_SIZE;
        int i = 1;
        while (hashTable[index] != NULL) {
            index = (index + doubleHash(key, i)) % TABLE_SIZE;
            i++;
        }
        hashTable[index] = new HashNode(key, data);
    }

    HashNode* search(int key) {
        int index = key % TABLE_SIZE;
        int i = 1;
        while (hashTable[index] != NULL) {
            if (hashTable[index]->key == key) {
                return hashTable[index];
            }
            // Use double hashing for collision resolution during search as well
            index = (index + doubleHash(key, i)) % TABLE_SIZE;
            i++;
        }
        return NULL; 
    }

    void remove(int key) {
        int index = key % TABLE_SIZE;
        int i = 1;
        while (hashTable[index] != NULL) {
            if (hashTable[index]->key == key) {
                HashNode* temp = hashTable[index];
                hashTable[index] = NULL;  
                delete temp;
                return;
            }
            index = (index + doubleHash(key, i)) % TABLE_SIZE;
            i++;
        }
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            if (hashTable[i] != NULL) {
                HashNode* current = hashTable[i];
                while (current != NULL) {
                    cout << "(" << current->key << ", " << current->data << ") ";
                    current = current->next;
                }
            }
            cout << endl;
        }
    }

    ~UniqueHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            HashNode* current = hashTable[i];
            while (current != NULL) {
                HashNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] hashTable;
    }
};

int main() {
    UniqueHashTable uniqueHashTable;

    uniqueHashTable.insert(20, 200);
    uniqueHashTable.insert(34, 340);
    uniqueHashTable.insert(45, 450);
    uniqueHashTable.insert(70, 700);
    uniqueHashTable.insert(56, 560);

    cout << "Initial Hash Table:\n";
    uniqueHashTable.display();

    int searchKey = 45;
    HashNode* searchData = uniqueHashTable.search(searchKey);
    if (searchData != NULL) {
        cout << "Element with key " << searchKey << " found: (" << searchData->key << ", " << searchData->data << ")\n";
    } else {
        cout << "Element with key " << searchKey << " not found.\n";
    }

    int deleteKey = 70;
    uniqueHashTable.remove(deleteKey);
    cout << "\nAfter deleting element with key " << deleteKey << ":\n";
    uniqueHashTable.display();

    return 0;
}

