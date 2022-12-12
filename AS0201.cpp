#include <iostream>
#include <cmath>
using namespace std;
#define Maxsize 50

typedef struct Stack
{
	int data[Maxsize];
	int top;
}stack;

stack* Creat_stack ()
{
	stack *collection  = new stack; //���뽨��һ��collective��ջ
	int num;
	cout<<"����ջ��Ԫ�صĸ���";
	cin>>num;
	int i;
	for (i = 0 ; i < num ; i++) //�ӵ�0��Ԫ������� 
		{
			cout<<"����ջ��"<<i+1<<"��Ԫ��";  
			cin>>collection->data[i]; 
		}
	collection->top = num-1;
	return collection;
	
 } 
 
void Pop_stack_all(stack *s)//��ջ����Ԫ�� 
{
	if(s->top == -1)
	cout<<"��ջ";
	else 
	while (s->top != -1)
	{
		cout<<s->data[s->top];
		s->top--;
	}
}

int Pop_stack(stack *s)
{
	int e;
	if (s->top == -1)
	cout<<"��ջ";
	else 
	e = s->data[s->top];
	s->top--;
	return e;
}

stack* Push_stack(stack *s,int e) //��ջһ��Ԫ�� 
{
	if(s->top == Maxsize-1)
	cout<<"ջ��";
	else
	{
		s->top++;
		s->data[s->top] = e;
		}	
	return s;
}

void Initiate(stack *&s)
{
	s->top = -1;
 } 

bool estimate(int a[],int a_length,int b[], int b_length)
{
	stack *s = new stack;		//��������ջ 
	Initiate(s);				//��ʼ��ջ 
	int i=0,j=0;
	if(a_length != b_length)	//����������г��Ȳ�һ�����Ǳز������Ƕ�Ӧ��POP���� 
	cout<<"false";
	while (i<a_length)		//a�����Ԫ��ȫ����ջ 
	{
		Push_stack(s,a[i]);
		i++;
	}	
	while(j<b_length)		  //�����ջ����b�����Ԫ�����αȽ�
	{
		if(Pop_stack(s) != b[j])	//��ջԪ�غ�����Ԫ�ز�һ��ʱ����false 
			return false;
			break;
		j++;
	}
	return true;
}

int main()
{
	int a[5]={1,2,3,4,5};
	int b[5]={5,4,3,2,1};
	estimate(a,5,b,5);
}
