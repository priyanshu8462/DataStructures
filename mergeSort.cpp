#include<iostream>
#include<conio.h>
using namespace std;
//function to apply mergesort
void merge(int a[],int l,int m,int r);
void mergeSort(int a[],int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}

//function to merge in a given order
void merge(int a[],int l,int m,int r)
{
	int i=l,j=m+1,k=l;
	int temp[20];
	while(i<=m && j<=r)
	{
		if(a[i]<=a[j])
		{
			temp[k]=a[i];
			i++;
			k++;
		}
		else
		{
			temp[k]=a[j];
			j++;
			k++;
		}
	}
	while(i<=m)
	{
		temp[k]=a[i];
		i++;
		k++;
	}
	while(j<=r)
	{
		temp[k]=a[j];
		k++;
		j++;
	}
	
	for(int p=l;p<=r;p++)
		a[p]=temp[p];
	cout<<endl;
	for(int p=l;p<=r;p++)
		cout<<a[p]<<" ";
		
}
//main() function
int main()
{
	int arr[20],n;
	cout<<"\nEnter size of array :";
	cin>>n;
	cout<<"\nEnter elements of array :";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"\n\n\nArray before sorting :";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	mergeSort(arr,0,n-1);	
	cout<<"\n\n\nArray after sorting :";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	getch();
	return 0;
}

