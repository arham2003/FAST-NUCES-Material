#include  <stdio.h>

int main(){
	int user1, user2, swap;
	
	printf("Enter two integers\n");
	scanf("%d%d",&user1,&user2);
	
	printf("Before Swapping\n First integer=%d\n Second Integer=%d\n", user1,user2);
	
	swap = user1;
	user1 = user2;
	user2 = swap;
	
	printf("AfterSwapping\n First integer= %d\nSecond Integer = %d\n", user1,user2);
	
	return 0;
	
}

