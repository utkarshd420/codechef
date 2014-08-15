#include <cstdio>
using namespace std; 
struct NodeA
{
	struct NodeA * left;
	struct NodeA * right;
	int data;
};
typedef struct NodeA node;
void create_new(int data,node *parent,int left,int right)
{
	node *temp = new node();
	temp->data = data;
	if(left == 1)
		parent->left = temp;
	else 
		parent->right = temp;
}
void inorder(node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d, ",root->data);
	inorder(root->right);
}
void mirror(node *root)
{
	if(root == NULL)
		return;
	else
	{
		mirror(root->left);
		mirror(root->right);
		node *temp;
		temp=root->left;
		root->left=root->right;
		root->right= temp;
	}
}
int main()
{
	node *root = new node();
	root->data=4;
	root->left=NULL;
	root->right= NULL;	
	create_new(5,root,1,0);
	create_new(6,root,0,1);
	create_new(7,root->left,1,0);
	create_new(8,root->left,0,1);
	create_new(9,root->right,1,0);
	create_new(10,root->right,0,1);
	inorder(root);
	printf("\n");
	mirror(root);
	inorder(root);
	int count[5]={7989};
	for(int i=0;i<5;i++)
		printf("%d, ", count[i]);
}
