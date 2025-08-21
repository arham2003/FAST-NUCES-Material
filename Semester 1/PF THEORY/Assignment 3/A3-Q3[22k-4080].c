#include <stdio.h>
#include <string.h>

struct student
{
	char StdID[9];
	char Name[40];
	float Quiz;
	float Assigment;
	float MidOne;
	float MidTwo;
	float Final;
	float GPA;
};

struct ClassInfo
{
	int TotalStudents;
	float MidOne;
	float MidTwo;
	float Final;
	float CalAverage;
};

int NoOfStudents = 7;

char PrintOptMenu();

void accumulateEvaluations(struct student allStudents[], int index, char task);

float getGPA(float total);

void smartFind(struct student allStudents[], char str[40]);

int main()
{
	int i,j;
	char task;

	struct student data[NoOfStudents];
	struct ClassInfo record = {NoOfStudents, 0, 0, 0, 0};

	float max = 0;
	char maxId[9];

	int fail = 0;
	char failed[NoOfStudents][9];

	char str[40];

	for (i = 0; i < NoOfStudents; i++)
	{
		float total = 0;
		printf("Enter data for %d Student ", i + 1);

		// Student ID
		printf("\nEnter student ID :- ");

		fflush(stdin);
		gets(data[i].StdID);
		fflush(stdin);

		for (j = 0; j < i; j++)
		{
			if (strcmp(data[i].StdID, data[j].StdID) == 0)
			{
				printf("\nStudent ID already exists, Please Enter Data For Another Student\n");
				printf("\nEnter student ID again: ");
				fflush(stdin);
				gets(data[i].StdID);
				j = i;
			}
		}

		// Student Name
		printf("\nEnter Student Name: ");
		fflush(stdin);
		gets(data[i].Name);
		fflush(stdin);

		// Student Scores
		printf("\nEnter marks scored in Quiz: ");
		scanf("%f", &data[i].Quiz);

		printf("\nEnter marks scored in Assigment: ");
		scanf("%f", &data[i].Assigment);

		printf("\nEnter marks scored in MidOne: ");
		scanf("%f", &data[i].MidOne);
		record.MidOne += data[i].MidOne;

		printf("\nEnter marks scored in MidTwo: ");
		scanf("%f", &data[i].MidTwo);
		record.MidTwo += data[i].MidTwo;

		printf("\nEnter marks scored in Final: ");
		scanf("%f", &data[i].Final);
		record.Final += data[i].Final;

		total += data[i].Quiz + data[i].Assigment + data[i].MidOne + data[i].MidTwo + data[i].Final;

		if (total < 50)
		{
			strcpy(failed[fail], data[i].StdID);
			fail++;
		}

		record.CalAverage += total;

		if (total > max)
		{
			max = total;
			strcpy(maxId, data[i].StdID);
		}
	}

	task = PrintOptMenu();
	char ID[9];

	while (task != 'e')
	{
		switch (task)
		{
		case 'a':
			printf("\nMy Name is:Muhammad Arham Hussain Khan  ID: 22K-4080\n");
			printf("\tID\tName\tGPA\n");
			for (i = 0; i < NoOfStudents; i++)
			{
				accumulateEvaluations(data, i, task);
				printf("\n");
			}
			break;

		case 'g':
			printf("Enter ID you wish to view GPA of: ");

			fflush(stdin);
			gets(ID);
			fflush(stdin);

			for (i = 0; i < NoOfStudents; i++)
			{
				if (strcmp(ID, data[i].StdID) == 0)
				{
					printf("\nMy Name:Muhammad Arham Hussain Khan  ID: 22K-4080\n\n");
					printf("\tID\tName\tGPA\n");
					accumulateEvaluations(data, i, task);
					break;
				}
			}
			break;

		case 's':
			record.MidOne /= NoOfStudents;
			record.MidTwo /= NoOfStudents;
			record.Final /= NoOfStudents;
			record.CalAverage /= NoOfStudents;
			printf("Total student TotalStudents is: %d\n", record.TotalStudents);
			printf("Average score mid 1 is: %.2f\n", record.MidOne);
			printf("Average score mid 2 is: %.2f\n", record.MidTwo);
			printf("Average score Final is: %.2f\n", record.Final);
			printf("Average total score is: %.2f\n", record.CalAverage);
			printf("Student ID %s has max score of %.2f\n", maxId, max);
			printf("List of student IDs who did not pass the course: \n");
			for (i = 0; i < fail; i++)
			{
				puts(failed[i]);
			}
			printf("\nThank you, my ID is 22K-4080 and my Name is Muhammad Arham\n");
			break;

		case 'f':
			for (i = 0; i < NoOfStudents; i++)
			{
				accumulateEvaluations(data, i, task);
			}
			printf("\nEnter student Id/Name you wish to find data of: ");
			fflush(stdin);
			gets(str);
			printf("\nMy Name is:Muhammad Arham  ID: 22K-4080 Function being called: Smart Find\n\n");
			smartFind(data, str);
			break;

		case 'r':
			strcpy(data[7].StdID, "22K-4080");
			strcpy(data[7].Name, "Muhammad Arham");
			data[7].Quiz = 8.0;
			data[7].Assigment = 9.0;
			data[7].MidOne = 11.5;
			data[7].MidTwo = 10.87;
			data[7].Final = 48.0;
			data[7].GPA = 3.67;
			printf("\nMy details:\n");
			printf("\n\nID\tName\tQuiz\t Assigment\tMidOne\tMidTwo\tFinal\tGPA\n");
			printf("%s\t%s\t%.2f\t %.2f\t%.2f\t%.2f\t%.2f\t%.2f points\n", data[7].StdID, data[7].Name, data[7].Quiz, data[7].Assigment, data[7].MidOne, data[7].MidTwo, data[7].Final, data[7].GPA);
			break;
		}
		task = PrintOptMenu();
	}
}
char PrintOptMenu()
{
	char task;
	printf("\n");
	printf("\nEnter appropriate letter for your choice of action:");
	printf("\n g. For printing GPA of a specific student ID.");
	printf("\n a. For printing GPA of all students in a tabular form.");
	printf("\n r. For replacing the details of the student at the 7th index by your exact data.");
	printf("\n f. For finding the details of a student using smartFind() function.");
	printf("\n s. For printing the statistics of the class.");
	printf("\n e. Exit the program\n");
	printf("Enter here: ");
	scanf(" %c", &task);
	printf("\n\n");
	return task;
}
void accumulateEvaluations(struct student allStudents[], int index, char task)
{
	float total = 0;
	total += allStudents[index].Quiz + allStudents[index].Assigment + allStudents[index].MidOne + allStudents[index].MidTwo + allStudents[index].Final;
	float GPA = getGPA(total);
	allStudents[index].GPA = GPA;

	if (task != 'f')
		printf("\t%s\t%s\t%.2f points", allStudents[index].StdID, allStudents[index].Name, GPA);
}

float getGPA(float total)

{
	float GPA;
	if (total >= 86)
	{
		GPA = 4.00;
	}
	else if (total >= 74)
	{
		GPA = 3.00;
	}
	else if (total >= 62)
	{
		GPA = 2.0;
	}
	else if (total >= 50)
	{
		GPA = 1.00;
	}
	else
		GPA = 0.00;

	return GPA;
}

void smartFind(struct student allStudents[], char str[40])
{
	int i;
	printf("\n\nID\t\tName\t\tQuiz\t Assigment\tMidOne\tMidTwo\tFinal\tGPA\n");
	for (i = 0; i < NoOfStudents; i++)
	{
		if ((strcmp(strlwr(allStudents[i].StdID), strlwr(str)) == 0) || (strcmp(strlwr(allStudents[i].Name), strlwr(str)) == 0))
		{
			printf("%s\t%s\t%.2f\t %.2f\t\t%.2f\t%.2f\t%.2f\t%.2f points\n", allStudents[i].StdID, allStudents[i].Name, allStudents[i].Quiz, allStudents[i].Assigment, allStudents[i].MidOne, allStudents[i].MidTwo, allStudents[i].Final, allStudents[i].GPA);
			return;
		}
	}
}
