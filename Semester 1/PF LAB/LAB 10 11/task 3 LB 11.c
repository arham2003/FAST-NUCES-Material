#include<stdio.h>
struct organisation{
	char orgname[10];
	int orgnum;
	struct employee{
		int emplid;
		char emplname[10];
		int salary;
	}empl;
};
int main(){
	struct organisation org;
	printf("Please input organisation name: \n");
	gets(org.orgname);
	printf("\nplease input organisation number: ");
	scanf("%d",&org.orgnum);
	printf("\nplease input name of employee: \n");
	scanf( " %s",&org.empl.emplname);
	printf("\nInput id:");
	scanf("\n%d",&org.empl.emplid);
	printf("Enter Salary\n");
	scanf("\n%d",&org.empl.salary);
		printf("The size of structure organisation:123\n");
	printf("Organisation Name:%s\nOrganisation Number:%d\nEmployee id:%d\nEmployee Name:%s\nEmployee salary:%d\n",org.orgname,org.orgnum,org.empl.emplid,org.empl.emplname,org.empl.salary);
	return 0;
}
