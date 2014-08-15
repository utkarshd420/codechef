#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct NodeA{
	struct NodeA * next;
	int data;
}node;
void del(node *root,node *r)
{
	node *temp = root;
	while(temp!=NULL)
	{
		if(temp->next==r)
		{
			temp->next = (temp->next)->next;
			free(temp->next);
		}
		temp = temp->next;
	}
}
int main()
{
	node *root = new node();
	root->data=1;
	node *n1 = new node();
	n1->data=2;
	node *n2 = new node();
	n2->data=3;
	node *n3 = new node();
	n3->data=0;
	node *n4 = new node();
	n4->data=5;
	node *n5 = new node();
	n5->data=4;
	node *n6 = new node();
	n6->data=0;
	node *n7 = new node();
	n7->data=3;
	node *n8 = new node();
	n8->data=2;
	node *n9 = new node();
	n9->data=0;
	root->next=n1;
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=n6;
	n6->next=n7;
	n7->next=n8;
	n8->next=n9;
	node *tmp = root->next;
	node *begin=root;
	while(tmp!=NULL)
	{
		cout<<begin->data<<endl;
		if(tmp->data==0)
		{
			begin->next=tmp->next;
			begin = tmp->next;
			free(tmp);
			if(begin!=NULL)
				tmp=begin->next;
			else
				tmp=NULL;
		}
		else
		{
			begin->data+=tmp->data;
			begin->next=tmp->next;
			free(tmp);
			tmp=begin->next;
		}
	}
	while(root!=NULL)
	{
		cout<<root->data<<", ";
		root= root->next;
	}
}