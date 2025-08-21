#include <iostream>
using namespace std;

int firstocc(int arr[], int n, int key){
	
	int s = 0;
	int e = n-1;
	int mid = s + (e-s)/2;
	int ans = -1;
	while (s<=e){
		
		if(arr[mid]  == key){
			ans = mid;
			e = mid - 1;
		}
		
		else if(key > arr[mid]){
			s = mid + 1;
		}
		else{
			e = mid -1;
		}
		mid = s + (e-s)/2;
		
	}
	return ans;
}

int lastocc(int arr[], int n, int key){
	
	int s = 0;
	int e = n-1;
	int mid = s + (e-s)/2;
	int ans = -1;
	
	while (s<=e){
		
		if(arr[mid]  == key){
			ans = mid;
			s = mid + 1;
		}
		else if(key > arr[mid]){
			s = mid + 1;
		}
		else{
			e = mid -1;
		}
		mid = s + (e-s)/2;
		
	}
	return ans;
}

int pivot(int arr[], int n){
	
	int s = 0;
	int e = n-1;
	int mid = s + (e-s)/2;
	
	while (s<e){
		
		
		if(arr[mid] > arr[e]){
			s = mid + 1;
		}
		else{
			e = mid;
		}
		mid = s + (e-s)/2;
		
	}
	return arr[s];
}



int main(){
	int even[8] = {4,1,3,3,3,3,3,5};
	
	int firstOcc = firstocc(even, 8, 3);
	int lastOcc = lastocc(even, 8, 3);
	int TotalOcc = (lastOcc - firstOcc) + 1;
	int pivotElement = pivot(even, 6);
	cout<<"First Occurence of 3 is at Index "<<firstOcc<<endl;
	cout<<"Last Occurence of 3 is at Index "<<lastOcc<<endl;
	cout<<"Total Occurence of 3 is  "<<TotalOcc<<endl;
	cout<<"pivot Element is  "<<pivotElement<<endl;
}
