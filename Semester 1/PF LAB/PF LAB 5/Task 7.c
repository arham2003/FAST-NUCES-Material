#include <stdio.h>
int main (){
	char custName[25];
	int custID, unitsConsumed;
	float cost,surcharge, unitcost,totalcost;
	
	printf("Enter Name: \n");
	fgets(custName, sizeof(custName), stdin); //reads string
	
	printf("Enter Customer ID: \n");
	scanf("%d",&custID);
	
	printf("Enter Units Consumed: \n");
	scanf("%d",&unitsConsumed);
	
	if (unitsConsumed >0 && unitsConsumed <=199){
		unitcost = 16.2;
		cost = unitsConsumed * 16.2;
	}
	else if (unitsConsumed>=200 && unitsConsumed<300){
		unitcost = 20.1;
		cost = unitsConsumed * 20.1;
	}
	else if (unitsConsumed>=300 && unitsConsumed<500){
		unitcost = 27.1;
		cost = unitsConsumed * 27.1;
	}
	else {
		unitcost = 35.9;
		cost = unitsConsumed * 35.9;
	}
	totalcost = cost;
	
		if (cost > 18000){
			surcharge = cost * 0.15;
			totalcost = cost + surcharge;
		}
		
	printf("Customer ID: %d\n",custID);
	printf("Customer Name: ",custName);
	puts(custName); //displays string
	printf("Units Consumed: %d\n",unitsConsumed);
	printf("Amount Charges @Rs. %.2f per unit: %.2f\n",unitcost,cost);
	printf("Surcharge Amount: %.2f\n",surcharge);
	printf("Net Amount paid by customer: %.2f",totalcost);
	
	return 0;
}
