#include  <stdio.h>

int main(){
	int taxrate, salary;
	
	printf("Enter Tax rate\n =");
	scanf("%d", &taxrate);
	
	printf("Enter Salary\n =");
	scanf("%d", &salary);
	
	float taxapplied = salary * taxrate / 100;
	float Salaryafter = salary - taxapplied;
	
	printf(" \n Salary after paying the tax = %.1lf \n ", Salaryafter);
	printf("Tax = %.1lf",taxapplied, Salaryafter);
	
	return 0;
}
