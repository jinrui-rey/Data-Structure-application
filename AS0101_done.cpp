#include <iostream>
#include <cmath>
using namespace std;

#define Maxsize 50
#define shatter 0
typedef struct Test
{
	double hight[Maxsize];
	int length; 
		
}test;

test* CreatList()
{
	test *egg = new test;
	cout<<"输入列表长度";
	cin>>egg->length; 
	for(int i=0; i<egg->length; i++)
	{
		cout<<"输入列表元素"; 
		cin>>egg->hight[i];
	}
	return egg;
}

void Display(test *egg)
{
	for(int i=0;i<egg->length;i++)
	cout<<egg->hight[i]<<", ";
	cout<<"\n";
	cout<<"the length is "<<egg->length; 
}

double experiment(test *egg)
{
	int mid = egg->length/2;
	int pre=0,n=2;
	while(egg->hight[mid] != shatter)
	{	
		pre = mid;
		mid = mid +egg->length/pow(2,n);
		n++;
	}	
	for(int i=pre;i<mid;i++)
	{
		if(egg->hight[i]== shatter)
		return egg->hight[i-1];
	}
}

int main()
{
	int i,n;
	test *egg;
	egg = CreatList();
	Display(egg);
	cout<<"\n 鸡蛋的等级是\t"<< experiment(egg);
}
