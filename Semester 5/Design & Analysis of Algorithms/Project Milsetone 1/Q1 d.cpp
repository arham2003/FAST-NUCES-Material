#include <iostream>
#include <vector>
using namespace std;

int partition(vector<double>& A, int low, int high) {
    double pivot = A[high]; // choosing the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            // Swap A[i] and A[j]
            swap(A[i], A[j]);
        }
    }
    
    swap(A[i + 1], A[high]);
    return i + 1;
}

void quicksort(vector<double>& A, int low, int high) {
    if (low < high) {
        
        int pivotIndex = partition(A, low, high);

        quicksort(A, low, pivotIndex - 1);  // Before pivot
        quicksort(A, pivotIndex + 1, high); // After pivot
    }
}

int main() {
    int n;
    cout << "Enter the size of the array (at least 10): ";
    cin >> n;

    if (n < 10) {
        cout << "Please enter a size of at least 10." << endl;
        return 1;
    }

    vector<double> A(n);
    cout << "Enter " << n << " real numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    quicksort(A, 0, n - 1);

    cout << "The sorted array is: ";
    for (double num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

