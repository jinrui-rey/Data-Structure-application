/*
张锦睿  2018302100103
*/
#include <iostream>
#include <cmath>
#include <malloc.h>
using namespace std;
 #define Maxsize 50
 
 struct Sqlist
 {
 	int data[Maxsize];
 	int length;
 };
 void creatList(Sqlist *&L, int a[], int n)//建立List 
 {
 	int i;
 	L=(Sqlist * )malloc(sizeof(Sqlist));
 	for(i=0;i<n;i++)
 		L->data[i]=a[i];
 		L->length = n;
 }
 void Display( Sqlist *L) //显示list 数据 
 {
 	int i;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
 	for(i=0;i<L->length;i++)
 		cout<<L->data[i]<<",";
 		cout<<"\t";
 		
 }
void Display_length( Sqlist *L) //显示list长度 
 {
 	cout<<"the length is "<<L->length;
 }


void delnode(Sqlist *&L)
{
  int i,j,k;
for(i=0;i<L->length;i++)
    {
    for(j=i+1;j<L->length;j++)
		if(L->data[j]==L->data[i])
        {
     		 if(j==L->length)			//如果在到表的最后找到 
      		{
      			L->data[j]=0;
       			L->length--;
       		}
      		else
        	{							//如果不是在最后找到 
     		for(k=j;k<L->length;k++)    //移动
       			L->data[k]=L->data[k+1];
       			L->length--;
       		}
       	j--; 
        }
}

}
int detectnode(Sqlist *L)//检查重复元素并提取 
{	
	int i,j,num,k;
	for(i=0;i<L->length;i++)
		{
			for(j=i+1;j<L->length;j++)
		{
			if(L->data [i]==L->data [j])
			num=L->data [i];
		}
		} 
			cout<<num;
			return num;
 } 
 int main()
 {
 	Sqlist *L;				
 	int a[7]={1,2,3,3,2,2,5};
 	int i=7;
 	creatList(L,a,i);
 	Display(L);
 	cout<<"\t";
	Display_length(L);
	delnode(L);
 	cout<<"\n";
	Display(L);
	Display_length(L);
 }
