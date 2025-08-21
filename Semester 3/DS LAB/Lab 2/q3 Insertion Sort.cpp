// 22K-4080

#include <iostream>
#include <string>
using namespace std;

int positionAssigner(string &position){
	if(position == "CEO")
	return 1;
	if(position == "CTO")
	return 2;
	if(position == "CFO")
	return 3;
	if(position == "VP")
	return 4;
	if(position == "MGR")
	return 5;
	if(position == "EMP")
	return 6;
	
	return 7;
}

void customInsertionSort(string positions[], int size){
	for (int i = 1; i < size; ++i){
        string key = positions[i];
        int j = i - 1;

        while (j >= 0 && positionAssigner(positions[j]) > positionAssigner(key)) {
            positions[j + 1] = positions[j];
            j = j - 1;
        }
        positions[j + 1] = key;
    }
}

int main(){
	
		int size;
		cout<<"Enter the number of positions: "<<endl;
		cin>>size;
		
		string designation[size];
		
		for(int i = 0; i<size;i++){
			cin>>designation[i];
		}
		
		customInsertionSort(designation,size);
		
		cout << "Sorted job positions:" << endl;
    	for (int i = 0; i < size; ++i){
        cout << designation[i] << endl;
    	}
}
