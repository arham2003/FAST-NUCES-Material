#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i){
	
	int largest= i;
	int left= 2*i;
	int right = 2*i+1;
	
	if(left <= n && arr[largest] < arr[left]){
		largest = left;
	}
	if(right <= n && arr[largest] < arr[right]){
		largest = right;
	}
	
	if(largest != i){
		
		swap(arr[largest],arr[i]);
		heapify(arr,n,largest);
	}
}
void heapSort(int arr[], int n){
	int t= n;
	
	while(t> 1){
		swap(arr[t],arr[1]);
		t--;
		
		heapify(arr, t, 1);
	}
}

int main(){
	int arr[6] = {-1,55,53,12,4,7};
	
	int n = 5;
	int k;
	cout<<"Enter the kth element: ";
	cin >> k;
	for(int i=n/2;i>0;i--){
		heapify(arr,n,i);
	}
	
	heapSort(arr,n);
	cout<<"Printing sorted array "<< endl;
	for(int i=0;i<=n;i++){
		cout << arr[i] <<" ";
	}cout<<endl;
	
	
	cout<<"Kth smallest element is: " << arr[k-1] << endl;
}
