// 22k-4080

#include <iostream>

using namespace std;

	struct date{
		int day;
		int month;
		int year;
	};
int main(){
	int i,n,j,smallest;
	
	cout<<"Enter size of array: "<<endl;
	cin>>n;
	date d[n];
	
	for (i=0;i<n;i++){
		cout<<"Enter Day "<<i+1<<": ";
		cin>>d[i].day;
		cout<<"Enter month "<<i+1<<": ";
		cin>>d[i].month;
		cout<<"Enter Year "<<i+1<<": ";
		cin>>d[i].year;
	}
	
	for(j=0;j<n-1;j++){
		smallest = j;
		for(i=j;i<n;i++){
			if(d[i].year<d[smallest].year){
				smallest=i;
			}
		}
				swap(d[j],d[smallest]);
	}
	
	cout << "Sorted Dates:" << endl;
	for(i=0;i<n;i++){
		cout<<d[i].day<<"/"<<d[i].month<<"/"<<d[i].year<<endl;
	}
	
	return 0;
}
