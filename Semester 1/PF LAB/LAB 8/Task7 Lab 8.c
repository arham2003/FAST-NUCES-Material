#include <stdio.h>

int subArraySum(int arr[], int n, int sum)
{
	int i,j;
	sum=0;
    // Pick a starting point
    for (i = 0; i < n; i++) {
        int currentSum = arr[i];
 
        if (currentSum == sum) {
            printf("Sum found at index %d ", i);
            return;
        }
        else {
            // Try all subarrays starting with 'i'
            for (j = i + 1; j < n; j++) {
                currentSum += arr[j];
 
                if (currentSum == sum) {
                    printf("Sum found between indexes %d "
                           "and %d",i, j);
                    return;
                }
            }
        }
    }
    printf("No subarray found");
    return;
}
 
// Driver program to test above function
int main()
{
    int i,n;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int arr[size];
    for (i=0;i<size;i++){
    	printf("Enter Element %d: \n",i+1);
    	scanf("%d",&arr[i]);
	}
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    printf("Enter sum number to be found: \n");
    scanf("%d",&sum);
    subArraySum(arr, n, sum);
    return 0;
}
