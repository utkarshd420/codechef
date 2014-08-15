#include <iostream>
using namespace std;
typedef struct NodeA{
	struct NodeA * left;
	struct NodeA * right;
	struct NodeA * parent;
	int data;
}node;
int bal_nodes(node *root)
{
	if(root==NULL)
		return 0;
	if(root->left!=NULL && root->right!=NULL)
		return 1+bal_nodes(root->left)+bal_nodes(root->right);
	else
		return 0;
}
int main()
{
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
	cout<<"Bal nodes ar "<<bal_nodes(n1)<<endl;
}