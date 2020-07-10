#include<iostream>
#include<conio.h>
using namespace std;
int binary_search(int a[],int left,int right,int x)
{
		while(left<=right)
		{
			int mid=left+(right-left)/2;
			if(a[mid]==x)
				return mid;
			else if(a[mid]<x)
				left=mid+1;
			else
				right=mid-1;		
		}	
}
int main()
{
	int arr[100],n,x,pos=-1;
	cout<<"\nEnter size of array :";
	cin>>n;
	cout<<"\nEnter a SORTED array of size "<<n<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter an element you want to search :";
	cin>>x;
	pos=binary_search(arr,0,(n-1),x);	
	cout<<"\nElement found at index :"<<pos;
	if(pos==-1)
		cout<<"\nElement not found!!";
	getch();
	return 0;
}
