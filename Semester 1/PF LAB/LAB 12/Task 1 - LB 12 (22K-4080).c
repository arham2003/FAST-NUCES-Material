#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,n;
	int *numPointer;
	printf("Enter total desired elements: ");
	scanf("%d", &n);


  numPointer = (int *)calloc(n, sizeof(int));
  if (numPointer == NULL) {
    printf("Error!! memory not allocated.");
    exit(1);
  }


  for (i = 0; i < n; ++i) {
    printf("Enter num %d: ", i + 1);
    scanf("%d", numPointer + i);
  }


  for (i = 1; i < n; ++i) {
    if (*numPointer < *(numPointer + i)) {
      *numPointer = *(numPointer + i);
    }
  }
  printf("Largest number = %d", *numPointer);

  free(numPointer);

  return 0;
}
