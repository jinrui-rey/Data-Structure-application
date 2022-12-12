#include <iostream>
#include <cmath>
using namespace std;
#define Maxsize 50

typedef struct node{
	char data;
	struct node *lchild;
	struct node *rchild;
}BTreenode;

void Create_tree(BTreenode *&b, char str[])	//按括号法建立树 
{
	BTreenode *st[Maxsize],*p;
	int top = -1,k,j=0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '#')
	{
		switch (ch)
		{
			case '(':top++; st[top] = p; k=1;break;
			case ',':k=2;break;
			case ')' :top--; break;
			default : p = new BTreenode;
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b==NULL)
				b = p;
			else 
			{
				switch(k)
				{
					case 1: st[top]->lchild = p; break;
					case 2: st[top]->rchild = p; break;
				}
			} 
		}
		j++;
		ch = str[j];
	}
}

void Display_pre(BTreenode *b)	//按先序遍历输出 
{
	if (b!= NULL)
	{
		cout<<b->data;
		Display_pre(b->lchild);
		Display_pre(b->rchild);
	}
}

void Display_mid(BTreenode *b)	//按中序遍历输出 
{
	if (b != NULL)
	{
		Display_mid(b->lchild);
		cout<<b->data;
		Display_mid(b->rchild);
	}
}

void Display_post(BTreenode *b)	//按后序遍历输出 
{
	if(b != NULL)
	{
		Display_post(b->lchild);
		Display_post(b->rchild);
		cout<<b->data;
	}
 } 

int main()
{
	BTreenode *tree;
	char str[Maxsize]={'0'};	//初始化树 
	cout<<"input the tree, end with #"<<endl;
	int i=0;;
	while(1)	//按括号法输入树 
	{	
		cin>>str[i];
		if (str[i] == '#' ) break;
		else i++;
	}
	Create_tree(tree,str); 
	cout<<"先序遍历:"; 
	Display_pre(tree);
	cout<<"\n";
	cout<<"中序遍历:"; 
	Display_mid(tree);
	cout<<"\n";
	cout<<"后序遍历:"; 
	Display_post(tree);
 } 
