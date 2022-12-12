/* AS04*/ 
#include <iostream>
#include <cmath>
using namespace std;
#define Maxsize 50


typedef struct Queue
{
	int data[Maxsize];
	int front,rear;
	int count;
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
		cout<<"输入队列的第"<<squeue->rear<<"个元素 ";
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
		cout<<q->data[q->front];	
	}
 } 
 
 
  int Delet_queue (queue *q)		//出队一个元素 
 {
 	if ( q->front == q->rear )
	cout<<"队空";
	else
	{
		q->front = (q->front+1)%Maxsize;
	}
	return q->data[q->front];
 }
 
 queue* Enter_queue(queue *q , int e)
{
	if ((q->rear+1)%Maxsize == q->front )
	cout<<"堆满";
	else
	{
		q->rear = (q->rear +1)%Maxsize;
		q->data[q->rear] = e;
	}
	return q;
 }
 
int Show_largest(queue *q)
{
	int i = 1;
	int mid;
	while (i < q->count)		//count是队列中元素的个数 
	{
		if(q->data[q->front+1] < q->data[q->front+i+1])		//一步步判断队内元素值是否比队首值大 
		{
			mid = q->data[q->front+1];						//如果比队首值大，交换两者的值 
			q->data[q->front+1] = q->data[q->front+i+1];
			q->data[q->front+i+1] = mid;
		 } 
		i++;
	}
	return q->data[q->front+1];			//返回队首的值，（此时队首的值最大，且其他位置的值没有变化） 
 } 

 int main()
{
	queue *qu;
	qu = Creat_queue();
	cout<<Show_largest(qu);
 } 
