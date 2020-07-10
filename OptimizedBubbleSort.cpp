#include<iostream>
#include<conio.h>
using namespace std;
//function to apply bubble sort
void insertionSort(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		bool flag=false;	
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				flag=true;
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}	
	cout<<"\nArray after pass :"<<i+1<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}
	if(flag==false)
	{
		break;
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
