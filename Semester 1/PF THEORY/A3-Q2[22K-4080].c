#include <stdio.h>
#include <string.h>

char String[50];

char Arr[1000][1000];

int WordsInArr = 0;

void BreakStr();

void PrintStr();

void EncryptStr();

void ConnectString();

void ReArrangeWord(int StringLength, int i);

int main()
{
  printf("Enter String You Want To Encrypt :- ");
  gets(String);

  BreakStr();
  EncryptStr();
  PrintStr();
  ConnectString();

  return 0;
};

void ConnectString()
{
	int i;
  char AppendIdStr[1000] = "22k-4080 ";
  for (i = 0; i < WordsInArr; i++)
  {
    strcat(AppendIdStr, Arr[i]);
    strcat(AppendIdStr, " ");
  }
  puts(AppendIdStr);
};

void EncryptStr()
{
	int i,j;
  for (i = 0; i < WordsInArr; i++)
  {
    char FirstLetter = tolower(Arr[i][0]);
    int CapFirstLetter = 0;
    if (Arr[i][0] >= 'A' && Arr[i][0] < 'Z')
    {
      CapFirstLetter = 1;
    }
    int CharConsistY = 0;

    for (j = 0; j < strlen(Arr[i]); j++)
    {
      if (tolower(Arr[i][j]) == 'y')
      {
        CharConsistY++;
      }
    };

    if ((FirstLetter == 'a') || (FirstLetter == 'e') || (FirstLetter == 'i') || (FirstLetter == 'o') || (FirstLetter == 'u'))
    {
      strcat(Arr[i], "way");
    }
    else if (FirstLetter == 'y')
    {
    	ReArrangeWord(strlen(Arr[i]),i);
      //strcat(Arr[i], "yay");
    }
    else if ((FirstLetter == 's') && (tolower(Arr[i][1]) == 'c') && (tolower(Arr[i][2]) == 'h'))
    {
      char NewString[strlen(Arr[i])];
      for (j = 3; j < strlen(Arr[i]); j++)
      {
        NewString[j] = Arr[i][j];
      }

      strcat(NewString, "sk");

      strcpy(Arr[i], NewString);
    }
    else
    {
      int StringLength = strlen(Arr[i]);
      if ((StringLength % 2) == 0)
      {
        ReArrangeWord(StringLength, i);
      }
      else
      {
        ReArrangeWord((StringLength - 1), i);
      }
    }

    if (CapFirstLetter > 0)
    {
      Arr[i][0] -= 32;
    }
  }
};

void ReArrangeWord(int StringLength, int i)
{
	int j;
  char Str1[StringLength], Str2[StringLength];

  for (j = 0; j < ((StringLength / 2) + 1); j++)
  {
    Str1[j] = Arr[i][j];
  }

  for (j = (StringLength / 2) + 1; j < StringLength + 1; j++)
  {
    Str2[j - ((StringLength / 2) + 1)] = Arr[i][j];
  }

  for (j = StringLength - ((StringLength / 2)); j < StringLength; j++)
  {
    Str2[j] = 0;
  }
  strcat(Str2, Str1);
  strcat(Str2, "ay");
  strcpy(Arr[i], Str2);
}

void PrintStr()
{
	int i;
  for (i = 0; i < WordsInArr; i++)
  {
    puts(Arr[i]);
  }
};

void BreakStr()
{
	int i;
  char *CurrWord = strtok(String, " ");

  while (CurrWord != NULL)
  {
    for (i = 0; i < strlen(CurrWord); i++)
    {
      Arr[WordsInArr][i] = CurrWord[i];
    }
    WordsInArr++;
    CurrWord = strtok(NULL, " ");
  }
};
