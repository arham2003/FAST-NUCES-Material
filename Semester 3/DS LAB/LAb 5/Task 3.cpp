//22k-4080

#include <iostream>
using namespace std;
void bubbleSortPass(int arr[], int n) {
    
	for(int i = 0; i < n-1; i++){
	
    	for (int j = 0; j < n - i - 1; j++) {
        	
			if (arr[j] > arr[j + 1]) {
            	swap(arr[j], arr[j + 1]);
        	}
    	}
	}
}

// I have used indirect recursion for my own clarification
void tailedrecursiveBubbleSort(int arr[], int n) {
    if (n <= 1)
        return; // If the array has 1 or 0 elements, it's already sorted

    bubbleSortPass(arr, n);
    tailedrecursiveBubbleSort(arr, n - 1);
}

void nonTailedrecursiveBubbleSort(int arr[], int n){
	if(n <= 1)
		return;
		
	bubbleSortPass(arr,n);
	nonTailedrecursiveBubbleSort(arr, n-1);
	cout<<"\n"<<endl;
}

int main() {
    int arr[] = {60, 37, 29, 112, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
	
	int arr2[] = {60, 37, 29, 112, 22, 11, 20};
    int n2 = sizeof(arr) / sizeof(arr[0]);
    
   cout << "Unsorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    tailedrecursiveBubbleSort(arr, n);
    
   

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;


	cout<< "Unsorted Array 2 for Non-Tailed: ";
	
	for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    nonTailedrecursiveBubbleSort(arr2, n2);
    
    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    
	
    return 0;
}

