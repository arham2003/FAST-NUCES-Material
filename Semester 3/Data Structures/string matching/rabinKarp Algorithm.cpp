#include<string.h>
#include <iostream>
using namespace std;

#define d 256	

void rabinKarp(char pattern[],char text[], int q){
	int m= strlen(pattern);
	int n= strlen(text);
	int i,j;
	int p =0 ;// hash value of pattern
	int t = 0;// hash value of text
	int h =1;
	
	for(i=0;i < m-1;i++){
		h = (h*d) %q;
	}
	
	for(i=0; i<m ;i++){
		p= (d * p + pattern[i]) % q;
		t= (d * t + text[i]) % q;
	}
	
	for(i=0;i<=n-m;i++){
		if(p=t){
			for(j =0;j<m;j++){
				if(text[i+j] != pattern[j]){
					break;
					}
				}
				
				if(j==m)
					cout<< "Pattern found  at position: "<< i + 1 <<endl;
			}
			
			if(i < n-m){
				t = (d * (t- text[i] * h) + text[i + m]) % q;
			}
			if(t<0){
				t = (t+q);
			}
		}
}
	

int main(){
	char text[] = "ABCCDDAEFG";
	char pattern[] = "CDD";
	
	int q=13; //prime number used to reduce collisions
	
	rabinKarp(pattern,text,q);
	
	return 0;
}
