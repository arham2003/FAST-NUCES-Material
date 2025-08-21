#include <stdio.h>
int main (){
	int time, totaltime; 
	float Sugartime,watertime,mixtime,addcoffeetime,addmilktime;
	char coffeeType, isManual, isDouble;
	
	printf("Enter Coffee type as B for Black or W for White Coffee: \n");
	scanf(" %c",&coffeeType);

	switch (coffeeType){
		case 'W':
		case 'w':
		printf("Is cup size Double? (Y for yes N for No): \n");
		scanf(" %c",&isDouble);
			
			switch (isDouble){
				case 'Y':
				case 'y':
					
					Sugartime = 15+(15*0.5);
					
					watertime = 15+(15*0.5);
					
					mixtime = 20+(20*0.5);
					
					addcoffeetime = 2+(2*0.5);
					
					addmilktime = 4+(4*0.5);
					totaltime = Sugartime + watertime + (mixtime*2) + addcoffeetime + addmilktime;
					
				printf("Is coffee manual? (Y for yes N for No): \n");
				scanf(" %c",&isManual);
			
					switch (isManual){
						case 'Y':
						case 'y':
							printf("  White Coffee:  \n\n");
							printf("Put Water: %.2f min\n", watertime);
							printf("Sugar: %.2f min\n", Sugartime);
							printf("Mix well: %.2f min\n", mixtime);
							printf("Add Coffee: %.2f min\n", addcoffeetime);
							printf("Add milk: %.2f min\n", addmilktime);
							printf("Sugar: %.2f min\n", mixtime);
							printf("Total Baking time is : %d min",totaltime);
							break;
						case 'N':
						case 'n':	
							printf("only manual function is available.");
							break;			
					}
				break;
					
				case 'N':
				case 'n':	
						Sugartime = 15;
						watertime = 15;
						mixtime = 20;
						addcoffeetime = 2;
						addmilktime = 4;
						totaltime = Sugartime + watertime + (mixtime*2) + addcoffeetime + addmilktime;
						printf("Is coffee manual? (Y for yes N for No): \n");
						scanf(" %c",&isManual);
						switch (isManual){
						case 'Y':
						case 'y':
							printf("  White Coffee:  \n\n");
							printf("Put Water: %.2f min\n", watertime);
							printf("Sugar: %.2f min\n", Sugartime);
							printf("Mix well: %.2f min\n", mixtime);
							printf("Add Coffee: %.2f min\n", addcoffeetime);
							printf("Add milk: %.2f min\n", addmilktime);
							printf("Sugar: %.2f min\n", mixtime);
							printf("Total Baking time is : %d min",totaltime);
							break;
						case 'N':
						case 'n':
							printf("only manual function is available.");
							break;		
							}
				}
		break;
							
		case 'B':
		case 'b':
		printf("Is cup size Double? (Y for yes N for No): \n");
		scanf(" %c",&isDouble);
			
			switch (isDouble){
				case 'Y':
				case 'y':
					
					Sugartime = 20+(20*0.5);
					
					watertime = 20+(20*0.5);
					
					mixtime = 25+(25*0.5);
					
					addcoffeetime = 15+(15*0.5);
					
					addmilktime = 0;
					totaltime = Sugartime + watertime + (mixtime*2) + addcoffeetime + addmilktime;
					
				printf("Is coffee manual? (Y for yes N for No): \n");
				scanf(" %c",&isManual);
				
					switch (isManual){
						case 'Y':
						case 'y':
							printf("  Black Coffee:  \n\n");
							printf("Put Water: %.2f min\n", watertime);
							printf("Sugar: %.2f min\n", Sugartime);
							printf("Mix well: %.2f min\n", mixtime);
							printf("Add Coffee: %.2f min\n", addcoffeetime);
							printf("Add milk: %.2f min\n", addmilktime);
							printf("Sugar: %.2f min\n", mixtime);
							printf("Total Baking time is : %d min",totaltime);
							break;
						case 'N':
						case 'n':	
							printf("only manual function is available.");
							break;			
				}
			break;	
					case 'N':
					case 'n':	
						Sugartime = 20;
						
						watertime = 20;
						
						mixtime = 25;
						
						addcoffeetime = 15;
						
						addmilktime = 0;
						
						printf("Is coffee manual? (Y for yes N for No): \n");
						scanf(" %c",&isManual);
						switch (isManual){
						case 'Y':
						case 'y':
							printf("  Black Coffee:  \n\n");
							printf("Put Water: %.2f min\n", watertime);
							printf("Sugar: %.2f min\n", Sugartime);
							printf("Mix well: %.2f min\n", mixtime);
							printf("Add Coffee: %.2f min\n", addcoffeetime);
							printf("Add milk: %.2f min\n", addmilktime);
							printf("Sugar: %.2f min\n", mixtime);
							
							break;
						case 'N':
						case 'n':
							printf("only manual function is available.");
							break;		
							}
				break;
						}
			}
		}
 
