#include <stdio.h>

main (){
	int x;
	x = 5 > 8 ? 10 : 1 != 2 < 5 ? 20 : 30 ; //Relational less than operation ( 2 < 5 ) is performed first which then is assigned a value of 20 and then relational is not equal to operation is done
	printf("Value of x: %d", x);
	return 0;
}
