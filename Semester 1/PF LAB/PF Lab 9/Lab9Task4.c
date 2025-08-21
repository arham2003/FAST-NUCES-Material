#include <stdio.h>
int upperCase(char n1[]);
int lowerCase(char n2[]);
int blankSpaces(char n3[]);
int main (){
	char str[20];
	int count1=0, count2=0, count3=0;
	printf("Enter a string: \n");
	scanf("%[^\n]s",&str);
	
	count1 = upperCase(str);
	count2 = lowerCase(str);
	count3 = blankSpaces(str);
	
	printf("The number of uppercase letters are: %d\n",count1);
	printf("The number of lowercase letters are: %d\n",count2);
	printf("The number of blankspaces are: %d\n",count3);
	return 0;
}

int upperCase(char n1[]){
	int i, upperCount=0;
	for(i=0; i<20;i++){
		if(n1[i] >= 'A' && n1[i] <= 'Z'){
			upperCount = upperCount + 1;
		}
	}
		return upperCount;
}

int blankSpaces(char n3[]){
	int i, blankCount=0;
	for(i=0; i<20;i++){
		if(n3[i] == ' '){
			blankCount = blankCount + 1;
		}
	}
		return blankCount;
}

int lowerCase(char n2[]){
	int i, lowerCount=0;
	for(i=0; i<20;i++){
		if(n2[i] >= 'a' && n2[i] <= 'z'){
			lowerCount = lowerCount + 1;
		}
	}
		return lowerCount;
}
