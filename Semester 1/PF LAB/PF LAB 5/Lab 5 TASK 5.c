#include <stdio.h>
#include <math.h>
int main (){
	int lightintensity;
	
	printf("Enter sunlight intensity: \n");
	scanf("%d",&lightintensity);
	
	if (lightintensity >= 100 && lightintensity <= 500){
		printf("it's Lighting ");
	}
	else if (lightintensity >= 0 && lightintensity <100){
		printf("It's evening");
	}
	else if (lightintensity > 500){
		printf("exposed under sunshine.");
	}
	else if (lightintensity > 1000 && lightintensity < 0){
		printf("Enter a valid sunlight intensity:");
	}
	
	return 0;
}
