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


void coincide(str s, str t)		//BF�㷨 
{
	int i=0,j=0,count=0;
	int position;
	while(i<s.length)		//����ָ����������β 
	{
		if(s.data[i] == t.data[j])	//������ģʽ��Ԫ����� 
		{
			i++;
			j++;
			if(j==t.length-1)	//���ģʽ��ָ���Ѿ����˴�β��˵��ƥ��ɹ�����¼������λ�� 
				{
					count++; //��¼���� 
					position = i - t.length+1; //��¼λ�� 
					cout<<"��"<<count<<"ƥ���λ��Ϊ��s["<<position<<"]";
					j=0;		//ģʽ��ָ�����ݣ�������һ��ƥ��	
				}
		}
		else	//����ָ����� 
		{
			i = i-j+1;
			j=0;
		}
	}
	cout<<"��ƥ��"<<count<<"��";
}


void Getnext(str t , int next[]) //���ģʽ����next���� 
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

void KMP_coincide(str s, str t)//KMP�㷨 
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
			if(j==t.length-1)	//���ģʽ��ָ���Ѿ����˴�β��˵��ƥ��ɹ�����¼������λ�� 
				{
					count++; //��¼���� 
					position = i - t.length+1; //��¼λ�� 
					cout<<"��"<<count<<"ƥ���λ��Ϊ��s["<<position<<"]";
					j=0;		//ģʽ��ָ�����ݣ�������һ��ƥ��	
				}
		}
		else j= next[j]; //����ָ�벻�䣬ģʽ��ָ����next[j] �� 
	}
	cout<<"��ƥ��"<<count<<"��";
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
