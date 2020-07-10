#include<iostream>
#include<conio.h>
using namespace std;
void shellSort(int a[],int n)
{
	for(int gap=n/2;gap>0; gap/=2)
	{
		for(int j=gap;j<n;j++)
		{
			int temp=a[j];
			int i=0;
			for(i=j;i>=gap && (a[i-gap]>temp);i-=gap)
				a[i]=a[i-gap];
			a[i]=temp;	
		}
	}
}

int main()
{	int arr[30],n;
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
	shellSort(arr,n);
	cout<<"\n\nArray after sort :";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"  ";
	}
	getch();
	return 0;
}
