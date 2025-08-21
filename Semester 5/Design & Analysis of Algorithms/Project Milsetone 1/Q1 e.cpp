#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

double minDistance(double d1, double d2) {
    return (d1 < d2) ? d1 : d2;
}

// Brute force approach to find the closest pair in a small set
double bruteForceClosestPair(const vector<double>& A, int left, int right) {
    double minDist = numeric_limits<double>::max();
    for (int i = left; i < right; i++) {
        for (int j = i + 1; j <= right; j++) {
            minDist = min(minDist, abs(A[i] - A[j]));
        }
    }
    return minDist;
}

double closestPairDivideAndConquer(const vector<double>& A, int left, int right) {
    // Base case: if there are 2 or 3 elements, use brute force
    if (right - left <= 2) {
        return bruteForceClosestPair(A, left, right);
    }

    int mid = left + (right - left) / 2;

    double dLeft = closestPairDivideAndConquer(A, left, mid);
    double dRight = closestPairDivideAndConquer(A, mid + 1, right);

    // Find the minimum distance from the left and right sides
    double d = minDistance(dLeft, dRight);

    // Combine step: Check the closest pair that crosses the middle
    double crossMinDist = abs(A[mid] - A[mid + 1]);
    
    return minDistance(d, crossMinDist);
}

int main() {
    int n;
    cout << "Enter the size of the array (at least 10): ";
    cin >> n;

    if (n < 10) {
        cout << "The size of the array must be at least 10." << endl;
        return 1;
    }

    vector<double> A(n);
    cout << "Enter " << n << " real numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    double closestDist = closestPairDivideAndConquer(A, 0, n - 1);

    cout << "The closest distance between two numbers is: " << closestDist << endl;

    return 0;
}

