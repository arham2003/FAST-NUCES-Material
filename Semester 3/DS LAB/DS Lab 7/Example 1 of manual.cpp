#include <iostream>

using namespace std;

const int MAX=100; // size of stack

class Stack{
	int top;
	public:
		int a[MAX];
		
		Stack(){
			top = -1;
		}
		
bool push(int x);

int pop();
int peek();
bool isEmpty();
};

bool Stack:: push(int x){
	if(top>=(MAX-1)){
		cout<<"Stack overflow"<<endl;
		return false;
	}
	else{
		a[++top] = x;
		cout<<x<<" "<<endl;
		return true;
	}
}
int Stack::pop(){
	if(top<0){
		cout<<"Stack underflow"<<endl;
		return 0;
	}
	else{
		int x = top--;
		cout<<a[x]<<endl;
		return x;
	}
}

int main(){
	Stack s1;
	
	int arr[10] = {123,124,53,46,21,44,112,34,21,89};
	
	for  (int i =0;i<10;i++){
		s1.push(arr[i]);
	}
	cout<<"Now reverse:" << endl;
	
	for(int j =0 ; j<10;j++){
		s1.pop();
	}
	return 0;
}
