#include<iostream>
#include<conio.h>
using namespace std;
//function to imply selection sort
void selectionSort(int arr[],int n)
{
	for(int i=0;i<(n-1);i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
				min=j;
		}
		if(min!=i)
		{	
			int temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
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
		
	cout<<"\nArray before sort :";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";	
	}	
	
	//function call
	selectionSort(arr,n);
	
	cout<<"\nArray after sort :";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";	
	}
	
	getch();
	return 0;
}
