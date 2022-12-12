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
	int count;   // 计队列内元素的个数 
}queue;

queue* Creat_queue() //建立一个循环队列 
{
	queue* squeue = new queue;
	int num;
	cout<<"输入队列内元素的个数";
	cin>>num; 
	squeue->front = 0;
	squeue->rear =0;
	squeue->count = num; 
	for(int i=0; i<num; i++)
	{	
		squeue->rear = (squeue->rear + 1)%Maxsize;
		cout<<"输入队列的第"<<squeue->rear+1<<"个元素 ";
		cin>>squeue->data[squeue->rear];
	} 
	return squeue;
}

void Dequeue_all(queue *q) // 出队全部元素
{
	if ( q->front == q->rear )
	cout<<"队空";
	else
	while (q->front != q->rear)
	{
		q->front = (q->front+1)%Maxsize;
		cout<<q->data[q->front]<<"\t";	
	}
 } 
 
int Dequeue(queue *q)		//出队队首元素 
{
 	if ( q->front == q->rear )
	cout<<"队空";
	else
	{
		q->front = (q->front+1)%Maxsize;
		cout<<q->data[q->front];	
	}
	return q->data[q->front];
}

queue* Enter_queue(queue *q , int e)		//入队一个元素 
{
	if ((q->rear+1)%Maxsize == q->front)
	cout<<"队满";
	else
	{
		q->rear = (q->rear +1)%Maxsize;
		q->data[q->rear] = e;
	}
	return q;
 }
 
stack* Creat_stack ()
{
	stack *collection  = new stack; //输入建立一个collective的栈
	int num;
	cout<<"输入栈内元素的个数";
	cin>>num;
	int i;
	for (i = 0 ; i < num ; i++) //从第0个元素起读入 
		{
			cout<<"输入栈第"<<i+1<<"个元素";  
			cin>>collection->data[i]; 
		}
	collection->top = num-1;
	return collection;
} 
 
void Pop_stack_all(stack *s)//出栈所有元素 
{
	if(s->top == -1)
	cout<<"空栈";
	else 
	while (s->top != -1)
	{
		cout<<s->data[s->top]<<"\t";
		s->top--;
	}
}

int Pop_stack(stack *s)		//出栈栈顶元素 
{
	int e;
	if (s->top == -1)
	cout<<"空栈";
	else 
	{
		e = s->data[s->top];
		s->top--;
	}
	return e;
}

stack* Push_stack(stack *s,int e) //进栈一个元素 
{
	if(s->top == Maxsize-1)
	cout<<"栈满";
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
	while(s->top != -1) 	//出栈全部元素并分别放入队列1,2 
	{
		if(s->top %2 != 0)//第偶数个元素进入队列1 
		Enter_queue(qu1, s->data[s->top]);
		if(s->top %2 == 0)//第奇数个元素进入队列2 
		Enter_queue(qu2, s->data[s->top]);
		s->top--; 
	} 	
	while(qu1->rear != qu1->front)//队列1 的元素全部出队，进栈 
	{
		Push_stack(s,Dequeue(qu1)); 
	}
	while(qu2->rear != qu2->front)//队列2的元素全部出队， 进栈 
	{
		Push_stack(s,Dequeue(qu2));
	}	
	return s; 
 } */
 

stack* Select (stack *s)
{
	queue *qu1 = new queue;
	queue *qu2 = new queue;	//建立两个辅助队列 
	int e;
	while(s->top != -1) 	//出栈全部元素并分别放入队列1,2 
	{
		if(s->top %2 != 0) //第偶数个元素进入队列1 
		{
			e = Pop_stack(s);// 出栈 
			Enter_queue(qu1,e);//入队 
		}
		if(s->top %2 == 0)//第奇数个元素进入队列2 
		{
			e = Pop_stack(s);
			Enter_queue(qu2,e);
		}	
	} 	//此时为空栈 
	int j;
	while(qu1->rear != qu1->front)//队列1 的元素全部出队，进栈 
	{
		j = Dequeue(qu1);//出队 
		Push_stack(s, j);//进栈 
	}
	while(qu2->rear != qu2->front)//队列2的元素全部出队， 进栈 
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
