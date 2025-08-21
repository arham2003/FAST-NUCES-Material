#include <stdio.h>

main (){
	float GPA;
	printf("Enter your GPA: \n");
	scanf("%f",&GPA);
	if (GPA >= 0 && GPA <= 4){
	
		if (GPA >= 0.0 && GPA <= 0.99){
			printf("Failed semester—registration suspended\n");
		}
		if (GPA >= 1.0 && GPA <= 1.99){
			printf("On probation for next semester\n");
		}
		if (GPA >= 2.0 && GPA <= 2.99){
			printf("(no message)\n");
		}
		if (GPA >= 3.0 && GPA <= 3.49){
			printf("Dean's List for semester'\n");
		}
		if (GPA >= 3.5 && GPA <= 4.00){
			printf("Highest honors for semester");
		}		
	}
	else {
		printf("Enter valid Grade Point Average");
	}
		return 0;
}
	
		
	

