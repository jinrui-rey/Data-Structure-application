#include <iostream>
#include <cmath>
using namespace std;
#define Maxsize 51

typedef struct SqList
{
	int data[Maxsize];
	int length; 
}sqlist;

void CreatList(sqlist *&poll, int a[], int n )
{
	poll = new sqlist;
	for(int i=0; i<n; i++)
	{
		poll->data[i] = a[i];
	}
	poll->length = n;
}

void Display( sqlist *poll)
{
	for(int i=0;i<poll->length;i++)
	cout<<poll->data[i]<<",";
	cout<<"\n";
	cout<<"the length is "<<poll->length; 
}
sqlist* detect(sqlist *poll)
{
	sqlist *result = new sqlist;
	int i =0,j;
	int x=0,y;
	for(i = 0; i<poll->length;i++) 
	{
		for(j=i+1;j<poll->length;j++) 
			if(poll->data[i]+poll->data[j] == 6)
			{
				result->data[x] = poll->data[i];
				result->data[x+1]=poll->data[j];
				x=x+2;
				result->length = x;
			}
	}	 
	return result;
}

int main()
{
	sqlist *poll;
	int a[7] = {1,2,3,4,5,3,5};
	int n = 7;
	CreatList(poll,a,n);
	Display(poll);
	cout<<"\n";
	Display(detect(poll));
}
