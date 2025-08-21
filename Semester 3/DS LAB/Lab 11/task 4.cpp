#include <iostream>
using namespace std;
class NutBoltMatcher {
private:
    char order[8] = {'#', '$', '%', '&', '*', '@', '^', '~'};

    // Partition the bolts based on the pivot nut
    int partition(char bolts[], int low, int high, char pivot) {
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (bolts[j] < pivot) {
                i++;
                swap(bolts[i], bolts[j]);
            } else if (bolts[j] == pivot) {
                swap(bolts[j], bolts[high]);
                j--;
            }
        }

        swap(bolts[i + 1], bolts[high]);
        return i + 1;
    }

    // Use the last bolt as a pivot to partition nuts
    int partitionNuts(char nuts[], int low, int high, char pivot) {
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (nuts[j] < pivot) {
                i++;
                swap(nuts[i], nuts[j]);
            } else if (nuts[j] == pivot) {
                swap(nuts[j], nuts[high]);
                j--;
            }
        }

        swap(nuts[i + 1], nuts[high]);
        return i + 1;
    }

    // Perform quicksort on nuts and bolts
    void matchHelper(char nuts[], char bolts[], int low, int high) {
        if (low < high) {
            
            int pivotIndex = partitionNuts(nuts, low, high, bolts[high]);

           
            partition(bolts, low, high, nuts[pivotIndex]);

            
            matchHelper(nuts, bolts, low, pivotIndex - 1);
            matchHelper(nuts, bolts, pivotIndex + 1, high);
        }
    }

public:
    // Match nuts and bolts
    void match(char nuts[], char bolts[], int n) {
        matchHelper(nuts, bolts, 0, n - 1);
    }

    // Display the matched nuts and bolts
    void display(char arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    NutBoltMatcher matcher;

    char nuts[] = {'@', '%', '$', '#', '^'};
    char bolts[] = {'%', '@', '#', '$', '^'};
    int n = 5;

    matcher.match(nuts, bolts, n);

    cout << "Matched nuts: ";
    matcher.display(nuts, n);

    cout << "Matched bolts: ";
    matcher.display(bolts, n);

    return 0;
}

