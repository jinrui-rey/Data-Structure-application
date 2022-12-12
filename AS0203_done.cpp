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
		cout<<"������еĵ�"<<squeue->rear<<"��Ԫ�� ";
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
		cout<<q->data[q->front];	
	}
 } 
 
 
  int Delet_queue (queue *q)		//����һ��Ԫ�� 
 {
 	if ( q->front == q->rear )
	cout<<"�ӿ�";
	else
	{
		q->front = (q->front+1)%Maxsize;
	}
	return q->data[q->front];
 }
 
 queue* Enter_queue(queue *q , int e)
{
	if ((q->rear+1)%Maxsize == q->front )
	cout<<"����";
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
	while (i < q->count)		//count�Ƕ�����Ԫ�صĸ��� 
	{
		if(q->data[q->front+1] < q->data[q->front+i+1])		//һ�����ж϶���Ԫ��ֵ�Ƿ�ȶ���ֵ�� 
		{
			mid = q->data[q->front+1];						//����ȶ���ֵ�󣬽������ߵ�ֵ 
			q->data[q->front+1] = q->data[q->front+i+1];
			q->data[q->front+i+1] = mid;
		 } 
		i++;
	}
	return q->data[q->front+1];			//���ض��׵�ֵ������ʱ���׵�ֵ���������λ�õ�ֵû�б仯�� 
 } 

 int main()
{
	queue *qu;
	qu = Creat_queue();
	cout<<Show_largest(qu);
 } 
