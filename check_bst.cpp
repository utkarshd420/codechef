#include <iostream>
using namespace std;
typedef struct NodeA{
	struct NodeA * left;
	struct NodeA * right;
	struct NodeA * parent;
	int data;
}node;
bool check_bst(node *root, int min,int max)
{
	if(root==NULL)
		return true;
	if(root->data >= min && root->data <= max && check_bst(root->left,min,root->data) && check_bst(root->right,root->data,max))
		return true;
	return false;
}
int main()
{
	
	int min=7,max=20;
	node *n1 = new node();
	n1->data = 14;
	
	node *n2 = new node();
	n2->data = 8;
	
	node *n3 = new node();
	n3->data = 19;
	
	node *n4 = new node();
	n4->data = 7;
	node *n5 = new node();
	n5->data = 13;
	node *n6 = new node();
	n6->data = 15;
	node *n7 = new node();
	n7->data = 20;
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;

	if(check_bst(n1,min,max))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}