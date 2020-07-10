#include<iostream>
#include<conio.h>
using namespace std;
//function to apply insertion sort
void insertionSort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int temp=a[i];
		int j=i-1;
		while(j>=0 && a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	cout<<"\nArray after pass :"<<i<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}
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
	insertionSort(arr,n);
	cout<<"\n\nArray after sort :";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"  ";
	}
	getch();
	return 0;
}

