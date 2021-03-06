#include<iostream>
#include<conio.h>
using namespace std;
class CircularQueue
{
	int front,rear,arr[5,itemCount];
	public:
		CircularQueue()
		{
			front=rear=-1;
			for(int i=0;i<5;i++)
				arr[i]=0;
			itemCount=0;	
		}
		bool isEmpty()
		{
			if(front==-1 && rear==-1)
				return true;
			else
				return false;	
		}
		bool isFull()
		{
			if((rear+1)%5==front)
				return true;
			else
				return false;	
		}
		void enqueue(int val)
		{
			if(isFull())
			{
				cout<<"\nQueue Overflow";
				return;
			}
			else if(isEmpty())
			{
				front++;
				rear++;
			}
			else
			{
				rear=(rear+1)%5;	
			}
			arr[rear]=val;
			itemCount++;
		}
		int dequeue()
		 {
		 	if(isEmpty())
		 	{
			 	cout<"\nQueue is empty";
		 		return 0;
			}
			else if(front==rear)
			{
				int x=arr[front];	
				front=-1;
				rear=-1;
				arr[front]=0;
				return x;
			}
			else
			{
				int x=arr[front];
				arr[front]=0;
				front=(front+1)%5;
				return x;	
			}
			itemCount--;
		 }
		 int count()
		 {
		 	return itemCount;
		 }
		 void display()
		 {
		 	for(int i=0;i<5;i++)
		 		cout<<arr[i]<<" ";
		 }
};
int main()
{
	CircularQueue obj;
	int x,val;
	char ch;
	do{
		cout<<"\nEnter your Choice \n";
		cout<<"\n1. Add an element in Queue \n2. Remove an element from Queue";
		cout<<"\n3. Count number of elements in Queue \n4. Check if Queue is Empty";
		cout<<"\n5. Check if Queue is Full\n 6. Display\n";
		cin>>x;
		switch(x)
		{
			case 1: cout<<"\nEnter a item to be enqueued :";
					cin>>val;
					obj.enqueue(val);
					break;
			case 2: cout<<"Element removed :"<<obj.dequeue();
					break;
			case 3: obj.count();
					break;
			case 4: if(obj.isEmpty())
						cout<<"\nQueue is Empty";
					else
						cout<<"\nQueue is not Empty";		
					break;
			case 5: if(obj.isFull())
						cout<<"\nQueue is Full";
					else	
						cout<<"\nQueue is not Full";
					break;
			case 6:obj.display();
					break;
			default: cout<<"\nwrong input!!";
					break;															
		}
		cout<<"\ndo you want to continue?(y/n)";
		cin>>ch;
	}while(ch=='y');
}

