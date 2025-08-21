#include <stdio.h>
int main (){
	int max,num1,num2,LCM,GCD,i;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    // maximum number between num1 and num2 is stored in max
    max = (num1 > num2) ? num1 : num2;

        if ((max % num1 == 0) && (max % num2 == 0)) {
            printf("The LCM of %d and %d is:\n%d.\n", num1, num2, max);

        }

// loop to find the GCD
    for (i = 1; i <= num1 && i <= num2; ++i) {
        // check if i is a factor of both integers
        if (num1 % i == 0 && num2 % i == 0)
            GCD = i;
    }
    
    printf("GCD of %d and %d is:\n%d \n", num1, num2, GCD);
	return 0;
}
