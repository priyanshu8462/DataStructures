#include<iostream>
#include<conio.h>
using namespace std;
class Node{
	public:
		int key;
		int value;
		Node * next;
		Node()
		{
			key=0;
			value=0;
			next=NULL;
		}
		Node(int k,int v)
		{
			key=k;
			value=v;
			next=NULL;
		}
};

class stack{
	public:
		Node * top;
		stack()
		{
			top=NULL;
		}
	//check if stack is empty	
		bool isEmpty()
		{
			if(top==NULL)
				return true;
			else
				return false;	
		}
		
	//check if node exist
		bool nodeExist(int k)
		{
			Node * temp=top;
			bool exist=false;
			while(temp!=NULL)
			{
				if(temp->key==k)
				{
					exist=true;
					break;
				}
				temp=temp->next;
			}
			return exist;	
		}	
	//push an node into stack
		void push(Node * n)
		{
			if(top==NULL)
			{
				top=n;
				cout<<"\nNode pushed";
			}
			else if(nodeExist(n->key))
				cout<<"\nNode already exist with key value "<<n->key;		
			else
			{
				Node *temp=top;
				top=n;
				n->next=temp;
				cout<<"\nNode Pushed";
			}
		}
		
	//pop the top node of stack
		Node* pop()
		{
			Node * temp=NULL;
			if(isEmpty())
				cout<<"\nStack underflow";
			else
			{
				temp=top;
				top=top->next;
				cout<<"\nElement popped";
			}
			return temp;
		}
		
	//count the number of elements
		int count()
		{
			int count=0;
			Node * temp=top;
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
			
			return count;		
		}		
		
	//peek top of stack
		Node * peek()
		{
			if(isEmpty())
			{
				cout<<"\nStack underflow";
				return NULL;		
			}		
			else
				return top;
		}		

	//display ell ekements from stack
		void display()
		{
			Node* temp=top;
			if(top==NULL)
				cout<<"\nStack is empty!!";
			else
			{
				while(temp!=NULL)
				{
					cout<<temp->key<<","<<temp->value<<endl;				
					temp=temp->next;
				}				
			}	
		}
		
};

int main()
{
	stack obj;
	int option,key,value;
	char ch;
	do
	{
		cout<<"\nEnter your choice :\n";
		cout<<"1. push()"<<endl;
		cout<<"2. pop()"<<endl;
		cout<<"3. count()"<<endl;
		cout<<"4. peek()"<<endl;
		cout<<"5. display()"<<endl;
		cin>>option;
		Node * n1=new Node();
		switch(option)
		{
			case 1: cout<<"\n---PUSH OPERTION---";
					cout<<"\nEnter key :";
					cin>>key;
					cout<<"\nEnter value :";
					cin>>value;
					n1->key=key;
					n1->value=value;
					obj.push(n1);			
					break;
			case 2:cout<<"\n---POP OPERATION---";		
					n1=obj.pop();
					cout<<"\nTop of stack popped :("<<n1->key<<","<<n1->value<<")"<<endl;
					delete n1;
					break;
			case 3:cout<<"\n---COUNT OPERATION---";		
					cout<<"\nTotal elements :"<<obj.count();
					break;
			case 4:cout<<"\n---PEEK OPERATION---";
					n1=obj.peek();
					cout<<"\nTop of stack :("<<n1->key<<","<<n1->value<<")"<<endl;
					break;
			case 5:cout<<"\n---DISPLAY OPERATION---\n";
					obj.display();
					break;
			default: cout<<"\nINVALID INPUT !!!";
					 break;						
		}
		cout<<"\nDo you ant to continue?? (y/n) :";
		cin>>ch;
	}while(ch=='y');
}
