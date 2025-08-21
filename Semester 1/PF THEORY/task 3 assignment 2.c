#include<stdio.h>
#include<string.h>
main(){
int choice,num,digit,length,decryptednum=0,k;
char letter,j;
int i;
printf("what do you want to perform?\n1.encryption\n2.decryption: ");
scanf("%d",&choice);
switch (choice){
case 1:
printf("\nenter the number you want to encrypt: ");
scanf("%d",&num);
printf("\ncypher text: ");
if(num<=25){
j='A';
for(i=0;i<=25;i++){
if(num==i){
printf("%c",j);
}
else j++;
}
}
else {
while(num>0){
digit=num%10;
num=num/10;
j='A';
for(i=0;i<=9;i++){
if(digit==i){
printf("%c",j);

}
else j++;
}
}
}
break;
case 2:
printf("enter the length of string you wish to decrypt: ");
scanf("%d",&length);
for(i=1;i<=length;i++){
printf("\nenter the #%d letter of your string: ",i);
scanf(" %c",&letter);
for(k=0,j='A';j<='Z' && k<=25 ;j++,k++){
if(letter==j){
decryptednum = decryptednum*10 + k;
}
}
}
printf("decrypted text: ");
if(decryptednum>25){
while(decryptednum>0){
digit=decryptednum%10;
decryptednum/=10;
printf("%d",digit);
} }
else printf("%d",decryptednum);
break;

}}
