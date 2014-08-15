#include <iostream>
using namespace std;
class Node
{
	public:
	Node *next = NULL;
	int data;
	Node(int n)
	{
		data = n;
	}
};
void print(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"-->";
		head= head->next;
	}
}
Node * add_element_end(Node *head,int d)
{
	Node * tmp= new Node(d);
	if(head==NULL)
	{
		head=tmp;
		return head;
	}
	Node *itr= head;
	while(itr->next!=NULL)
		itr= itr->next;
	itr->next = tmp;
	return head;
}	

int main()
{
	Node *head=NULL;
	cout<<"Please input the elements of Nodes, zero to exit";
	int n;int len=0;
	do{
		cin>>n;
		head=add_element_end(head,n);
		/*Node *temp = new Node(n);
		if(len++ == 0 )
			head=temp;*/
	}while(n!=0);
	print(head);
}

