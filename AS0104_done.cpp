/*  ���ϵĲ���������� 
*/
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
collection * Delete_repetition(collection *head)	//ɾ���ظ�Ԫ�� 
{
	collection *p1 = head->next;
	collection *p2 ;
	collection *mid;
	while (p1!= NULL)
	{
		p2= p1->next;
		while(p2!= NULL)
		{
			
			if (p1->data == p2->data )
			{
				mid = p2;
				p2=p2->next;
				p1->next = p2;
				delete mid;
			}
			else p2= p2->next;
		}
		p1=p1->next;	
	}
	return head;
}
collection* Minus(collection *head1, collection *head2)
{
	collection *p1 = head1->next;
	collection *p2 = head2->next;
	collection *head3 = new collection;
	collection *pre= head3;
	while (p1 != NULL && p2!= NULL)
	{
		collection *p_result = new collection;
		p_result->data=p1->data-p2->data;
		p1=p1->next ;
		p2=p2->next;
		pre->next = p_result;
		pre = p_result;
		p_result->next= NULL;
	}
	return head3;
}
collection* Intersection(collection *head1, collection *head2)
{
	collection *p1 = head1->next;
	collection *p2 = NULL;
	collection *head3 = new collection; 
	collection *pre = head3;
	while( p1!=NULL )
	{
		p2 = head2->next;
		while(p2!= NULL)
		{
			if (p1->data == p2->data)
		{
			collection *p_result = new collection;
			p_result->data = p1->data;					//	ȷ��P_result���ֵ 
			
			p2=p2->next;
			pre->next = p_result;						// ȷ�������ϵ 
			pre = p_result;
			p_result->next = NULL; 
		}
		else
		p2 = p2->next;
		}
		p1 = p1->next;
	}
	if (head3->next == NULL)
	cout<<"�޽���"; 
	return head3;
}

collection* Union (collection *head1, collection *head2)
{
	collection *head3 = new collection;
	collection *p1,*p2,*p3;
	p1=head1->next;
	p2=head2->next;
	
	head3->next = p1;
	while(p1->next!=NULL)
	{
		p1=p1->next;
	}
	p1->next = p2;
	return head3;
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

int main ()
{
	int a=5;
	collection *head1, *head2;
	head1 = CreatList(a);
	Display(head1);
	cout<<"\n";
	head2 = CreatList(a); 
	Display(head2);
	cout<<"\n";											//�������������� 
	
	cout<<"�����ϵĲ�Ϊ"; 
	Display(Delete_repetition(Minus(head1, head2))); 	//�����������ϵĲ��ʾ 
	
	collection *head3;									 
	head3 =Union(head1,head2);							//���������ϣ�������źϼ� 
	cout<<"�����ϵĲ���Ϊ";
	Display(Delete_repetition(head3));	  				//ɾ���ϼ��е��ظ�Ԫ�ز���� 
	return 0;
}
