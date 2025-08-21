// 22k-4080
#include <iostream>
using namespace std;

int indirectRecFun1(int n){
	
	if(n>-1 && n <= 1){
		return n;
	}
	else{
		return indirectRecFun1(n-1) + indirectRecFun1(n-2);
	}
}

int indirectRecFun2(int n){
	
	return indirectRecFun1(n);
}

int main(){
	int n ;
	cout<< "how many terms you want? (term starts from 0)" << endl;
	cin >> n;
	cout << "Fibonacci Series: " << endl;
	
	for(int i = 0; i<=n;i++){
		cout << indirectRecFun2(i) << ", ";
	}
	cout<<endl;
	cout<< "Indirect Approach Succesful!!";
	return 0;
}
