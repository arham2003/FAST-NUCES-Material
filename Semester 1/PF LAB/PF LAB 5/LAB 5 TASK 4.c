#include <stdio.h>
#include <math.h>
int main (){
	int itemcost; 
	float discount, discountedprice, discountgiven;
	printf("Enter the cost of items: \n");
	scanf("%d",&itemcost);
	if (itemcost<2000){
		discount=0.05;
		discountgiven=discount*itemcost;
		discountedprice=itemcost - discountgiven;
	}
	else if (itemcost >=2000 && itemcost < 4000){
		discount=0.1;
		discountgiven=discount*itemcost;
		discountedprice=itemcost - discountgiven;
	}
	else if (itemcost >= 4000 && itemcost < 6000){
		discount=0.2;
		discountgiven=discount*itemcost;
		discountedprice=itemcost - discountgiven;
	
	}
	else if (itemcost >= 6000){
		discount=0.35;
		discountgiven=discount*itemcost;
		discountedprice=itemcost - discountgiven;
	}

	
	printf("The Actual price: %d\n",itemcost);
	printf("The Amount Saved is: %.2lf\n",discountgiven);
	printf("The Amount after discount is: %.2lf",discountedprice);

}

