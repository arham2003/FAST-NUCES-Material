#include <iostream>
#include <vector>
using namespace std;

int main(){
	
	vector<int> v;
	cout<<"Size: "<<v.capacity()<<endl;
	
	v.push_back(1);
	cout<<"Capacity: "<<v.capacity()<<endl;
	
	v.push_back(2);
	cout<<"Capacity: "<<v.capacity()<<endl;
	
	v.push_back(3);
	cout<<"Capacity: "<<v.capacity()<<endl;
	
	v.push_back(4);
	cout<<"Capacity: "<<v.capacity()<<endl;
	
	v.push_back(5);
	cout<<"Capacity: "<<v.capacity()<<endl;  //capacity tells how much space is assigned for elements
	cout<<"Size: "<<v.size()<<endl;  // size tells how many elements are there
	
	cout<<"Front: "<<v.front()<<endl;
	cout<<"back: "<<v.back()<<endl;
	
	
	
}
