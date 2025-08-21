#include <stdio.h>
#include <math.h>
int reverse(long int x);
int main(){
	long int n,tempN=0,reversed;
	double finalN=0;
	
	printf("Enter a number:\n");
	scanf("%ld",&n);
	
	tempN = n;
	
	reversed = reverse(n);
	printf("%ld\n",reversed);
	
	finalN = finalN + pow(tempN,reversed);
	printf("The big value: %lld\n",finalN);
	
	finalN = fmod(finalN, 1000000007);
	
	printf("Output: %.0lf\n",finalN);
	return 0;
}

	int reverse(long int x){
	int reverse = 0, remainder;
	while (x != 0) {
    remainder = x % 10;
    reverse = reverse * 10 + remainder;
    x /= 10;
  }
  return reverse;
}
