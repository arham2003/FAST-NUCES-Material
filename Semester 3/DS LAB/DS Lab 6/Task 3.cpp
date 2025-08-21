#include<iostream>
using namespace std;

void merge(int *arr, int s, int mid, int e, bool ascending) {
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // Copy values
    for (int i = 0; i < len1; i++) {
        first[i] = arr[s + i];
    }

    for (int i = 0; i < len2; i++) {
        second[i] = arr[mid + 1 + i];
    }

    // Merge two sorted arrays
    int index1 = 0;
    int index2 = 0;
    int mainArrayIndex = s;

    while (index1 < len1 && index2 < len2) {
        if ((ascending && first[index1] <= second[index2]) || (!ascending && first[index1] >= second[index2])) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int s, int e, bool ascending) {
    if (s < e) {
        int mid = s + (e - s) / 2;

        // Left part sorting
        mergeSort(arr, s, mid, ascending);

        // Right part sorting
        mergeSort(arr, mid + 1, e, ascending);

        // Merge the two halves
        merge(arr, s, mid, e, ascending);
    }
}

int main() {
    int arr[8] = {3, 1, 6, 8, 4, 5, 7, 2};
    int n = 8;

    mergeSort(arr, 0, n - 1, true); // Ascending order
    cout << "Ascending Sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1, false); // Descending order
    cout << "Descending Sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

