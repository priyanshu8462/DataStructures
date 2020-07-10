#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int a[1000],n,x,pos=-1;
	cout<<"\nEnter the number of elements in array :";
	cin>>n;
	cout<<"\nEnter the elements :\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"\nEnter an element you want to search :";
	cin>>x;	
	for(int i=0;i<n;i++)	
	{
		if(a[i]==x)
		{
			pos=i;
			break;
		}
	}
	if(pos!=-1)
		cout<<x<<" is present at index position :"<<pos;
	else
		cout<<x<<" is not present in list";
	getch();
	return 0;
}
