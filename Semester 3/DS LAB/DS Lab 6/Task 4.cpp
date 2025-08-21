//ID : 22k-4080
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool isSwapped;
    for (i = 0; i < n - 1; i++) {
        isSwapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }
        
        if (isSwapped == false)
            break;
    }
}

void sortedArr(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
}

int BinarySearch(int arr[], int n, int key){
	
	int s = 0;
	int e = n-1;
	int mid = s + (e-s)/2;
	
	while(s<=e){
		if(arr[mid] == key){
			return mid;
		}
		
		if(key > arr[mid]){
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
		mid = s + (e-s)/2;
	}
	return -1;
}

int main(){
	int arr[11] = {1,3,12,14,23,34,55,65,80,75,78}; //added 80 as my last two digits of id
	bubbleSort(arr,11);
	cout<<"Sorted Array: " <<endl;
	sortedArr(arr,11);
	cout<<endl;
	int valueInd = BinarySearch(arr,11,80);
	
	cout<<"The value 80 is at Index "<<valueInd<<endl;
}
