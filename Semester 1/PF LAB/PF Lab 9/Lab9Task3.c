#include <stdio.h>
void swap(char x[], char y[]);
int main (){
	char n1[10],n2[10];
	
	printf("Enter two variables: \n");
	//fgets(n1, sizeof(n1), stdin);
	//fgets(n2, sizeof(n2), stdin);
	scanf("%s",&n1);
	scanf("%s",&n2);
	
	swap(n1, n2);
	
	return 0;
}

void swap(char x[], char y[]){
	char i, tempchar;
	for (i=0;x[i] != '\0' && y[i] !='\0';i++){
	tempchar = x[i];
	x[i] = y[i];
	y[i] = tempchar;
	}


	printf("The swapped elements are: ");
	printf("%s %s", x, y);
}
