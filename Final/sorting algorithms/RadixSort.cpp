#include<iostream>
#include<conio.h>
using namespace std;
void CountingSortForRadixSort(int a[],int n,int div);
int getMax(int a[],int n);
void RadixSort(int a[],int n);
void RadixSort(int a[],int n)
{
	int m=getMax(a,n);
	for(int i=1;m/i>0;i*=10)
		CountingSortForRadixSort(a,n,i);
}
int getMax(int a[],int n)
{
	int max=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}
void CountingSortForRadixSort(int a[],int n,int div)
{
	int out[n];
	int range=10;
	int count[10];
	for(int i=0;i<range;i++)
		count[i]=0;
	for(int i=0;i<n;i++)
		count[(a[i]/div)%10]++;
	for(int i=1;i<range;i++)
		count[i]=count[i]+count[i-1];		
	for(int i=n-1;i>=0;i--)
	{
		out[count[(a[i]/div)%10]-1]=a[i];
		count[(a[i]/div)%10]--;
	}
	for(int i=0;i<n;i++)
		a[i]=out[i];	
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
	RadixSort(arr,n);	
	cout<<"\nArray after sorting :";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	getch();
	return 0;	
}


