// 22k-4080
#include <iostream>

#include "matrix_multiply.h" 
using namespace N; 
using namespace std;
void matrix_multiply::do_something()
{
cout << "Doing Matrix multiplication!" << endl;
}
using namespace std;

int main(){
	int row1,column1,row2,column2;
	cout<<"First Matrix: \n";
	cout<<"Enter size of row: ";
	cin>>row1;
	cout<<"Enter size of column: ";
	cin>>column1;
	
	int matx1[row1][column1];
	cout<<"Enter first Matrix Element: ";
	
	for (int i=0;i<row1;i++){
		
		for (int j=0;j<column1;j++){
			cin>>matx1[i][j];
		}
	}
	cout<<"1st matrix:\n";
	for(int i =0;i<row1;i++){
		for (int j=0;j<column1;j++){
			cout<<matx1[i][j]<<" ";
		}
	}
	
	cout<<"\nSecond Matrix: ";
	cout<<"row size: ";
	cin>>row2;
	cout<<"column size: ";
	cin>>column2;
	
	int matx2[row2][column2];
	
	cout<<"Enter 2nd matrix Element";
	for (int i=0;i<row2;i++){
		for(int j=0;j<column2;j++){
			cin>>matx2[i][j];
		}
	}
	
	cout<<"2nd matrix:\n";
	for(int i =0;i<row2;i++){
		for (int j=0;j<column2;j++){
			cout<<matx2[i][j]<<" ";
		}
	}
	
	if(column1==row2){
		int multiply[row1][column2];
		for(int i=0;i<row1;i++){
			for(int j=0;j<column2;j++){
				multiply[i][j]=0;
				for(int k=0;k<column1;k++){
					multiply[i][j]+=matx1[i][k]*matx2[k][i];
					
				}
			}
		}
			cout<<"\nMultiplied Matrix: \n";
	for(int i=0;i<row1;i++){
		for(int j=0;j<column2;j++){
		cout<<multiply[i][j]<<" ";
		}
		cout<<"\n";
	}
	}
	else {
		cout<<"multiplication not possible";	
		}

	

}
