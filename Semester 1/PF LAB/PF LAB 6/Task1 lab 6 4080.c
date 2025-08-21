#include<stdio.h>
int main (){

	float calories, fgram, totalcalories, perCalories,x;
	char c=37;
	printf("Enter no. of Calories: \n");
	scanf("%f",&totalcalories);
	printf("Enter fat grams in food: \n");
	scanf("%f",&fgram);
	
	
	if (totalcalories >= 0 && fgram >= 0){
		calories = fgram * 9;
		x = calories * 100;
		if (calories < totalcalories){
			perCalories = x / totalcalories ;
		}
		else {
			printf("Either the calories or fat grams were incorrectly entered.\n");
		}
		printf("Percentage of calories is : %.3lf%c",perCalories,c);
	}
	return 0;
	
	
}
