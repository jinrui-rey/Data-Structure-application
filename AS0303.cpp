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
	int i=0,j=0,count=0;
	int position;
	while(i<s.length)		//主串指针自增至串尾 
	{
		if(s.data[i] == t.data[j])	//主串与模式串元素相等 
		{
			i++;
			j++;
			if(j==t.length-1)	//如果模式串指针已经到了串尾，说明匹配成功，记录次数和位置 
				{
					count++; //记录次数 
					position = i - t.length+1; //记录位置 
					cout<<"第"<<count<<"匹配的位置为是s["<<position<<"]";
					j=0;		//模式串指正回溯，进行下一次匹配	
				}
		}
		else	//主串指针回溯 
		{
			i = i-j+1;
			j=0;
		}
	}
	cout<<"共匹配"<<count<<"次";
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
	int count=0;
	int position;
	Getnext(t,next);
	while(i<s.length && j<t.length)
	{
		if(j == -1 || s.data[i] == t.data[j])
		{
			i++;
			j++;
			if(j==t.length-1)	//如果模式串指针已经到了串尾，说明匹配成功，记录次数和位置 
				{
					count++; //记录次数 
					position = i - t.length+1; //记录位置 
					cout<<"第"<<count<<"匹配的位置为是s["<<position<<"]";
					j=0;		//模式串指正回溯，进行下一次匹配	
				}
		}
		else j= next[j]; //主串指针不变，模式串指正到next[j] 处 
	}
	cout<<"共匹配"<<count<<"次";
}

int main()
{
	char a[6]={'c','d','e','d','d','f'};
	str s;
	s = Creat_str(s,a);
	Display(s);
	char b[3]={'c','d','e',};
	str t;
	t = Creat_str(t,b);
	Display(t);
	cout<<"\n";
	KMP_coincide(s,t);
}
