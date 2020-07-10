#include<iostream>
#include<conio.h>
using namespace std;

//function to merge
void merge(int a[],int l,int m,int r)
{
	int i=l,j=m+1,k=l;
	int temp[20];
	while(i<=m && j<=r)
	{
		if(a[i]<=a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
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
		k++;
		i++;
	}
	while(j<=r)
	{
		temp[k]=a[j];
		j++;
		k++;
	}
	for(int i=l;i<=r;i++)
		a[i]=temp[i];
}

//function to imply merge sort
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

//main()
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
	mergeSort(arr,0,n-1);	//pass array, initial index and fial index
	cout<<"\n\n\nArray after sorting :";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	getch();
	return 0;
}
