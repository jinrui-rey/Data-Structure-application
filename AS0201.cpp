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
		cout<<s->data[s->top];
		s->top--;
	}
}

int Pop_stack(stack *s)
{
	int e;
	if (s->top == -1)
	cout<<"空栈";
	else 
	e = s->data[s->top];
	s->top--;
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

void Initiate(stack *&s)
{
	s->top = -1;
 } 

bool estimate(int a[],int a_length,int b[], int b_length)
{
	stack *s = new stack;		//建立辅助栈 
	Initiate(s);				//初始化栈 
	int i=0,j=0;
	if(a_length != b_length)	//如果两个序列长度不一样，那必不可能是对应的POP序列 
	cout<<"false";
	while (i<a_length)		//a数组的元素全部进栈 
	{
		Push_stack(s,a[i]);
		i++;
	}	
	while(j<b_length)		  //逐个出栈，和b数组的元素依次比较
	{
		if(Pop_stack(s) != b[j])	//出栈元素和数组元素不一致时返回false 
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
