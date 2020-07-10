#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int x=5;
	int *p=&x;
	int **q=&p;
	cout<<"q :"<<q<<endl;
	cout<<"*q :"<<*q<<endl;
	cout<<"**q :"<<**q<<endl;
	cout<<"p :"<<p<<endl;
	cout<<"*p :"<<*p<<endl;
	getch();
	return 0;
}
