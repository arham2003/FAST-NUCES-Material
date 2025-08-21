#include <iostream>
using namespace std;

void enrollInCourse(string courseArr[6],string sID,string course, string enrolledStd[][2]){
	
}

int main(){
	string sID;
	cout<<"Enter Student Id: "<<endl;
	cin>> sID;
	
	string courseArr[6] = {"Maths","Discrete","PF","History","Islamiyat","ICT"};
	
	string course=" ";
	cout<<"Enter the course to enroll in?"<<endl;
	cin>>course;
	
	string enrolledStd [6][2] = {{"Maths","4081"},{"PF","4082"},{"Maths","4092"},{"History","4102"},
	{"Discrete","8701"},{"ICT","4111"}};
	
	enrollInCourse(courseArr,sID,course,enrolledstd);
	
	int perc;
	cout<<"Enter Your Current Percentage?"<<endl;
	cin>>perc;
	
	
}
