#include <iostream>
using namespace std;
struct node{
	struct node *left;
	struct node *right;
	struct node *parent;
	int data;
};
typedef struct node NODE;
int height(NODE *root,NODE *inp,int h)
{
	if(root==NULL)
		return 0;
	if(root==inp)
		return h;
	int lh = height(root->left,inp,h+1);
	int rh = height(root->right,inp,h+1);
	if(lh!=0 )
		return lh;
	return rh;
}
NODE * findnear(NODE * root, NODE * inp,int h)
{
	if(h==0 && root!=inp)
	{
		return root;
	}
	if(root==NULL || h==0)
		return NULL;
	NODE *ltm = findnear(root->left,inp,h-1);
	NODE *rtm = findnear(root->right,inp,h-1);
	if(ltm!=NULL)
		return ltm;
	return rtm;
}
int main()
{
 	NODE *n1 = new NODE();
 	n1->data=19;
 	NODE *n2 = new NODE();
 	n2->data=5;
 	NODE *n3 = new NODE();
 	n3->data=8;
 	NODE *n4 = new NODE();
 	n4->data=15;
 	NODE *n5 = new NODE();
 	n5->data=18;
 	NODE *n6 = new NODE();
 	n6->data=19;
 	n1->left=n2;
 	n1->right=n4;
 	n2->left=n3;
 	n2->right=n6;
 	n4->left=n5;
 	cout<<height(n1,n1,0)<<endl;
 	cout<<height(n1,n2,0)<<endl;
 	cout<<height(n1,n3,0)<<endl;
 	cout<<height(n1,n4,0)<<endl;
 	cout<<height(n1,n5,0)<<endl;
 	NODE * ans = findnear(n1,n3,height(n1,n3,0));
 	if(ans!=NULL)
 		cout<<ans->data<<endl;
 	else
 		cout<<"NAN"<<endl;
}