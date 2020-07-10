#include<iostream>
#include<conio.h>
using namespace std;
class Node{
	public:
		int key;
		int data;
		Node * next;
		Node()
		{
			key=0;
			data=0;
			next=NULL;
		}
		Node(int k,int d)
		{
			key=k;
			data=d;
		}
};
class SinglyLinkedList{
	public:
		Node* head;
		
		SinglyLinkedList()
		{
			head=NULL;
		}
		
		SinglyLinkedList(Node* n)
		{
			head=n;
		}
		
		Node* nodeExist(int k)
		{
			Node* temp=NULL;
			Node* ptr=head;
			while(ptr!=NULL)
			{
				if(ptr->key==k)
				{
					temp=ptr;	
				}
			  ptr=ptr->next;		
			}
		  return temp;		
		}
		
		void appendNode(Node *n)
		{
			if(nodeExist(n->key)!=NULL)
			{
				cout<<"Node Already exist with same key value";
			}
			else
			{
				if(head==NULL)
				{
					head=n;					
					cout<<"Node Appended!!"<<endl;
				}
				else
				{
						Node* ptr=head;
						while(ptr->next!=NULL)
						{
							ptr=ptr->next;
						}
						ptr->next=n;
	  				 cout<<"\nNode Appended!!!";
				}	
			}
		}
		void prependNode(Node* n)
		{
			if(nodeExist(n->key) !=NULL)
			{
				cout<<"\nNode Already exist with same key value";
			}
			else
			{
				n->next=head;
				head=n;
				cout<<"\nNode Prepended!!";
			}
		}
		void insertNode(int k,Node* n)
		{
			Node* ptr=nodeExist(k);
			if(ptr==NULL)
			{
				cout<<"\nKey doesnot exist";
			}
			else
			{
				if(nodeExist(n->key)!=NULL)
				{	
					cout<<"\nNode Already exist with same key value";
				}
				else
				{
					n->next=ptr->next;
					ptr->next=n;
					cout<<"\nNode Inserted";
				}
			}
		}
	
		void deleteNode(int k)
		{
			if(head==NULL)
			{
				cout<<"\nLinked list already empty";
			}
			else if(head!=NULL)
			{
				if(head->key==k)
				{
					head=head->next;
					cout<<"\nNode deleted-key value :"<<k;
				}
				else
				{
					Node* temp=NULL;
					Node* prevptr=head;
					Node* currentptr=head->next;
					while(currentptr!=NULL)
					{
						if(currentptr->key==k)
						{
							temp=currentptr;
							currentptr=NULL;
						}
						else
						{
							prevptr=prevptr->next;
							currentptr=currentptr->next;
						}
					}
					if(temp!=NULL)
					{
						prevptr->next=temp->next;
						cout<<"\nNode unlinked with key value :"<<k;
					}
					else
					{
						cout<<"\nNode doesnot exist with key value :"<<k;
					}
				}
			}
		}
		
		void updateNode(int k,int d)
		{
			Node* ptr=nodeExist(k);
			if(ptr!=NULL)
			{
				ptr->data=d;
				cout<<"\nData updated successfully!!";
			}
			else
			{
				cout<<"\nNode doesnot exist with given key values";
			}
		}
		
		void display()
		{
			if(head==NULL)
			{
				cout<<"\nLinked list doesnot contain any data";
			}
			else
			{
				cout<<"\nSingly Linked list values :\n";
				Node* temp=head;
				while(temp!=NULL)
				{
					cout<<"("<<temp->key<<","<<temp->data<<")"<<"-->";
					temp=temp->next;
				}
			}
		}
		
};
int main()
{
	SinglyLinkedList s;
	int option;
	char ch;
	int key1,k1,data1;
	do
	{
		cout<<"\nSelect the operation you want to perform \n";
		cout<<"1. appendNode() \n2. prependNode() \n3. insertNode()";
		cout<<"\n4. deleteNode() \n5. updateNode() \n6. Display\n";
		cin>>option;
		Node * n1=new Node();
		switch(option)
		{
			case 1:cout<<"\nAppend Node operation :\n enter key :";
					cin>>key1;
					cout<<"\nEnter data :";
					cin>>data1;
					n1->key=key1;
					n1->data=data1;
					s.appendNode(n1);
					break;
			case 2:cout<<"\nPrepend Node operation :\n enter key :";
					cin>>key1;
					cout<<"\nEnter data :";
					cin>>data1;
					n1->key=key1;
					n1->data=data1;
					s.prependNode(n1);
					break;
			case 3:cout<<"\nInsert key after which you want to insert new node :";
					cin>>k1;
					cout<<"\nEnter key :";
					cin>>key1;
					cout<<"\nEnter data :";
					cin>>data1;
					n1->key=key1;
					n1->data=data1;
					s.insertNode(k1,n1);
					break;
			case 4:cout<<"\nEnter the key of the node you want to delete :";
					cin>>k1;
					s.deleteNode(k1);	
					break;
			case 5:cout<<"\nUpdate Data \nEneter key whose data you want to update :";
					cin>>k1;
					cout<<"\nEnter updated data :";
					cin>>data1;
					s.updateNode(k1,data1);
					break;	
			case 6:	s.display();
					break;	
			default: cout<<"\nInvalid input!!";
					break;						
		}
		cout<<"\nDo you want to continue?(y/n) ";
		cin>>ch;
	}while(ch=='y');
	return 0;
}
