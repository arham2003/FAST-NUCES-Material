#include <stdio.h>
#include <string.h>
int main (){
	int i,j,k,digit[4],score=0,value=0;
	char table[5][6], str[20];
	//printf("Enter User ID (4 digits): \n");
	//scanf("%d",&digit);
	
	for(i=0;i<=4;i++){
		for(j=0;j<=5;j++){
			table[i][j] = (rand()%26)+65;
		}
	}
	
		for(i=0;i<=4;i++){
		for(j=0;j<=5;j++){
			if(i==4 && j==0){
				table[i][j] = '4';
			}
			if(i==4 && j==1){
				table[i][j] = '0';
			}
			if(i==4 && j==2){
				table[i][j] = '8';
			}
			if(i==4 && j==3){
				table[i][j] = '0';
			}
		}
	}
	
	for(i=0;i<=4;i++){
		printf("\n");
		for(j=0;j<=5;j++){
			printf(" %c",table[i][j]);
			
		}
	}
	
	
	do{
	
		printf("\nEnter search string: \n");
		fgets(str, sizeof(str), stdin);
		
		int len = sizeof(str)/sizeof(str[0]);
		int i;
		
		for(i = 0; i < len; i++)
		{
			for(i=0;i<=4;i++){
					for(j=0;j<=5;j++){
								if(strcmp(str[i], table[i][j]) == 0){
								score = score + 1;
								}
								else{
								score = score - 1;
								}
					
		  					}
		 				} 
		}
			
				printf("The score is: %d",score);
	 }while (str != "END");
		if(str == "END"){
			for(i=0;i<=4;i++){
			for(j=0;j<=5;j++){
			table[i][j] = (rand()%26)+65;
				}
			}	
		}
	 
	 
	return 0;
}


