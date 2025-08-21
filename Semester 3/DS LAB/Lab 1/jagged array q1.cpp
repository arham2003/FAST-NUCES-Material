// 22k-4080
#include <iostream>
using namespace std;
int main(){
/*	int *arr = new int*[3];
	int Size[3];
	int i,j,k;
	
	for(i=0;i<3;i++){
	cout<<"Row "<<i+1<< " size: ";
	cin>>Size[i];
	arr[i] =new int[Size[i]];
	}
	
	for(i=0;i<3;i++){
	for(j=0;j<Size[i];j++){
	cout<<"Enter row " <<i+1<<" elements: ";
	cin>>*(*(arr + i) + j);
		}
	}
	*/
	
	int arr[5][5];
	
	for(int i=0;i<5;i++){
		cout<<"Row "<<i+1<<":";
		for(int j=0;j<5;j++){
			cout<<"Element "<<j+1<<":\n";
			cin>>arr[i][j];
			
			
		}
	}
	
	for(int i=0;i<5;i++){
		cout<<"\n";
		for(int j=0;j<5;j++){
			cout<<arr[i][j];
		}
	}
	
	
}
