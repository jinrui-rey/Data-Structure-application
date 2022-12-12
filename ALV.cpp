#include <iostream>
#include <cmath>
using namespace std;
struct node
{
	int height;
	char val;
	node *left;
	node *right;
};

int GetHeight(node *root)
{
	if (root == NULL)
		return 0;
	else 
		return root->height;
}

node* RotateRight(node *root)//LL
{
	node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	return temp;
}

node* RotateLeft(node* root)//RR
{
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	return temp;
}

node* RotateLeftRight(node* root)//LR
{
	root->left =  RotateLeft(root->left);
	root = RotateRight(root);
	return root;
}

node* RotateRightLeft(node* root)//RL
{
	root->right =  RotateRight(root->right);
	root = RotateLeft(root);
	return root;
}

node* Search(node *root,int val)
{
	if (root->val == val || root ==NULL)
		return root;
	if (val < root->val)
		return Search(root->left,val);
	else 
		return Search (root->right,val);
}


node* Insert(node* root, char val)
{
	if (root == NULL)
	{
		root = new node();
		root->left = NULL;
		root->right = NULL;
		root->height = 1;
		root->val = val;
	}
	
	if (val < root->val)
	{
		root->left = Insert(root->left,val);
		root->height = max(GetHeight(root->left),GetHeight(root->right))+1;
		
		if (GetHeight(root->left) - GetHeight(root->right) == 2)
		{
			if (val<root->left->val)//LL 
			{
				root = RotateRight (root);
			} 
			else //LR
			root = RotateLeftRight(root);
		}
	}
	
	if(val > root->val)
	{
		root->right = Insert(root->right,val);
		root->height = max(GetHeight(root->left),GetHeight(root->right))+1;
		
			if (GetHeight(root->left) - GetHeight(root->right) == -2)
		{
			if (val > root->right->val)//RR 
			{
				root = RotateLeft(root);
			 } 
			else //RL
			root = RotateRightLeft(root);
		}
	}
	return root;
}

void DeleteLR(node* p, node*& r)
{
	node* q;
	if(r->right != NULL)
		DeleteLR(p,r->right);
	else
	{
		p->val = r->val;
		q=r;
		r = r->left;
		delete(q);
	}
 } 

void Delete(node* &p)
{
	node* q;
	if(p->right == NULL)
	{
		q=p;
		p=p->left;
		delete(q);
	}
	else if (p->left == NULL)
	{
		q=p;
		p=p->right;
		delete(q);
	}
	else
	DeleteLR(p,p->left); 
 } 

int DeleteTree(node*& root, char val)
{
	if(root==NULL)
		return 0;
	else
	{
		if(val<root->val)
			return DeleteTree(root->left,val);
		else if (val>root->val)
			return DeleteTree(root->right,val);
		else 
		{
			Delete(root);
			return 1;
		 } 
	}
}


void Display_post(node *root)
{
	if(root!=NULL)
	{
		Display_post(root->left);
		Display_post(root->right);  
		cout<<root->val;
	} 
}

char function(node*& root)
{
	char temp;
	if(root!=NULL)
	{
		temp = root->val;
		DeleteTree(root,temp);
	}
	return temp;
}

int main()
{
	int n;
	char letter;
	cin>>n;
	node* root = NULL;
	for (int i=0 ; i<n;i++)
	{
		cin>>letter;
		root = Insert(root,letter);
	} 
	int m;
	char deletter;
	node* target;
	cin>>m;
	for(int j=0;j<m;j++)
	{
		cin>>deletter;
		target = Search(root,deletter);
		DeleteTree(root,target->val);
	}
	char mid;
	char array[n-m];
	for(int u=0;u<n-m;u++)
	{
		mid = function(root);
		array[u] = mid;
	}
	
	for (int v=0;v<n-m;v++)
		root = Insert(root,array[v]);
	
	Display_post(root);
}
