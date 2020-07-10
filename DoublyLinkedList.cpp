#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
	public:
		int key;
		int data;
		Node* prev;
		Node* next;
		Node()
		{
			key=0;
			data=0;
			prev=NULL;
			next=NULL;	
		}	
		Node(int k,int d)
		{
			key=k;
			data=d;
			prev=NULL;
			next=NULL;
		}
};
class DoublyLinkedList
{
	public:
		Node * head;
		DoublyLinkedList()
		{
			head=NULL;
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
		
		void appendNode(Node * n)
		{
			if(nodeExist(n->key)!=NULL)
			{
				cout<<"\nNode Already exists with the given key value";
			}
			else
			{
				if(head==NULL)
				{
					head=n;
					cout<<"\nNode appended successfully!!";
				}
				else
				{
					Node* ptr=head;
					while(ptr->next!=NULL)
					{
						ptr=ptr->next;
					}
					ptr->next=n;
					n->prev=ptr;
					cout<<"\nNode appended successfully!!";
				}
			}
		}
		
		void prependNode(Node* n)
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
				}
				else
				{
					head->prev=n;
					n->next=head;
					head=n;
				}
				cout<<"\nNode prepended successfully!!";
			}
		}
		
		void insertNode(int k,Node* n)
		{
			Node* ptr=nodeExist(k);
			if(ptr==NULL)
			{
				cout<<"\nNo such node exist with given key value";
			}
			else
			{
				if(nodeExist(n->key)!=NULL)
				{
					cout<<"\nMultiple node with same key value cannot exist";
				}
				else
				{
					Node* nextNode=ptr->next;
					if(nextNode==NULL)
					{
						ptr->next=n;
						n->prev=ptr;
						cout<<"\nNode Inserted at the end";
					}
					else
					{
						n->next=nextNode;
						 nextNode->prev = n;
				          n->prev = ptr;
				          ptr->next = n;
				          cout << "Node Inserted in Between" << endl;
				 	}
				}
			}
		}
		
		void deleteNode(int k)
		{
			Node* ptr=nodeExist(k);
			if(ptr==NULL)
			{
				cout<<"\n no Node exist with given key values";
			}
			else
			{
				if(head->key==k)
				{
					head=head->next;
					cout<<"\nNode Unlinked!!";
				}
				else
				{
					Node* prevNode=ptr->prev;
					Node* nextNode=ptr->next;
					if(nextNode==NULL)
					{
						prevNode->next=NULL;
						cout<<"\nNode deleted from the end !";
					}
					else
					{
						prevNode->next=nextNode;
						nextNode->prev=prevNode;
						cout<<"\nNode deleted in between";
					}
				}
			}
		}
		
		void updateNode(int k,int d)
		{
			Node* ptr=nodeExist(k);
			if(ptr==NULL)
			{
				cout<<"\nNo noe exits with given key value";
			}
			else
			{
				ptr->data=d;
				cout<<"\nData updated successfully !";
			}
		}
		
		void printList()
		{
			if(head==NULL)
			{
				cout<<"\nList Empty!!";
			}
			else
			{
				Node* temp=head;
				cout<<"\nLinked List :\n";
				while(temp!=NULL)
				{
					cout<<"("<<temp->key<<"'"<<temp->data<<")-->";
					temp=temp->next;
				}
			}
		}
		
};

int main()
{
	DoublyLinkedList obj;
	int datain,keyin,option;
	char  ch;
	do
	{
		Node * n1=new Node();
		cout<<"\nEnter your choice :\n";
		cout<<"1. AppendNode()"<<endl;	
		cout<<"2. PrependNode()"<<endl;
		cout<<"3. InsertNode()"<<endl;
		cout<<"4. DeleteNode()"<<endl;
		cout<<"5. UpdateNode()"<<endl;
		cout<<"6. Print"<<endl;
		cin>>option;
		switch(option)
		{
			case 1: cout<<"\n--Append Node --\n";
					cout<<"Enter key value :";
					cin>>keyin;
					cout<<"\nEnter data :";
					cin>>datain;
					n1->key=keyin;
					n1->data=datain;
					obj.appendNode(n1);
					break;
			
			case 2: cout<<"\n--Prepend Node --\n";
					cout<<"Enter key value :";
					cin>>keyin;
					n1->key=keyin;
					cout<<"\nEnter data :";
					cin>>datain;
					n1->data=datain;
					obj.prependNode(n1);
					break;
			
			case 3: cout<<"\n--Insert Node--\n";
					cout<<"Enter key value :";
					cin>>keyin;
					cout<<"\nenter data :";
					cin>>datain;
					cout<<"\nEnter key value of node after you which you want to insert this node :";
					int k1;
					cin>>k1;
					n1->key=keyin; 
					n1->data=datain;
					obj.insertNode(k1,n1);
					break;
			
			case 4: cout<<"\n--Delete Node--\n";
					cout<<"Enter the key value of the node which you want to delete :";
					cin>>keyin;
					obj.deleteNode(keyin);	
					break;
					
			case 5: cout<<"\n--Update Node--\n";					
					cout<<"\nEnter the key value of node whose value you want to update :";
					cin>>keyin;
					cout<<"\nEnter Updated data :";
					cin>>datain;
					obj.updateNode(keyin,datain);
					break;
			
			case 6: obj.printList();
					break;
					
			default: cout<<"invalid input !! Try again";
					 break;
											
		}cout<<"\nDo you want to continue? (y/n)";
		cin>>ch;
	}while(ch=='y');
	return 0;
}
