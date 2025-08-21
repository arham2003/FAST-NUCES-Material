#include <stdio.h>

int main () {
	int input,output,age,gender,sum;
	
	printf("Input a 4 Number :- ");
    scanf("%d",&input);

	printf("Input your Age :- ");
    scanf("%d",&age);
    
	printf("Input your Gender \n 0.) Female \n 1.) Male  :- \n");
    scanf("%d",&gender);
    if(gender == 0 || gender == 1){
      sum = input + age + gender;
	} else {
		printf("Sorry You Entered Wrong Gender");
    	return 0;
	}
    
    while(sum > 0){
    	output = output  + (sum % 10);
    	sum = sum /10;
	}
   
    int calOpt;
    printf("What is Your Calculated Ouput \n");
    scanf("%d",&calOpt);
    
    if(calOpt == (output % 5)) {
    	printf("You can Enter The Room");
	} else {
		printf("You can not Enter The Room");
	}
    
	return 0;
}