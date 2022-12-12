/* AS04*/ 
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

int Pop_stack(stack *s)   //��ջջ��Ԫ�� 
{
	int e;
	if (s->top == -1)
	cout<<"��ջ";
	else 
	e = s->data[s->top];
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

void Show_large(int a[],int length)
{
	int k=0,i=1;
	int e;
	stack *s = new stack;
	Initiate(s);
	
	while(k<length)
	{
		Push_stack(s,a[k+i]);
		if( s->data[s->top] > a[k])
		{
			a[k] = s->data[s->top];
			Initiate(s);
			k++;
			i=1;
		}
		i++;
		
		
	}
	/*while(k <= length )
	{
		Push_stack(s,a[k+i]);			//�������k��֮���Ԫ��ȫ����ջ  
			if(s->data[s->top] > a[k])	// ��ջ��Ԫ�ر�������Ԫ�ش�
			{
				a[k] = s->data[s->top];	
				k++; 
				i=1;
				Initiate(s);
			}
			else 
			{
				i++;
				Push_stack(s, a[k+i]);
			}	
		/*if(s->data[s->top] < a[i] || s->data[s->top] == a[i])
		{
			int useless = Pop_stack(s);
			if(s->top == 0)
			a[i] = -1;
		}
	}*/
	
	int j =0;
	while (j<length)		//������� 
	{
		cout<<a[j]<<" ";
		j++;
	}
}

void Display_array(int a[], int length)
{
	int i = 0;
	while(i < length)
	{
		cout<<a[i]<<"\t";
		i++; 
	}
}

int main()
{

	int a[5] = {3,2,3,4,5};
	Display_array(a,5);
	cout<<"\n";
	Show_large(a,5);
	//st = Creat_stack();
	//Pop_stack_all(st);
}

