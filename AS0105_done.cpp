#include <iostream>
#include <cmath>
using namespace std;
typedef struct Collection
{
	int data;
	Collection *next;	
}collection;
collection* CreatList(int n)
{
	int i;
	collection *head = new collection;
	collection *pre = head ;
	for(i=0;i<n;i++)
	{
		collection *p = new collection;
		cout<<"�����뼯�ϵĵ�"<<i+1<<"��Ԫ��\t"; 
		cin>>p->data;								//����collection�е����� 
		
		pre->next= p;
		pre = p;
		p->next=NULL;										//ȷ�������ϵ 
		
	}
	return head;
}
void Display (collection *head)
{
	collection *p = head->next;
	while(p!=NULL)
	{
		cout<<p->data<<",";
		p=p->next;
	}
}
collection* Select(collection *head)
{
	collection *pivot = head->next;
	collection *p = pivot->next;	
	collection *mid = head;
	int temp;
	while(p!=NULL)
	{
		if( pivot->data > p->data)
		{
			temp = p->data;
			p->data = pivot->data;
			pivot->data = temp;
			
			pivot = p;
		}	
		p=p->next;
	}
	
	return head;
}
int main()
{
	int a=5;
	collection *head;
	head = CreatList(a);
	Display(head);
	cout<<"\n";
	Display(Select(head));
}
