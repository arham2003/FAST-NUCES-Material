#include <stdio.h>
#include <string.h>
void consonant(char arr[], int size, const int n) //function if word starts with consonant or y
{
	int arr2[100];
	int i, j = 0;
	
	for (i = 0; i < size; i++)
	{
		arr2[i] = arr[i];
	}
	
	for (i = 0, j = 2; j < size; i++, j++)
	{
		arr[j] = arr2[i];
	}
	
	for (i = 0, j = size - 2; i < 2; i++, j++)
	{
		arr[i] = arr2[j];
	}
	
	arr[size] = 'a';
	arr[size + 1] = 'y';
	arr[size + 2] = '\0';
	
}

void yvowel(char arr[], int size, int flag) //function in case of y as a vowel
{
	char arr2[100];
	int i, j = 0;
	
	for (i = 0; i < size; i++)
	{
		arr2[i] = arr[i];
	}
	
	for (i = flag, j = 0; i < size; i++, j++)
	{
		arr[j] = arr2[i];
	}
	
	for (i = 0, j = size - flag; j < size; i++, j++)
	{
		arr[j] = arr2[i];
	}
	
	arr[size] = 'a';
	arr[size + 1] = 'y';
	arr[size + 2] = '\0';
}

void schToSk(char arr[], int size) //function to change sch to sk
{
	int arr2[100];
	int i, j = 0;
	
	for (i = 0; i < size; i++)
	{
		arr2[i] = arr[i];
	}
	
	for (i = 3, j < 0; i < size; i++, j++)
	{
		arr[j] = arr[i];
	}
	
	arr[size - 3] = 's';
	arr[size - 2] = 'k';
	arr[size - 1] = 'a';
	arr[size] = 'y';
	arr[size + 1] = '\0';
}
	

int main()
{
	char inputStr[200];
	printf("Name: Muhammad Arham Hussain Khan\t ID:22k-4080\n");
	printf("Enter sentence to Encrypt: ");
	fflush(stdin);
	gets(inputStr);
	
	//checking length of sentence to make code efficient
	int i;
	int length = 0;
	for (i = 0; i < 200; i++)
	{
		if (inputStr[i] != '\0')
		{
			length++;
		} else break;
	}

 	//counting spaces to count words, then to generate 2D array to store words in it
	int spaces = 0;
	for (i = 0; i < length; i++)
	{
		
		if (inputStr[i] == 32)
		{
			spaces++;
		} else continue;
		
	}
	
	//copying individual words in 2D array
	int j, k;
	int wordnum = spaces + 1;
	char words[wordnum][15];
		i = 0;
		k = 0;
		for (j = 0; j < length; j++)
		{
			
			if (inputStr[j] == 32)
				{
					i++;
					k = 0;
					continue;
				} 
			else 
				{
					words[i][k] = inputStr[j];
					k++;
				}
			
		}
	//for calculating length of each word
	int len[30] = { 0 };
	for (i = 0; i < wordnum; i++)
	{
		
		for (j = 0; j < 20; j++)
		{
			if ((words[i][j] >= 65 && words[i][j] <= 90) || (words[i][j] >= 97 && words[i][j] <= 122))
			{
				len[i]++;	
			} else break;
			
		}
	}
	int flag, l, yflag = 0;
	//Encrypting each word seperately
	for (i = 0; i < wordnum; i++)
	{
		for (j = 0; j < len[i]; j++)
		{	
			//Y first letter
			if (words[i][0] == 'y' || words[i][0] == 'Y')
			{
				consonant(words[i], len[i], 2);
				break;
			}
			 else if (words[i][0]=='A' || words[i][0]=='a' || words[i][0]=='E' || words[i][0]=='e' //starts with vowel 
	     	|| words[i][0]=='I' || words[i][0]=='i' || words[i][0]=='O'
	     	|| words[i][0]=='o' || words[i][0]=='U' || words[i][0]=='u')
			{
				words[i][len[i]] = 'w';
	     		words[i][len[i] + 1] = 'a';
	     		words[i][len[i] + 2] = 'y';
	     		words[i][len[i] + 3] = '\0';
	     		break;
			} else if ((words[i][0] == 's' || words[i][0] == 'S') && words[i][1] == 'c' && words[i][2] == 'h') //schToSk to sk
			{
				schToSk(words[i], len[i]);
				break;
			} else //starts with consonant
			{
				for (l = 1; l < len[i]; l++)
				{
					if (words[i][l] == 'y' || words[i][l] == 'Y')
						yflag = 1;
						flag = 0;
						{	for (k = 0; k < len[i]; k++)
							{
								if (words[i][k]=='A' || words[i][k]=='a' || words[i][k]=='E' || words[i][k]=='e' 
		     					|| words[i][k]=='I' || words[i][k]=='i' || words[i][k]=='O'
		     					|| words[i][k]=='o' || words[i][k]=='U' || words[i][k]=='u')
		     					{
		     						flag = k;
		     						break;
								}	
							}							
								
						}
						
					
				}
				
				
			}
			if (yflag != 1)
				{
					consonant(words[i], len[i], 2);
					break;
				} else 
				{
					yvowel(words[i], len[i], flag);
					break;
				}
			
		}
	}
	
	
	for (i = 0; i < wordnum; i++) //toggling case 
	{
		for (j = 0; j < len[i]; j++)
		{
			if (words[i][j] >= 65 && words[i][j] <= 90)
			{
				words[i][j] = words[i][j] + 32;
				words[i][0] = words[i][0] - 32;
				break;
			}
		}
	}
	printf("String after encryption: 22K-4080 ");
	for (i = 0; i < wordnum; i++)
	{
		printf("%s ", words[i]);
	}
	
	return 0;
}
