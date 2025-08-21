#include <stdio.h>

int main () {
	int oprTime,cost,numberRequired;
	float days;
	printf("How Much Ice Creams You want to Purchase  :- ");
	scanf("%d",&numberRequired);

	printf("How Much Time you want Plant to Operate  :- ");
	scanf("%d",&oprTime);
	
	if(oprTime == 8){
		cost = numberRequired * 60;
		days = numberRequired / (50*8);
	} else if (oprTime == 16) {
		cost = numberRequired * 60;
		cost = (cost/2) + (cost);
    	days = numberRequired / 100;	
	} else {
		printf("Plant can not operate for your time");
		return 0;
	}
	printf("Your Total is :- %d \n",cost);
	printf("Your Days Required is :- %f hours:- %d \n",days,days*24);
	return 0;
}
