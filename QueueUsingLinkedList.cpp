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
class Queue{
	public:
		Node * front;
		Node *rear;
		Queue()
		{
			front=NULL;
			rear=NULL;
		}
		//check if queue is empty
		bool isEmpty()
		{
			if(front==NULL && rear==NULL)
				return true;
			else
				return false;		
		}
		
		//check if node Exist with given key value
		bool nodeExist(int k)
		{
			Node * temp=front;
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
		//enqueue an element in queue from rear
		void enqueue(Node * n)
		{
			if(isEmpty())
			{
				front=n;
				rear=n;
				cout<<"\nNode enqueued successfully";
			}
			else if(nodeExist(n->key))
			{
				cout<<"\nNode exist with key value "<<n->key;
			}
			else
			{
				rear->next=n;
				rear=n;
				cout<<"\nNode Enqueued successfully";
			}
		}
		
		//dequeue an element in queue from front
		Node * dequeue()
		{
			Node* temp=NULL;
			if(isEmpty())
			{
				cout<<"\nQueue is empty";
			}
			else if(front==rear)
			{
				temp=front;
				front=NULL;
				rear=NULL;
			}
			else
			{
				temp=front;
				front=front->next;
			}
			
			return temp;
		}
		
		//count total number of elements
		int count()
		{
			int count=0;
			Node * temp=front;
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
			return count;
		}
		
		//display queue
		void display()
		{
			Node * temp=front;
			while(temp!=NULL)
			{
				cout<<"("<<temp->key<<","<<temp->value<<") -->";
				temp=temp->next;
			}
		}
};

int main()
{
	Queue obj;
	int x,k,v;
	char ch;
	do{
		cout<<"\nEnter your Choice \n";
		cout<<"\n1. Add an element in Queue \n2. Remove an element from Queue";
		cout<<"\n3. Count number of elements in Queue \n4. Check if Queue is Empty";
		cout<<"\n5. Display\n";
		cin>>x;
		Node * n1=new Node();
		switch(x)
		{
			case 1: cout<<"\n--ENQUEUE OPERATION--";
					 cout<<"\nEnter key :";
					cin>>k;
					cout<<"\nEnter value :";
					cin>>v;
					n1->key=k;
					n1->value=v;
					obj.enqueue(n1);
					break;
			case 2: cout<<"\n--DEQUEUE OPERATION--";
					n1=obj.dequeue();
					cout<<"Element removed : ("<<n1->key<<","<<n1->value<<") ";
					break;
			case 3: cout<<"\n--COUNT OPERATION--";
					cout<<"\nTotal eements :"<<obj.count();
					break;
			case 4: if(obj.isEmpty())
						cout<<"\nQueue is Empty";
					else
						cout<<"\nQueue is not Empty";		
					break;
			case 5:obj.display();
					break;
			default: cout<<"\nwrong input!!";
					break;															
		}
		cout<<"\ndo you want to continue?(y/n)";
		cin>>ch;
	}while(ch=='y');
	
	getch();
	return 0;
}
