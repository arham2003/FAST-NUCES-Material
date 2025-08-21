#include <stdio.h>
struct book{
	int ISBN_No;
	char book_title[20];
	char name_author[20];
	int quantity;
	char sold[20];
	int availability;
	
}bk1,bk2,bk3,bk4;
int main(){
	int n,term,i,author,n3,term1,n4,avail,title1,avail1;
	char newbook[20];
	struct book bk1={122762,"Pet Sematary","Stephen King",3,"2 sold",1
	};
	struct book bk2={671222,"Inerno","Dan brown",3,"0 sold",3
	};
	struct book bk3={309292,"Da Vinci Code","Dan brown",3,"3 sold",0
	};
	struct book bk4={998973,"Bag of bones","Stephen King",3,"2 sold",1
	};
	printf("----------------Menu---------------\n");
	printf(" 1----> Books Information\n 2----> Add a new book\n 3----> Particular author books\n 4----> Quantity of a particular book\n 5----> Total quantity of books\n 6----> Issue a book\n");
	avail=bk1.availability+bk2.availability+bk3.availability+bk4.availability;
	term:
	printf("Select the option from menu\n");
	scanf("%d",&n);
        switch(n){
    	    case 1:
    		    printf(" Book 1\n");
    		    printf(" ISBN number:%d\n Book title:%s\n Author:%s\n Quantity:%d\n Total sales:%s\n Availabilty:%d\n",bk1.ISBN_No,bk1.book_title,bk1.name_author,bk1.quantity,bk1.sold,bk1.availability);
    		    printf("\n");
    		    printf(" Book 2\n");
    		    printf(" ISBN number:%d\n Book title:%s\n Author:%s\n Quantity:%d\n Total sales:%s\n Availabilty:%d\n",bk2.ISBN_No,bk2.book_title,bk2.name_author,bk2.quantity,bk2.sold,bk2.availability);
    		    printf("\n");
    		    printf(" Book 3\n");
    		    printf(" ISBN number:%d\n Book title:%s\n Author:%s\n Quantity:%d\n Total sales:%s\n Availabilty:%d\n",bk3.ISBN_No,bk3.book_title,bk3.name_author,bk3.quantity,bk3.sold,bk3.availability);
    		    printf("\n");
    		    printf(" Book 4\n");
    		    printf(" ISBN number:%d\n Book title:%s\n Author:%s\n Quantity:%d\n Total sales:%s\n Availabilty:%d\n",bk4.ISBN_No,bk4.book_title,bk4.name_author,bk4.quantity,bk4.sold,bk4.availability);
    		    printf("\n");
    		    printf(" 1----> EXIT the program\n 2----> Return to Menu\n ");
    		    int n1;
    		    scanf("%d",&n1);
    		    if(n1==1){
    		    	return 0;
				}
				else
				{
					goto term;
				}
			case 2:
				printf("Enter your suggession for the new book in our library. We shall surely arrange it for you\n");
				scanf("%s",&newbook);
				printf("Your suggestion has been recorded\n");
				printf("\n");
				printf(" 1----> EXIT the program\n 2----> Return to Menu\n ");
    		    int n2;
    		    scanf("%d",&n2);
    		    if(n2==1){
    		    	return 0;
				}
				else
				{
					goto term;
				}
			case 3:
				printf(" Enter the author name\n 1----> For Dan brown\n 2----> For Stephen King\n");
				scanf("%d",&author);
					if(author==1){
						printf(" %s\n %s\n",bk2.book_title,bk3.book_title);
						printf("\n");
						printf(" 1----> EXIT the program\n 2----> Return to Menu\n ");
    		            scanf("%d",&n3);
    		            if(n3==1){
    		    	        return 0;
				        }
				        else
				        {
					        goto term;
				        }
					}
					else if(author==2){
						printf(" %s\n %s\n",bk1.book_title,bk4.book_title);
						printf("\n");
						printf(" 1----> EXIT the program\n 2----> Return to Menu\n ");
    		            scanf("%d",&n3);
    		            if(n3==1){
    		    	        return 0;
				        }
				        else
			 	        {
					        goto term;
				        }
					}
					else{
						printf(" Invalid Entry");
						printf("\n");
						printf(" 1----> EXIT the program\n 2----> Return to Menu\n ");
    		            scanf("%d",&n3);
    		            if(n3==1){
    		    	        return 0;
				        }
				        else
				        {
					        goto term;
				        }
					}
			case 4:
				printf("------------SUB MENU 1------------\n");
				term1:
				printf("Enter the book title\n 1----> Pet Sematary\n 2----> Inferno\n 3----> Da Vinci Code\n 4----> Bag of bones\n");
				int title;
				scanf("%d",&title);
				if(title==1){
				    printf(" %d available",bk1.availability);
				    printf("\n");
				    printf(" 1----> EXIT the program\n 2----> Return to Menu\n 3----> Return to Sub-menu 1\n ");
    		            scanf("%d",&n3);
    		            if(n3==1){
    		    	        return 0;
				        }
				        else if(n3==2)
				        {
					        goto term;
				        }
				        else{
				        	goto term1;
						}
				}
				else if(title==2){
					printf(" %d available",bk2.availability);
				    printf("\n");
				    printf(" 1----> EXIT the program\n 2----> Return to Menu\n 3----> Return to Sub-menu 1\n ");
    		            scanf("%d",&n3);
    		            if(n3==1){
    		    	        return 0;
				        }
				        else if(n3==2)
				        {
					        goto term;
				        }
				        else{
				        	goto term1;
						}
				}
				else if(title==3){
					printf(" %d available",bk3.availability);
				    printf("\n");
				    printf(" 1----> EXIT the program\n 2----> Return to Menu\n 3----> Return to Sub-menu 1\n ");
    		            scanf("%d",&n3);
    		            if(n3==1){
    		    	        return 0;
				        }
				        else if(n3==2)
				        {
					        goto term;
				        }
				        else{
				        	goto term1;
						}
				}
				else if(title==4){
					printf(" %d available",bk4.availability);
				    printf("\n");
				    printf(" 1----> EXIT the program\n 2----> Return to Menu\n 3----> Return to Sub-menu 1\n ");
    		            scanf("%d",&n3);
    		            if(n3==1){
    		    	        return 0;
				        }
				        else if(n3==2)
				        {
					        goto term;
				        }
				        else{
				        	goto term1;
						}
				}
			case 5:
				printf(" The total books in the library are %d\n",avail);
				printf("\n");
				printf(" 1----> EXIT the program\n 2----> Return to Menu\n");
    		    scanf("%d",&n4);
    		    if(n4==1){
    		    return 0;
				}
			    else if(n4==2)
				{
				    goto term;
			    }
			case 6:
				printf(" Enter the book title you want to get\n 1----> Pet sematary\n 2----> Inferno\n 3----> Da Vinci Code\n 4----> Bag of bones\n");
				scanf("%d",&title1);
				switch(title1){
					case 1:
						printf(" Pet sematary has been issued\n");
						avail--;
						if(bk1.availability!=0)
						bk1.availability-=1;
						else{
							bk1.availability=0;
						}
						printf(" %d books are left in our library\n",avail);
						printf(" %d books left in the stock of this book\n",bk1.availability);
				        printf("\n");
				        printf(" 1----> EXIT the program\n 2----> Return to Menu\n");
    		            scanf("%d",&n3);
    		            if(n3==1){
    		    	        return 0;
				        }
				        else if(n3==2)
				        {
					        goto term;
				        }
				    case 2:
				    	printf("Inferno has been issued.\n");
						avail--;
						if(bk2.availability!=0)
						bk2.availability-=1;
						else{
							bk2.availability=0;
						}
						printf(" %d books are left in our library\n",avail);
						printf(" %d books left in the stock of this book\n",bk2.availability);
				        printf("\n");
				        printf(" 1----> EXIT the program\n 2----> Return to Menu\n");
    		            scanf("%d",&n3);
    		            if(n3==1){
    		    	        return 0;
				        }
				        else if(n3==2)
				        {
					        goto term;
				        }
				    case 3:
				    	printf(" Da Vinci Code has been issued.\n");
						avail--;
						if(bk3.availability)
						bk3.availability-=1;
						else{
							bk3.availability=0;
						}
						printf(" %d books are left in our library\n",avail);
						printf(" %d books left in the stock of this book\n",bk3.availability);
				        printf("\n");
				        printf(" 1----> EXIT the program\n 2----> Return to Menu\n");
    		            scanf("%d",&n3);
    		            if(n3==1){
    		    	        return 0;
				        }
				        else if(n3==2)
				        {
					        goto term;
				        }
				    case 4:
				    	printf(" Bag of bones has been issued.\n");
						avail--;
						bk4.availability-=1;
						printf(" %d books are left in our store\n",avail);
						printf(" %d books left in the stock of this book\n",bk4.availability);
				        printf("\n");
				        printf(" 1----> EXIT the program\n 2----> Return to Menu\n");
    		            scanf("%d",&n3);
    		            if(n3==1){
    		    	        return 0;
				        }
				        else if(n3==2)
				        {
					        goto term;
				        }
					}
				}
	return 0;	
}
	
