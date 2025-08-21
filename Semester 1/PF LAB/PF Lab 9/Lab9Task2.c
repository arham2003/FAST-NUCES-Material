#include <stdio.h>
char replace(char *str, char repchar, char newcharacter);
int main (){
	char str[100], repchar, newchar;
	
	printf("Enter String: \n");
	gets(str);
	
	printf("Enter character to be replaced: \n");
	scanf(" %c",&repchar);
	
	printf("Enter replacement character: \n");
	scanf(" %c",&newchar);
	
	replacement(str,repchar,newchar);
	
	printf("Output: %s", str);
	return 0;
}

char replacement(char *str, char repchar, char newcharacter){
	int i;
	
	for(i=0; str[i] != '\0';i++){
		if (str[i] == repchar)
		str[i] = newcharacter;
	}
	
}
