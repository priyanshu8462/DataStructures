#include<iostream>
#include<conio.h>
using namespace std;
//function to apply count sort
void countSort(int in[],int n)
{
	int k;
	cout<<"\nEnter range , i.e, number of unique elements :";
	cin>>k;
	int out[n],count[k];
	for(int i=0;i<k;i++)
	{
		count[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		++count[in[i]];
	}
	for(int i=1;i<k;i++)
	{
		count[i]=count[i]+count[i-1];
	}	
	for(int i=0;i<n;i++)
	{
		out[--count[in[i]]]=in[i];
	}
	for(int i=0;i<n;i++)
	{
		in[i]=out[i];
	}
}
int main()
{
	int arr[30],n;
	cout<<"\Enter the number of elements in array :";
	cin>>n;
	cout<<"\nEnter elements of array :";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"\nArray before sort :";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"  ";
	}
	countSort(arr,n);
	cout<<"\n\nArray after sort :";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"  ";
	}
	getch();
	return 0;
}
