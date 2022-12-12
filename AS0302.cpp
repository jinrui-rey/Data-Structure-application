#include <iostream>
#include <cmath>
using namespace std;
#define Maxsize 50

typedef struct String
{
	char data[Maxsize];
	int length;	
}str;

str Creat_str(str s, char a[])
{
	int i;
	for(i=0; a[i]!= '\0';i++)
		s.data[i] = a[i];
	s.length = i;
	return s;
}

void Display(str s)
{
	int i=0;
	while(s.data[i]!= '\0')
	{
		cout<<s.data[i];
		i++;
	}
}

void coincide(str s, str t)		//BF算法 
{
	int i=0,j=0;
	while(i<s.length && j<t.length)		
	{
		if(s.data[i] == t.data[j] || t.data[j]=='*')//当主串和模式串的元素相等，或模式串元素为“*”时，两指针继续++ 
		{
			i++;
			j++;
		}
		else	//主串指针回溯 
		{
			i = i-j+1;
			j=0;
		}
	}
	if(j>=t.length )		//判断是否匹配到 
	cout<<i-t.length;
	else 
	cout<<"不匹配"; 
}

void Getnext(str t , int next[]) //输出模式串的next数组 
{
	int j,k;
	j=0;k=-1;next[0]=-1;
	while(j<t.length-1)
	{
		if( k==-1|| t.data[j] == t.data[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else k=next[k];
	}
	
}

void KMP_coincide(str s, str t)//KMP算法 
{
	int next[Maxsize],i=0,j=0;
	Getnext(t,next);
	while(i<s.length && j<t.length)
	{
		if(j == -1 || s.data[i] == t.data[j] || t.data [j] =='*')//当主串和模式串的元素相等，或模式串元素为“*”时，两指针继续++ 
		{
			i++;
			j++;
		}
		else j= next[j]; //主串指针不变，模式串指正到next[j] 处 
	}
	if(j >= t.length )	//判断是否匹配到 
	cout<<i-t.length;
	else
	cout<<"不匹配"; 
}

int main()
{
	char a[5]={'a','b','c','d','e'};
	str s;
	s = Creat_str(s,a);
	Display(s);
	char b[3]={'c','*','e',};
	str t;
	t = Creat_str(t,b);
	Display(t);
	cout<<"\n";
	KMP_coincide(s,t);
}
