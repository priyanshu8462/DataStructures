#include<iostream>
#include<conio.h>
using namespace std;
class Stack
{
	public:
		int a[5];
		int top;
		Stack()
		{
			for(int i=0;i<5;i++)	
				a[i]=0;
			top=-1;
		}	
	//check if stack is empty	
		bool isEmpty()
		{
			if(top==-1)
				return true;
			else
				return false;	
		}
	//check if stack is full	
		bool isFull()
		{
			if(top==(4))
				return true;
			else
				return false;	
		}
	//push an element in stack	
		void push(int n)
		{
			if(isFull())
			{
				cout<<"\nStack Overflow!!";
			}
			else
			{
				top++;
				a[top]=n;
				cout<<"\nItem pushed successfully!!";
			}
		}
	//pop the element from top of stack	
		int pop()
		{
			if(isEmpty())
			{
				cout<<"\nStack Underflow!!";
			}
			else
			{
				int popvalue=a[top];
				a[top]=0;
				top--;
				return popvalue;
			}
		}
	//peek the element at position i
		int peek(int i)
		{
			if(isEmpty())
			{
				cout<<"\nStack Underflow!!";	
			}	
			else
			{
				return a[i];
			}
		}	
	//count the number of items in stack
		int count()
		{
			return (top+1);
		}
	//display all elements
		void print()
		{
			for(int i=4;i>=0;i--)
				cout<<a[i]<<endl;	
		}	
			
};

//main function
int main()
{
	int option,n;
	char ch;
	Stack obj;
	do
	{
		cout<<"\nEnter your choice (1-6):\n";
		cout<<"1. push()"<<endl;
		cout<<"2. pop()"<<endl;
		cout<<"3. peek()"<<endl;
		cout<<"4. count()"<<endl;
		cout<<"5. display()"<<endl;
		cout<<"6. clear screen"<<endl;
		cin>>option;
		switch(option)
		{
			case 1: cout<<"--PUSH OPERATION--";
					cout<<"\nEnter value of element to be pushed :";
					cin>>n;
					obj.push(n);
					break;
					
			case 2: cout<<"\n--POP OPERATION--\n";
					cout<<"Element popped : "<<obj.pop();
					break;
					
			case 3: cout<<"\n--PEEK OPERATION--";
					cout<<"\nEnter index position of element :";	
					cin>>n;
					cout<<"\nValue of element :"<<obj.peek(n);
					break;
					
			case 4: cout<<"\n--COUNT OPERATION--";
					cout<<"\nTotal number of elements in stack :"<<obj.count();
					break;
					
			case 5: cout<<"\n--DISPLAY OPERATION--\n";
					obj.print();
					break;
					
			case 6: system("cls");
					break;
					
			default : cout<<"\nWrong input!!";				
					  break;							
		}
		cout<<"\nDo you want to continue?? (y/n)";
		cin>>ch;
	}while(ch=='y');
}
