#include<iostream>
#include<conio.h>
using namespace std;
int getMax(int arr[],int size)
{
	int max=arr[0];
	for(int i=0;i<size;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	return max;
}


void countarray(int a[],int size,int div)
{
	int count[10]={0};
	int out[size];
	for(int i=0;i<size;i++)
	{
		int rem=(a[i]/div)%10;
		count[rem]++;
	}
	cout<<endl;
	for(int i=0;i<10;i++)
		cout<<i<<" ";
	cout<<endl;	
	for(int i=0;i<10;i++)
		cout<<count[i]<<" ";
	
	cout<<"\n\n\nCummulative count array :\n";	
	for(int i=1;i<10;i++)
		count[i]=count[i]+count[i-1];
	for(int i=0;i<10;i++)
		cout<<i<<" ";
	cout<<endl;		
	for(int i=0;i<10;i++)	
		cout<<count[i]<<" ";
		
	cout<<"\n\n\nOutput array :\n";	
	for(int i=size-1;i>=0;i--)
	{
		int countindex=(a[i]/div)%10;
		int outindex=--count[countindex];
		out[outindex]=a[i];	
	}	
	for(int i=0;i<size;i++)
		cout<<i<<" ";
	cout<<endl;		
	for(int i=0;i<10;i++)	
		cout<<out[i]<<" ";
	cout<<endl<<endl;	
	for(int i=0;i<10;i++)
		a[i]=out[i];		
}

void radixSort(int a[],int n)
{
	int max=getMax(a,n);
	for(int i=1;max/i>0;i*=10)
		countarray(a,n,i);
	
}


int main()
{
	int n;
	cout<<"\nEnter size of array :";
	cin>>n;
	int arr[n];
	cout<<"\nEnter array :";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"\nArray before sorting :";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;	
	radixSort(arr,n);	
	/*RadixSort(arr,n);	
	cout<<"\nArray after sorting :";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" "; */
	getch();
	return 0;	
}

