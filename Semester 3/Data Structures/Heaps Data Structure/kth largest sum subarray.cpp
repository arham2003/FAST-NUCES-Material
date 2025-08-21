#include <iostream>
#include <queue>
using namespace std;
// l: starting index
// r: last index
// k: find kth smallest element
int kthLargest(int arr[],int k){
	//creates min heap
	priority_queue<int,vector<int>, greater<int> > mini;
	
	int n = pq.size();
	for(int i = 0; i< n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			
			sum += arr[j];
			
			if(mini.size() < k){
				mini.push(sum);
			}
			else{
				if(sum > mini.top()){
					mini.pop();
					mini.push(sum);
				}
			}
		}
	}
	
	return mini.top();
}

int main(){
	int n;
	cout<< "no. of elements in arr: ";
	cin>> n;
	cout<<endl;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}cout<<endl;
	
	int k;
	cout << "Enter the value of k: ";
	cin>>k;
	cout<<endl;
	int answer = kthLargest(arr,k);
	cout<<"Kth largest Sum Subarray is: "<< answer;
}
