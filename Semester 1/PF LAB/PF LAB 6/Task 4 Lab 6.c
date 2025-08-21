#include <stdio.h>

int main (){
	int nooftypes, quantity, quantity1, quantity2;
	char firstSnack, secondSnack;
	int amount, total, total1, total2;
	
	printf("Please select from the following menu: \nB= Burger\nF= French Fries\nP= Pizza\nS= Sandwich\n");
	printf("How many types of snacks you want to order: ");
	scanf("%d",&nooftypes);
	switch (nooftypes){
		case 1:
			printf("\nEnter the snack you want to order: ");
			scanf(" %c",&firstSnack);
			printf("\nEnter Quantity: ");
			scanf("%d",&quantity);
			if (firstSnack == 'B' || firstSnack == 'b'){
				amount = 200;
				
			}
			else if (firstSnack == 'F' || firstSnack == 'f'){
				amount = 50;
			
			}
			else if (firstSnack == 'P' || firstSnack == 'p'){
				amount = 500;
		
			}
			else if (firstSnack == 'S' || firstSnack == 's'){
				amount = 150;
				
			}
			total = quantity * amount;
			printf("You have Ordered! \n %d %c (s) value %d PKR\n",quantity,firstSnack,amount);
			printf("Total: %d PKR\n",total);
			printf("Thank You for Your Order have a nice day.");
			break;
			
			case 2:
				
				printf("\nEnter first snack you want to order: ");
				scanf(" %c",&firstSnack);
				printf("\nEnter Quantity: ");
				scanf("%d",&quantity1);
				printf("\nEnter second Snack you want to order: ");
				scanf(" %c",&secondSnack);
				printf("\nEnter Quantity: ");
				scanf("%d",&quantity2);
				if (firstSnack == 'B' || firstSnack == 'b' || secondSnack == 'B' || secondSnack == 'b'){
					amount = 200;
					
				}
				else if (firstSnack == 'F' || firstSnack == 'f' || secondSnack == 'F' || secondSnack == 'f'){
					amount = 50;
				
				}
				else if (firstSnack == 'P' || firstSnack == 'p' || secondSnack == 'P' || secondSnack == 'p'){
					amount = 500;
				
				}
				else if (firstSnack == 'S' || firstSnack == 's' || secondSnack == 'S' || secondSnack == 's'){
					amount = 150;
				
				}
				total1 = quantity1 * amount;
				total2 = quantity2 * amount;
				total = total1 + total2;
				printf("You have Ordered! \n %d %c (s) value %d PKR\n",quantity1,firstSnack,total1);
				printf(" %d %c (s) value %d PKR\n",quantity2,secondSnack,total2);
				printf("Total: %d PKR\n",total);
				printf("Thank You for Your Order have a nice day.");
				break;
		
		default:
			printf("Invalid input.");
			break;
		}
	
		
}
