#include<iostream>
#include<conio.h>
using namespace std;
//function to perform selection sort
void selectionsort(int a[],int n)
{
	int min,i,j;
	for( i=0;i<(n-1);i++)
	{
		min=i;
		for( j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
	
	if(min!=i)
	{
		int temp=a[min];
		a[min]=a[i];
		a[i]=temp;	
	}
	}
}

int main() 
{
	int arr[20],n;
	cout<<"\nEnter number of elements in array :";
	cin>>n;
	cout<<"\nEnter elements in array :";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"\nArray before sorting :";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"  ";
	}
	selectionsort(arr,n);
	cout<<"\nArray after sorting :";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"  ";
	}
	getch();
	return 0;
}
