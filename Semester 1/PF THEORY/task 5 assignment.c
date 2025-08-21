#include<stdio.h>
#include<math.h>

int main()
{
	int nooficecream, ice_cream_price,  total_cost, a,x,b, rem_icecream, cost8_hour, cost16_hour;
	char operTime;
	int total_days, extra_hour;
    printf("Input total number of ice-creams you have to buy: ");
    scanf("%d", &nooficecream);
    printf("Input the shift of operTimeeration you want per day: \n(A) for 8 hours per day\n(B) for 16 hours per day: ");
    scanf(" %c", &operTime);
    switch(operTime)
    {
    	case 'A':
    	case 'a':	
    		extra_hour= nooficecream % 400;
    		extra_hour= extra_hour/50;
    		total_days= nooficecream/400;
    		

    		total_cost= 60*nooficecream;
    		printf("\nIt will take total %d days or %d hours to prepare your order\n", total_days, extra_hour);
    		printf("\nYour total cost will be %d", total_cost);
    		break;
    		
    	case 'B':
    	case 'b':	
    		extra_hour= nooficecream%800;
    		extra_hour= extra_hour/50;
    		total_days= nooficecream/800;
    		printf("\nIt will take total %d days and %1d hours to prepare your order\n", total_days, extra_hour);
    		a= nooficecream;
    		for(x=0; a>400; x++)
    		{
    			a= a-400;
			}
			x=x+1;
			rem_icecream= nooficecream-a;
			if(x%2==1)
			{
				cost8_hour= (a*60)+ ((rem_icecream/2)*60);				
				cost16_hour= ((rem_icecream/2)*120);
				
				
			}
			else if(x%2==0)
			{
				rem_icecream= rem_icecream-400;
				b=400;
				cost8_hour= ((rem_icecream/2)*60)+(b*60);
				cost16_hour= (a*120) + ((rem_icecream/2)*120);
				
			}
			total_cost= cost8_hour + cost16_hour;
            printf("Cost distribution in 8 hour shift is %d", cost8_hour);
            printf("\nCost distribution in 16 hour shift is %d", cost16_hour);
    		printf("\nYour total cost will be %d", total_cost);
    		break;
	}
return 0;
}
