#include<iostream>
#include<conio.h>
using namespace std;
class Stack{
	private:
		int a[5];
		int top;
	public:
		Stack()
		{
			top=-1;	
			for(int i=0;i<5;i++)
				a[i]=0;
		}	
		bool isEmpty()
		{
			if(top==-1)
				return true;
			else
				return false;	
		}
		bool isFull()
		{
			if(top==4)
				return true;
			else
				return false;	
		}
		void push(int x)
		{
			if(isFull())
			{
				cout<<"\nStack Overflow";
			}
			else
			{
				top++;
				a[top]=x;
			}
		}
		int pop()
		{
			if(isEmpty())
			{
				cout<<"\nStack Underflow";
				return 0;
			}
			else
			{
				int popValue=a[top];
				a[top]=0;
				top--;
				return popValue;			
			}	
		}
		int count()
		{
			return (top+1);
		}
		int peek(int pos)
		{
			if(isEmpty())
			{
				cout<<"\nStack Underflow";
				return 0;
			}
			else	
				return a[pos];
		}
		void change(int pos,int val)
		{
			a[pos]=val;
			cout<<"\nValue changed at location given";
		}
		void display()
		{
			for(int i=4;i>=0;i--)
			{
				cout<<a[i]<<" ";
			}
		}
};
int main()
{
	Stack obj;
	int c;
	char ch;
	int x,z;
	do
	{
		cout<<"Enter your choice :\n";
		cout<<"1. Check if stack is empty \n2. Check if stack is full \n3. Push an element in stack\n";
		cout<<"4. Pop the element from stack \n5. Count the number of elements \n6. Peek a value from stack\n";
		cout<<"7. Change a value in stack \n8. Display the stack";
		cin>>c;
		switch(c)
		{
			case 1:if(obj.isEmpty())
						cout<<"\nstack is empty";
					else
						cout<<"\nStack is not empty";
					break;	
			case 2:if(obj.isFull())
						cout<<"\nstack is full";
					else
						cout<<"\nStack is not full";
					break;	
			case 3: cout<<"\nenter the value to be pushed :";
					cin>>x;	
					obj.push(x);
					break;
			case 4:	cout<<"\nvalue popped "<<obj.pop();
					break;
			case 5:cout<<"\nNumber of elements in Stack "<<obj.count();
					break;							
			
			case 6:cout<<"Enter the position ";
					cin>>x;
					cout<<"\nValue at "<<x<<" is "<<obj.peek(x);
					break;
			case 7:cout<<"\nEnter position :";
					cin>>x;
					cout<<"\nEnter Value ";
					cin>>z;
					obj.change(x,z);
					break;
			case 8: obj.display();
					break;
			default: cout<<"\nInvalid choice ";
					break;
		}
		cout<<"\nDo you want to continue?(y/n)";
		cin>>ch;
		}while(ch=='y');
}
