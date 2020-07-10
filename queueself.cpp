#include<iostream>
#include<conio.h>
using namespace std;
class Queue
{
	public:
		int a[5];
		int front,rear;
		Queue()
		{
			for(int i=0;i<5;i++)
			{
				a[i]=0;
			}
			front=-1;
			rear=-1;
		}
		
	//check if Queue is empty
	bool isEmpty()
	{
		if(front==-1 && rear==-1)
			return true;
		else
			return false;		
	}
	
	//check if Queue is full
	bool isFull()
	{
		if(rear==4)
			return true;
		else
			return false;		
	}	
	
	//insert a new element in queue
	void enqueue(int n)
	{
		if(isFull())
		{
			cout<<"\nQueue Overflow!! ";
		}
		else 
		{
			if(isEmpty())
			{
				front++;
				rear++;
			}
			else
			{
				rear++;
			}
		  a[rear]=n;		
		}
	}
	
	//remove an element from the beginning of Queue
	int dequeue()
	{
		if(isEmpty())
		{
			cout<<"\nStack Underflow!!";
		}
		else
		{
			int x;
			if(front==rear)
			{
				x=a[front];
				a[front]=0;
				front=-1;
				rear=-1;
				return x;
			}
			else
			{
				x=a[front];
				a[front]=0;
				front++;
				return x;
			}
		}
		return 0;
	}
	
	//peek the element a position i
	int peek(int i)
	{
		if(isEmpty())
			cout<<"\nQueue Underflow";
		else
			return a[i];
	}
	
	//count the number of elements in Queue
	int count()
	{
		return (rear-front+1);
	}
	
	//display all elements in queue
	void display()
	{
		for(int i=0;i<5;i++)
			cout<<a[i]<<"  ";
	}	
};

// main function
int main()
{
	Queue obj;
	int option,x;
	char ch;
	do
	{
		cout<<"\nEnter your choice (1-6) :\n";
		cout<<"1. enqueue()"<<endl;
		cout<<"2. dequeue()"<<endl;
		cout<<"3. peek()"<<endl;
		cout<<"4. count()"<<endl;
		cout<<"5. display()"<<endl;
		cout<<"6. cler screen"<<endl;
		cin>>option;
		switch(option)
		{
			case 1: cout<<"\n--ENQUEUE OPERATION--";
					cout<<"\nEnter value to be enqueued :";
					cin>>x;
					obj.enqueue(x);
					break;
			
			case 2: cout<<"\n--DEQUEUE OPERATION--";
					cout<<"\nElement removed :"<<obj.dequeue();
					break;
			
			case 3:	cout<<"\n--PEEK OPERATION--";
					cout<<"\nenter the index position of the element you want to peek :";
					cin>>x;
					cout<<"\nValue of element :"<<obj.peek(x);
					break;
			
			case 4: cout<<"\n--COUNT OPERATION--";
					cout<<"\nTotal number of elements :"<<obj.count();
					break;
			
			case 5: cout<<"\nDISPLAY OPERATION--";
					obj.display();
					break;
			
			case 6: system("cls");
					break;
			
			default: cout<<"\nWrong input!!";
						break	;									
		}
		cout<<"\nDo you want to continue?? (y/n)";
		cin>>ch;
	}while(ch=='y');
	
	return 0;
}
