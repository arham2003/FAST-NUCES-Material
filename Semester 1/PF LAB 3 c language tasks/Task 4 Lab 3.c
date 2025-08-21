#include  <stdio.h>

int main(){
	int dist1 = 1207;
	int dist2 = 1207;
	int fuelavg;
	
	printf("Enter Your car's fuel average\n");
	scanf("%d",&fuelavg);
	
	if (fuelavg < 0){
		printf("Error: Enter a postive value\n");
	}
	
	if (fuelavg >= 0){
		
	int fuelAB = 118;
	int fuelBA = 123;
	int totalfuelconsumed, totalcost, fuelconsumed;
	
	fuelconsumed = (dist1 / fuelavg);
	totalfuelconsumed = fuelconsumed * 2;
	
	totalcost = (fuelconsumed * fuelAB) + (fuelconsumed * fuelBA);
	
	printf("The total fuel consumed is %d litre \n", totalfuelconsumed);
	printf("The total fuel cost is Rs.%d", totalcost);
}
	return 0;
	
	
	
}

