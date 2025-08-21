//22k-4080

#include <iostream>
using namespace std;

int Funct(int n){
		
	if(n <= 1){
		return n;
	}
	else{
		return Funct(n-1) + Funct(n-2);
	}
}

int main(){
	int n ;
	cout<< "how many terms you want?" << endl;
	cin >> n;
	cout << "Fibonacci Series: " << endl;
	
	for(int i = 0; i<=n;i++){
		cout << Funct(i) << ", ";
	}
	
	
	return 0;
}
