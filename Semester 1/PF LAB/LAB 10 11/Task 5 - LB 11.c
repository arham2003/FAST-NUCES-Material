#include <stdio.h>
struct Register{
	char course_id[20];
	char course_name[20];
};
struct Student{
	char std_id[20];
	char firstName[20];
	char lastName[20];
	int cell_no;
	char email[20];
	struct Register r;
};
int main()
{
	int numStudent,i;
	printf("Enter number of students: \n");
	scanf("%d",&numStudent);
	struct Student st[numStudent];
	for(i=0;i<numStudent;i++){
		printf("Enter student's id, first name, last name, cell no, email, course id, and course name\n");
		scanf("%s %s %s %d %s %s %s",&st[i].std_id,&st[i].firstName,&st[i].lastName,&st[i].cell_no,&st[i].email,&st[i].r.course_id,&st[i].r.course_name);
	}
	printf("\n");
	for(i=0;i<numStudent;i++){
		printf("Student %d info: \n",i+1);
		printf("%s %s %s %d %s %s %s\n\n",st[i].std_id,st[i].firstName,st[i].lastName,st[i].cell_no,st[i].email,st[i].r.course_id,st[i].r.course_name);
	}
	return 0;
}
