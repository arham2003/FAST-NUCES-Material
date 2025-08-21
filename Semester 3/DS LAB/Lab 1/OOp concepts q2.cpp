// 22k-4080
#include <iostream>
using namespace std;

	class BankAccount{
		public:
			int balance;
			BankAccount(){
				cout<<"Balance=0.00";
			}
			BankAccount(int bal){
				balance = bal;
				cout<<"\nParametrized Constructors Balance: "<<balance;
			}
			BankAccount(BankAccount &acc2){
				balance = acc2.balance;
				cout<<"\n copy constructor";
				balance = balance - 200;
				cout<<" Remaining Balance = "<<balance<<"\n";
			}
			
			void printBalance(){
				cout<<"\n Current balance: "<<balance;
			}
			
		
	};
int main(){
	BankAccount account1;
	BankAccount account2(500);
	BankAccount account3(account2);
	
	cout<<"\n Account 1 Balance: ";
	account1.printBalance();
	cout<<"\n Account 2 Balance: ";
	account2.printBalance();
	cout<<"\n Account 3 Balance: ";
	account3.printBalance();
}
