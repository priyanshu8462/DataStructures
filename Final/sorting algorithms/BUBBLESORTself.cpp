#include<iostream>
#include<conio.h>
using namespace std;
//function to imply bubble sort
void bubblesort(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

int main()
{
	int n;
	cout<<"\nEnter size of array :";
	cin>>n;
	int arr[n];
	cout<<"\nEnter "<<n<<" elements of array :";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"\nArray before sorting :";
	for(int i=0;i<n;i++)	
		cout<<arr[i]<<" ";
	
	//function call
	bubblesort(arr,n);
		
	cout<<"\nArray after sorting :";
	for(int i=0;i<n;i++)	
		cout<<arr[i]<<" ";	
	getch();
	return 0;
}
