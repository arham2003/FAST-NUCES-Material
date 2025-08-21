#include <iostream>

using namespace std;

int main() {
    long x;
    cin >> x;
    int minSteps = (x/5) + ((x%5) == 0 ? 0 : 1);

    // Print the result
    cout << minSteps << endl;

    return 0;
}

