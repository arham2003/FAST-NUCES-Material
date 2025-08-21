// 22k-4080

#include <iostream>
#include <string>
using namespace std;

struct Crate {
    string id;
    string shippingDate;
};

void applyInsertionSort(Crate crates[], int size) {
    for (int i = 1; i < size; ++i) {
        Crate currentCrate = crates[i];
        int j = i - 1;

        while (j >= 0 && crates[j].shippingDate > currentCrate.shippingDate) {
            crates[j + 1] = crates[j];
            j = j - 1;
        }
        crates[j + 1] = currentCrate;
    }
}

int main() {
    cout << "Welcome to the Crate Sorting Program!" << endl;

    int crateCount;
    cout << "Enter the number of crates: ";
    cin >> crateCount;

    Crate crates[crateCount];
    for (int i = 0; i < crateCount; ++i) {
        cout << "Enter ID for Crate " << i + 1 << ": ";
        cin >> crates[i].id;
        cout << "Enter shipping date (YYYY-MM-DD) for Crate " << i + 1 << ": ";
        cin >> crates[i].shippingDate;
    }

    applyInsertionSort(crates, crateCount);

    cout << "\nOptimized crate order for shipping:\n";
    for (int i = 0; i < crateCount; ++i) {
        cout << "Crate " << crates[i].id << " (Shipping Date: " << crates[i].shippingDate << ")\n";
    }

    cout << "Crates are now arranged for shipping!" << endl;

    return 0;
}

