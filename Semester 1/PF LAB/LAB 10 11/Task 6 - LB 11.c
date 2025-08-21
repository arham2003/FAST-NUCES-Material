#include <stdio.h>

struct volume{
	int leng;
	int width;
	int height;
};
int main(){
	int a,i,j,k;
	printf("Enter total number of boxes: ");
	scanf("%d", &a);
	struct volume box[a];
	
	for(i=0,j=1;i<a;i++,j++){
		printf("\nEnter the height of box %d: ", j);
		scanf("%d", &box[i].height);
		printf("\nEnter the leng of box %d: ", j);
		scanf("%d", &box[i].leng);
		printf("\nEnter the width of box %d: ", j);
		scanf("%d", &box[i].width);
		printf("\n \n \n");}
	
	for(i=0,j=1;i<a;i++,j++){
		if(box[i].height>=41){
			printf("\nThe height of box %d exceeds limits", j);}
		else{
			k= (box[i].leng*box[i].height*box[i].width);
			printf("\nThe volume of box %d is: %d", j, k);}
	}
	
	return 0;
}
