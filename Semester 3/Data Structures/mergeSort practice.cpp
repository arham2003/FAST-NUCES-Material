#include <iostream>
using namespace std;

void merge(int *arr, int s, int e){
	
	int mid = (s+e)/2;
	
	int len1 = mid-s+1;
	int len2 = e-mid;
	
	int *first = new int[len1];
	int *second = new int[len2];
	
	int mainArrIndex = s;
	
	for(int i = 0;i<len1;i++){
		first[i] = arr[mainArrIndex++];
	}
	mainArrIndex = mid+1;
	for(int i = 0;i<len2;i++){
		second[i] = arr[mainArrIndex++];
	}
	
	// merge 2 sorted
	
	int Index1 = 0;
	int Index2 = 0;
	mainArrIndex = s;
	
	while(Index1<len1 && Index2<len2){
		if(first[Index1] < second[Index2]){
			arr[mainArrIndex++] = first[Index1++];
		}
		else{
			arr[mainArrIndex++] = second[Index2++];
		}
	}
	
	while (Index1 < len1){
		arr[mainArrIndex++] = first[Index1++];
	}
	
	while(Index2 < len2){
		arr[mainArrIndex++] = second[Index2++];
	}
	
	delete []first;
	delete []second;
}

void mergeSort(int *arr, int s, int e){
	if(s>=e){
		return;
	}
	
	int mid = (s+e)/2;
	
	//left part sort
	
	mergeSort(arr,s,mid);
	
	mergeSort(arr,mid+1,e);
	
	//merge
	
	merge(arr,s,e);
}

int main(){
	int arr[8] = {12,45,22,52,553,21,431,81};
	int n = 8;
	
	mergeSort(arr, 0, n-1);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
			
	}
	cout<<endl;
	
	return 0 ;
}
