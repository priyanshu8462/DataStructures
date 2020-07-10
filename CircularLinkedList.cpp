#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
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
			next=NULL;
		}
};

class CircularLinkedList
{
	public:
		Node * head;
		CircularLinkedList()
		{
			head=NULL;
		}	
		
		

		Node * nodeExist(int k)
		{
			Node * temp=NULL;
			Node * ptr=head;
			if(ptr==NULL)
			{
				return temp;
			}
			do
			{
				if(ptr->key==k)
				{
					temp=ptr;
				}
			   ptr=ptr->next;
			}while(ptr!=head);
		   return temp;	
		}
	
	

		void appendNode(Node * n)
		{
			if(nodeExist(n->key)!=NULL)
			{
				cout<<"\nNode already exist with given key value";
			}
			else
			{
				if(head==NULL)
				{
					head=n;
					n->next=head;
					cout<<"\nElement appended successfully";	
				}
				else
				{
					Node * ptr=head;
					while(ptr->next!=head)
					{
						ptr=ptr->next;
					}
				    ptr->next=n;
			    	    n->next=head;
			            cout<<"\nNode Appended Successfully!!";								
				}	
			}
		}

		void prependNode(Node * n)
		{
			if(nodeExist(n->key)!=NULL)
			{
				cout<<"\nNode already exist with given key value";
			}
			else
			{
				if(head==NULL)
				{
					head=n;
					n->next=head;
					cout<<"\nNode prepended successfully";
				}
				else
				{
					Node * ptr=head;
					while(ptr->next!=head)
					{
						ptr=ptr->next;
					}
					ptr->next=n;
					n->next=head;
					head=n;
					cout<<"\nNode prepended successfully!!";
				}
			}
		} 

		void insertNode(int k,Node * n)
		{
			Node * ptr=nodeExist(k);
			if(ptr==NULL)
			{
				cout<<"\nA node already exist with same key value";
			}
			else
			{
				if(nodeExist(n->key)!=NULL)
				{
					cout<<"\nNode alreday exit with given key value";	
				}
				else
				{
					if(ptr->next==head)
					{
						n->next=head;
						ptr->next=n;
						cout<<"\nNode inserted successfully!";
					}		
					else
					{
						n->next=ptr->next;
						ptr->next=n;
						cout<<"\nNode inserted in between";
					}
				}
			}
		}

		void deleteNode(int k)
		{
			Node * ptr=nodeExist(k);
			if(ptr==NULL)
			{
				cout<<"\nNo node exist with this key value";
			}
			else
			{
				if(ptr==head)
				{
					if(head->next==NULL)
					{
						head=NULL;
						cout<<"\nNode deleted (head)...";
					}		
				
					else
					{
						Node * nptr=head;
						while(nptr->next!=head)
						{
							nptr=nptr->next;
						}	 
					   nptr->next=head->next;
				 	   head=head->next;	
		              		   cout<<"\nNode unlinked ";		
					}
				}
				else
				{
					Node* temp=NULL;
					Node * prev=head;
					Node * current=head->next;
					while(current!=NULL)
					{
						if(current->key==k)
						{
							temp=current;
							current=NULL;	
						}
						else
						{
							prev=prev->next;
							current=current->next;	
						}	
					}
					prev->next=temp->next;
					cout<<"\nNode unlinked with key value :"<<k<<endl;
				}
			}
		}		
		
		void updateNode(int k,int d)
		{
			Node* ptr=nodeExist(k);
			if(ptr==NULL)
			{
				cout<<"\nNo node exist with given key value";
			}
			else
			{
				ptr->data=d;
				cout<<"\nData updated successfully";
			}
		}
		
		void print()
		{
			if(head==NULL)
			{
				cout<<"\nList already empty";
			}
			else
			{
				Node * ptr=head;
				cout<<endl;
				do
				{
					cout<<"("<<ptr->key<<","<<ptr->data<<") -->";
					ptr=ptr->next;
				}while(ptr!=head);
			}
		}
};

int main()
{
	CircularLinkedList obj;
	int option,keyin,datain,k1;
	char ch;
	do
	{
		cout<<"\nEnter your choice :\n";
		cout<<"1. appendNode()"<<endl;
		cout<<"2. prependNode()"<<endl;
		cout<<"3. insertNode()"<<endl;
		cout<<"4. deleteNode()"<<endl;
		cout<<"5. updateNode()"<<endl;
		cout<<"6. print()"<<endl;
		cin>>option;
		Node * newnode=new Node();
		switch(option)
		{
			case 1:	cout<<"\n--APPEND NODE--";
					cout<<"\nEnter key :";
					cin>>keyin;
					cout<<"\nEnter data :";
					cin>>datain;
					newnode->key=keyin;
					newnode->data=datain;
					obj.appendNode(newnode);
					break;
								
			case 2: cout<<"\n--PREPEND NODE--";
					cout<<"\nEnter key :";
					cin>>keyin;
					cout<<"\nEnter data :";
					cin>>datain;
					newnode->key=keyin;
					newnode->data=datain;
					obj.prependNode(newnode);
					break;			
					
			case 3:	cout<<"\n--INSERT OPERATION--";
					cout<<"\nEnter key of node after which you want to insert new node :";
					cin>>k1;
				 	cout<<"\nEnter key :";
					cin>>keyin;
					cout<<"\nEnter data :";
					cin>>datain;
					newnode->key=keyin;
					newnode->data=datain;
					obj.insertNode(k1,newnode);	
					break;
		
			case 4:	cout<<"\n--DELETE NODE--";
					cout<<"/nENter key of node you want to delete :";
					cin>>k1;
					obj.deleteNode(k1);
					break;
			
			case 5: cout<<"\n--UPDATE NODE --";
					cout<<"\nENter key of node whose data yu want to update :";
					cin>>k1;
					cout<<"\nEnter new data :";
					cin>>datain;
					obj.updateNode(k1,datain);	
					break;
			case 6:	cout<<"\n--DISPLAY OPERATION--";
					obj.print();
					break;
			default: cout<<"\nWrong input!!";
					break;										
		}
		cout<<"\ndo you want to continue?(y/n)";
		cin>>ch;
	}while(ch=='y');

return 0;
}
