/* AS02*/ 
#include <iostream>
#include <cmath>
using namespace std;
#define Maxsize 50

typedef struct Stack		 
{
	int data[Maxsize];
	int top;
}stack;

typedef struct Queue
{
	int data[Maxsize];
	int front,rear;
	int count;   // �ƶ�����Ԫ�صĸ��� 
}queue;

queue* Creat_queue() //����һ��ѭ������ 
{
	queue* squeue = new queue;
	int num;
	cout<<"���������Ԫ�صĸ���";
	cin>>num; 
	squeue->front = 0;
	squeue->rear =0;
	squeue->count = num; 
	for(int i=0; i<num; i++)
	{	
		squeue->rear = (squeue->rear + 1)%Maxsize;
		cout<<"������еĵ�"<<squeue->rear+1<<"��Ԫ�� ";
		cin>>squeue->data[squeue->rear];
	} 
	return squeue;
}

void Dequeue_all(queue *q) // ����ȫ��Ԫ��
{
	if ( q->front == q->rear )
	cout<<"�ӿ�";
	else
	while (q->front != q->rear)
	{
		q->front = (q->front+1)%Maxsize;
		cout<<q->data[q->front]<<"\t";	
	}
 } 
 
int Dequeue(queue *q)		//���Ӷ���Ԫ�� 
{
 	if ( q->front == q->rear )
	cout<<"�ӿ�";
	else
	{
		q->front = (q->front+1)%Maxsize;
		cout<<q->data[q->front];	
	}
	return q->data[q->front];
}

queue* Enter_queue(queue *q , int e)		//���һ��Ԫ�� 
{
	if ((q->rear+1)%Maxsize == q->front)
	cout<<"����";
	else
	{
		q->rear = (q->rear +1)%Maxsize;
		q->data[q->rear] = e;
	}
	return q;
 }
 
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
		cout<<s->data[s->top]<<"\t";
		s->top--;
	}
}

int Pop_stack(stack *s)		//��ջջ��Ԫ�� 
{
	int e;
	if (s->top == -1)
	cout<<"��ջ";
	else 
	{
		e = s->data[s->top];
		s->top--;
	}
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


/*stack* Select (stack *s)
{
	queue *qu1 = new queue;
	queue *qu2 = new queue;
	while(s->top != -1) 	//��ջȫ��Ԫ�ز��ֱ�������1,2 
	{
		if(s->top %2 != 0)//��ż����Ԫ�ؽ������1 
		Enter_queue(qu1, s->data[s->top]);
		if(s->top %2 == 0)//��������Ԫ�ؽ������2 
		Enter_queue(qu2, s->data[s->top]);
		s->top--; 
	} 	
	while(qu1->rear != qu1->front)//����1 ��Ԫ��ȫ�����ӣ���ջ 
	{
		Push_stack(s,Dequeue(qu1)); 
	}
	while(qu2->rear != qu2->front)//����2��Ԫ��ȫ�����ӣ� ��ջ 
	{
		Push_stack(s,Dequeue(qu2));
	}	
	return s; 
 } */
 

stack* Select (stack *s)
{
	queue *qu1 = new queue;
	queue *qu2 = new queue;	//���������������� 
	int e;
	while(s->top != -1) 	//��ջȫ��Ԫ�ز��ֱ�������1,2 
	{
		if(s->top %2 != 0) //��ż����Ԫ�ؽ������1 
		{
			e = Pop_stack(s);// ��ջ 
			Enter_queue(qu1,e);//��� 
		}
		if(s->top %2 == 0)//��������Ԫ�ؽ������2 
		{
			e = Pop_stack(s);
			Enter_queue(qu2,e);
		}	
	} 	//��ʱΪ��ջ 
	int j;
	while(qu1->rear != qu1->front)//����1 ��Ԫ��ȫ�����ӣ���ջ 
	{
		j = Dequeue(qu1);//���� 
		Push_stack(s, j);//��ջ 
	}
	while(qu2->rear != qu2->front)//����2��Ԫ��ȫ�����ӣ� ��ջ 
	{
		j = Dequeue(qu2);
		Push_stack(s,j);
	}	
	return s; 	
}

int main()
{
	stack *s;queue *qu;
	s= Creat_stack();
	s = Select(s);
	Pop_stack_all(s);
	
 } 
