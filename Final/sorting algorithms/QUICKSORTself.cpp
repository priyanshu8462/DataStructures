#include<iostream>
#include<conio.h>
using namespace std;
int partititon(int a[],int s,int e)
{
	int pivotindex=e;
	int pindex=s;
	for(int i=s;i<e;i++)
	{
		if(a[i]<=a[pivotindex])
		{
			int temp=a[i];
			a[i]=a[pindex];
			a[pindex]=temp;
			pindex++;
		}
	}
	int temp=a[pivotindex];
	a[pivotindex]=a[pindex];
	a[pindex]=temp;
	return pindex;	
}
int quicksort(int a[],int s,int e)
{
	if(s<e)
	{	
		int p=partititon(a,s,e);
		quicksort(a,s,p-1);
		quicksort(a,p+1,e);
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
	quicksort(arr,0,n-1);
	cout<<"\n\nArray after sort :";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"  ";
	}
	getch();
	return 0;
}
