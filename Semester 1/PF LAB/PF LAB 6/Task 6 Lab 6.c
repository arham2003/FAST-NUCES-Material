#include <stdio.h>

main (){
	int pH;
	printf("Enter pH \n");
	scanf("%d",&pH);
	
	if (pH > 7){
		 if (pH < 12){
			printf("Alkaline");
			}
			else {
				printf("Very Alkaline");
			}
			
		
			if (pH > 2){
			printf("Acidic");
			}else {
			printf("Very Acidic");
			}
		}
	else if (pH = 7){
			printf("Neutral");
		}
	
		return 0;
	}
	
		
	

