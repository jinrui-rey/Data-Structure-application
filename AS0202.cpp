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

int Pop_stack(stack *s)   //出栈栈顶元素 
{
	int e;
	if (s->top == -1)
	cout<<"空栈";
	else 
	e = s->data[s->top];
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
		Push_stack(s,a[k+i]);			//将数组第k个之后的元素全部进栈  
			if(s->data[s->top] > a[k])	// 若栈顶元素比数组内元素大
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
	while (j<length)		//输出数组 
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

