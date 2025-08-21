#include <iostream>
using namespace std;

int firstocc(int arr[], int s, int e, int key){
	
	if(s>e)
		return -1;
			
		int mid = s + (e-s)/2;
		
		if ((mid == 0 || key > arr[mid - 1]) && arr[mid] == key	){
		
			return mid;
		}
		
		else if(key > arr[mid]){
			return firstocc(arr,mid+1,e,key);
		}
		else{
			return	firstocc(arr,s,mid-1,key);
		}
			
		
}


int lastocc(int arr[], int s, int e, int key, int n){
	
	if(s>e)
		return -1;
			
		int mid = s + (e-s)/2;
		
		if ((mid == n-1 || key < arr[mid + 1]) && arr[mid] == key){
		
			return mid;
		}
		
		else if(key < arr[mid]){
			return lastocc(arr,s,mid -1,key,n);
		}
		else{
			return lastocc(arr,mid + 1,e,key,n);
		}
			
		
}


int main(){
	int even[8] = {4,1,3,3,3,3,3,5};
	
	int firstOcc = firstocc(even,0, 7, 3);
	int lastOcc = lastocc(even,0, 7, 3,8);

	cout<<"First Occurence of 3 is at Index "<<firstOcc<<endl;
	cout<<"Last Occurence of 3 is at Index "<<lastOcc<<endl;

}
