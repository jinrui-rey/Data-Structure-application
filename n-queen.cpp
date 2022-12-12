/*数据结构上机1*/
#include <iostream> 
#include <cmath>
using namespace std;
#define N 100
int q[N];		//表示棋盘，第i行，第q[i]列 
int count = 0;		//用于计解的数量 
void print(int n)		//输出一组解 
{
	count++;
	int i;
	cout<<"第"<<count<<"个解";
	for(i=1; i<=n;i++)
		cout<<"("<<i<<","<<q[i]<<")";
	cout<<'\n'; 
}

bool place(int row, int col)	//判断第row行，第col列是否可以放下一个皇后 
{
	int i = 1;
	while(i<row)
	{
		if (q[i]==col || (abs(q[i]-col)) == (abs(row-i)))	//判断列冲突和斜线冲突 
			return false;
			i++;
	}
	return true;
}

void queen(int i, int n)	//放置第i个皇后，直到第n个皇后 
{
	int j;
	if(i>n)		 //如果放置到第n个皇后，则找到一个解，打印 
		print(n);
	else 
	{
		for(j=1;j<=n;j++)	//从第1列到第n列遍历，是否有能放置皇后的地方 
			if(place(i,j))
			{
				q[i] = j;
				queen(i+1,n);	//如果可以放置皇后，开始寻找下一个皇后的位置 
			}
	}
}

int main()
{
	int n;
	cout<<"input the length of the keyboard";
	cin>>n;
	
	queen(1,n);
	cout<<'\n';
	
}
