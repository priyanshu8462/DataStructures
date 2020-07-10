#include<iostream>
#include<conio.h>
using namespace std;
//function to imply insertion sort
void insertionsort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int temp=a[i];
		int j;
		for(j=i-1;(j>=0) && ((a[j]>temp));)
		{	
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}

int main()
{
	int n;
	cout<<"\nEnter the size of array :";
	cin>>n;
	int arr[n];
	cout<<"\nEnter "<<n<<" elements of array :";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<endl;
	cout<<"\nArray before sort :";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
		
	//function call
	insertionsort(arr,n);
		
	cout<<"\nArray after sort :";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	
	getch();
	return 0;
}

