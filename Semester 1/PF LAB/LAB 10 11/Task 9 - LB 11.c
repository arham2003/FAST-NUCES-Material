#include <stdio.h>
#include <stdlib.h>

int main() {
  int i;
  int noofElem;
  int *pointer;
  printf("Enter total elements: ");
  scanf("%d", &noofElem);


  pointer = (int *)calloc(noofElem, sizeof(int));
  if (pointer == NULL) {
    printf("Error!! memory not allocated.");
    exit(0);
  }


  for (i = 0; i < noofElem; ++i) {
    printf("Enter num %d: ", i + 1);
    scanf("%ld", pointer + i);
  }


  for (i = 1; i < noofElem; ++i) {
    if (*pointer < *(pointer + i)) {
      *pointer = *(pointer + i);
    }
  }
  printf("Largest number = %.2ld", *pointer);

  free(pointer);

  return 0;
}
