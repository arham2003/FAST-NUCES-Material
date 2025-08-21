#include <stdio.h>
int main (){
	int checkvacation , dayCheck;
	
	printf("\nPress 1 if it's weekday and 0 if not:");
	scanf("%d", &checkvacation);
	
	if (checkvacation == 1 && dayCheck == 0){
		printf("True");
	}
	else if (checkvacation == 0 && dayCheck == 1){
		printf("False");
	}
	else if (checkvacation == 0 && dayCheck == 0){
		printf("True");
	}
	else if (checkvacation == 1 && dayCheck == 0){
		printf("True");
	}
	else {
		printf("Invalid Input.");
	}
	return 0;
}
