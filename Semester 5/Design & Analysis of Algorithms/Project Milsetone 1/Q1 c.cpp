#include <iostream>
#include <vector>
using namespace std;

// Merging two sorted arrays and counting the inversions
long long mergeAndCount(vector<double>& A, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    vector<double> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = A[mid + 1 + i];

    // Merge the temp arrays back into A[left..right]
    int i = 0, j = 0, k = left;
    long long inversions = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
            // Count inversions, because all remaining elements in L are greater than R[j]
            inversions += (n1 - i);
        }
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        A[k++] = L[i++];
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        A[k++] = R[j++];
    }

    return inversions;
}

// Divide and conquer method to sort the array and count inversions
long long mergeSortAndCount(vector<double>& A, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in the left half and right half
        inversions += mergeSortAndCount(A, left, mid);
        inversions += mergeSortAndCount(A, mid + 1, right);

        // Count the inversions during the merge process
        inversions += mergeAndCount(A, left, mid, right);
    }
    return inversions;
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

    long long inversions = mergeSortAndCount(A, 0, n - 1);

    cout << "The number of inversions is: " << inversions << endl;
    cout << "The sorted array is: ";
    for (double num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

