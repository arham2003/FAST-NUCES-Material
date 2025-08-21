#include <stdio.h>
#include <math.h>
int main (){
	int age,n,i=1;
	char areatype;
	printf("Enter Number of users data you have ? \n");
	scanf("%d",&n);
	while(i<=n){
		printf("\nwhats your age ? \n");
		scanf("%d",&age);
		printf("press U for urban and R for rural\n");
		scanf(" %c",&areatype);
		if (areatype == 'U' || areatype == 'u' && age >= 18){
		printf("Eligible for the vaccine. Kindly proceed for the vaccination\n");		
		}
		else if (areatype == 'R' || areatype == 'r' && age < 18){
			printf("Not Eligible for the vaccine. Kindly wait for the vaccination\n");
		}
		else {
			printf("Sorry there is no classification for this type.");
		}
	i++;	
	}
	return 0;
	// This question can also be solved with switch case statements and While loops.
	
}
