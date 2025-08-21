#include <iostream>
using namespace std;

int arrSum(int *arr, int size){
	int sum = 0;
	
	if(size<=0)
		return sum;
		
	sum = arrSum(arr,size-1)  + arr[size-1];
	return sum;
}

int main(){
	int arr[5] = {2,4,9,9,6};
	int size = 5;
	
	int ans = arrSum(arr,size);
	
	cout<<"Sum is "<<ans<<endl;
}
