#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num,i,stuMark;
	char stuName[20];
	printf("Enter num of students: ");
	scanf("%d",&num);
	
	FILE *fptr;

	fptr = fopen("D:\\stuData.txt","w");
	if(fptr == NULL){
			printf("File not Found!");
			exit(1);
		}
	
	for(i=0; i<num; ++i){
		printf("Enter name of student %d: ",i+1);
		scanf("%s", &stuName);
		fprintf(fptr,"Name: %s\n",stuName);
		printf("Enter mark of student %d: ",i+1);
		scanf("%d",&stuMark);
		fprintf(fptr,"Marks: %d\n",stuMark);
	}

	fclose(fptr);
	
	return 0;

}
