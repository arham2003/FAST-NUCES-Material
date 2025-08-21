#define	_COLOUR_H_
#include <_mingw.h>
#include<windows.h>

void textcolor (int color)
{
    static int __BACKGROUND;

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             color + (__BACKGROUND << 4));
}
//This will set the forground color for printing in a console window.
void SetColor(int ForgC)
{
     WORD wColor;
     //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        //Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
void ClearColor(){
    SetColor(15);
}
void SetColorAndBackground(int ForgC, int BackC)  
{  
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;  
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);  
     return;  
} 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Remainder{
    int dd;
    int mm;
    char note[50];
};
struct Remainder R;


struct Event{
    int dd1;
    int mm1;
    char events[50];
};
struct Event E;

void AddEvent(){
    FILE *fp;
    fp = fopen("events.dat","ab+");
    system("cls");
    printf("Enter the date(DD/MM): ");
    scanf("%d%d",&E.dd1, &E.mm1);
 
    printf("Enter the Event(50 character max): ");
    fflush(stdin);
    scanf("%[^\n]",&E.events);
    if(fwrite(&R,sizeof(R),1,fp)){
        
        puts("Event is added sucessfully");
        fclose(fp);
    }else{
        
        SetColor(12);
        puts("\aFail to save!!\a");
        ClearColor();
    }
    printf("Press any key............");
    getch();
    fclose(fp);
    
}

void AddNote(){
    FILE *fp;
    fp = fopen("note.dat","ab+");
    system("cls");

    printf("Enter the date(DD/MM): ");
    scanf("%d%d",&R.dd, &R.mm);

    printf("Enter the Note(50 character max): ");
    fflush(stdin);
    scanf("%[^\n]",&R.note);
    if(fwrite(&R,sizeof(R),1,fp)){
      
        puts("Note is saved sucessfully");
        fclose(fp);
    }else{
 
        SetColor(12);
        puts("\aFail to save!!\a");
        ClearColor();
    }
    printf("Press any key............");
    getch();
    fclose(fp);
    
}

int checkNote(int dd, int mm){
    FILE *fp;
    fp = fopen("note.dat","rb");
   /* if(fp == NULL){
        printf("Error in Opening the file");
    }*/
    while(fread(&R,sizeof(R),1,fp) == 1){
        if(R.dd == dd && R.mm == mm){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int checkEvent(int DD, int MM){
    FILE *fp;
    fp = fopen("events.dat","rb");
   
    while(fread(&E,sizeof(E),1,fp) == 1){
        if(E.dd1 == DD && E.mm1 == MM){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void showNote(int mm){  
    FILE *fp;  
    int i = 0, isFound = 0;  
    system("cls");  
    fp = fopen("note.dat","rb");  
    if(fp == NULL){  
        printf("Error in opening the file");  
    }  
    while(fread(&R,sizeof(R),1,fp) == 1){  
        if(R.mm == mm){  

            printf("Note %d Day = %d: %s\n", i+1, R.dd,  R.note);  
            isFound = 1;  
            i++;  
        }  
    }  
    if(isFound == 0){  
        //gotoxy(10,5);  
        printf("This %d Month contains no note\n",mm);  
    } 
	printf("Press any key............");
    getch(); 
   
}

void showEvent(int mm){  
    FILE *filep;  
    int i = 0, isFound = 0;  
    system("cls");  
    filep = fopen("events.dat","rb");  
    if(filep == NULL){  
        printf("Error in opening the file");  
    }  
    while(fread(&E,sizeof(E),1,filep) == 1){  
        if(E.mm1 == mm){  
         
            printf("Event of Day = %d: %s", E.dd1, E.events);  
            isFound = 1;  
            i++;  
        }  
    }  
    if(isFound == 0){  
       
        printf("This %d Month contains no Events\n",mm);  
    }  
    printf("Press any key............");
    getch();
   
}

int get_1st_weekday(int year){

  int d;
  d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
  return d;
}

int get_1st_weekday_islamic(int year){

  int d;
  d = (((year - 1) * 354) + ((year) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
  return d;
}

int main()
{
	   	SetConsoleTitle("Calender Project - Gregorian & Islamic Calendar"); 
	  	int year,month,day,daysInMonth,daysInIslamicMonth,weekDay=0,startingDay;
	   	char ch, ch2, i, ch3;
		int caseValue;
		SetColor(14);
		printf("Do you want to repeat the program ?(If yes, press y)\n");
		scanf(" %c",&ch3);
		do{
		caseValue = menu();
		system("cls");
		switch(caseValue){
            case 1:
	
	   
	   printf("\nEnter your desired year: ");
	   scanf("%d",&year);
	
	   char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	   int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};
	  
	   
	   if((year%4==0&&year%100!=0)||year%400==0){
	       monthDay[1]=29;
	   }
	
	   startingDay=get_1st_weekday(year);
	
	   for(month=0;month<12;month++){
	
	      daysInMonth=monthDay[month];
	      printf("\n------------------------------------------\n");
	      printf("\n\n-------------- %s, %d -----------------\n",months[month],year);
	      printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");
	
	      for(weekDay=0;weekDay<startingDay;weekDay++)
	        printf("     ");
	
	      for(day=1;day<=daysInMonth;day++){
				if((checkNote(day,month)==1)){
            		SetColor(12);
   	 			}else if(checkNote(day,month)==0){
   	 				SetColor(14);
					}
					
	      	
	        printf("%5d",day);
	
	        if(++weekDay>6){
	            printf("\n");
	            weekDay=0;
	        		}
	        startingDay=weekDay;
	      				} 	
	      		
	   		}
	   		
	   		printf("\nRed colour indicates notes.\n\n");
	   		
				printf("Do want to show notes?(Y or N)\n");
				scanf(" %c",&ch);	
				printf("Show Events (press q)\n\n");
				scanf(" %c",&ch2);
				
			for(i=1;i<=12;i++){
				 if(ch == 'y' || ch=='Y'){
				 		showNote(i);
				 }
				if(ch2 == 'q' || ch2 =='Q'){
					 		showEvent(i);
					 } 
			}
			  	
					
			
			break;
					
		case 2:
	
	   
	   	printf("\nEnter your desired year (In Gregorian): ");
	   	scanf("%d",&year);
		double hijriYear = ceil( (year - 621) * 1.03 );

	   	char *islamicMonths[]={"Muharram","Safar","Rabi-I","Rabi-II","Jumada-I","Jumada-II","Rajab","Shaban","Ramadan","Shawwal","Zulkadah","Zulhijjah"};
	   	int islamicMonthDay[]={30,29,30,29,30,29,30,29,30,29,30,29};
	   
	   if((year%4==0&&year%100!=0)||year%400==0){
	       islamicMonthDay[12]=30;
	   }
	
	   startingDay=get_1st_weekday_islamic(year);
	
	   for(month=0;month<12;month++){
	
	      daysInIslamicMonth=islamicMonthDay[month];
	      printf("\n------------------------------------------\n");
	      printf("\n\n-------------- %s, %.0f -----------------\n",islamicMonths[month],hijriYear);
	      printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");
	
		    for(weekDay=0;weekDay<startingDay;weekDay++)
		        printf("     ");
	      	for(day=1;day<=daysInIslamicMonth;day++){
	      	
				if(checkNote(day,month)==1){
            		SetColor(12);
   	 			}else if(checkNote(day,month)==0){
   	 				SetColor(14);
					}
				
					
			        printf("%5d",day);
			
			        if(++weekDay>6){
			            printf("\n");
			            weekDay=0;
			        		}
			        startingDay=weekDay;
	      				}	
	
	   		}
	   	
	   		printf("\nRed colour indicates notes.\n\n");
				printf("Do want to show notes?(Y or N)\n");
				scanf(" %c",&ch);	
				printf("Show Events (press q)\n\n");
				scanf(" %c",&ch2);
			for(i=1;i<=12;i++){
				 if(ch == 'y' || ch=='Y'){
				 		showNote(i);
				 }
				if(ch2 == 'q' || ch2 =='Q'){
					 		showEvent(i);
					 } 
			}
			
			break;	 
		
		case 3:
			AddNote();
			
                break;
                
        case 4:
        	AddEvent();
		    break;    
        case 5 :  
        exit(0);  
	
	}
		}while (ch3 == 'y' || ch3 == 'Y');		
	return 0;
}

int menu(){
	int n;
	textcolor(14);
	printf("\n\t\tWelcome To Calendar app (Gregorian & Islamic)! (2022-2025)\n\n");
	printf("\t------------------------------------------------------------------------------\n\n");
	printf("\n 1- Print out the Gregorian Calendar \n");
	printf("\n 2- Print out the Islamic Calendar \n");
	printf("\n 3- Add notes \n");
	printf("\n 4- Add Events to the calender \n");
	printf("\n 5- EXIT\n");
	printf("\n Enter Your Choice: \n");
	scanf("%d",&n);
	
	return n;
}
