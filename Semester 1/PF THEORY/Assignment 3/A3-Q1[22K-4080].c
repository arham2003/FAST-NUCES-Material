#include <stdio.h>
#include <string.h>
int main (){
	int i,j,k,digit[4],score=0;
	char table[5][6], str[20];
	//printf("Enter User ID (4 digits): \n");
	//scanf("%d",&digit);
	srand(time(NULL)); //only once

	for(i=0;i<=4;i++){
		for(j=0;j<=5;j++){
			table[i][j] = (rand()%(90-65))+65;
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
		fflush(stdin);
  		gets(str);
  		fflush(stdin);
		
		int len = strlen(str);
		int count=0;
		int k,searched=0,found=0;
		
			for(i=0;i<=4;i++){
		for(j=0;j<=5;j++){
			for(k=0;k<=len;k++){
					if(table[i][j]==str[k]){
						
										searched+=1;
							j++;
					
						}else{
						
							searched=0;
							break;
						} if(searched==len){
					    	found=1;
					    	break;}
				}if(found==1)
			     break;
			} if(found==1)
			     break;
		}
		
		
		
		
		if(found==1){
			score++;
			printf("%s is present: Score = %d\n\n",str, score);
		}
		else{
			score-=1;
	    	printf("%s is not present: Score = %d\n\n",str, score);
		}
	
	 	 

	}while(strcmp(str, "END") != 0);	
	 	 
		if (strcmp(str, "END") == 0){
			for(i=0;i<=4;i++){
			for(j=0;j<=5;j++){
			table[i][j] = (rand()%26)+65;
				}
			}
			
			for(i=0;i<=4;i++){
			printf("\n");
			for(j=0;j<=5;j++){
			printf(" %c",table[i][j]);
			
				}
			}	
		}
	 
	 
	return 0;
}


