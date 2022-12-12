#include <iostream>
using namespace std;

#define Max 50
#define INF 1000

typedef struct
{
	int no;
	char village_name;
 } vertex;
 
typedef struct
{
	int edges[50][50];
	int n,e;
	vertex vetx[50];
}graph;

int mini(int a[],int num)
{
	int i,j;
	int less = Max;
	for(i=0;i<num;i++)
	{
		if (a[i] <= less)
			less = a[i];
	}
	for(j=0;j<num;j++)
		if(a[j] == less)
			return j+1;
}

void Floyd(graph g)
{
	int A[Max][Max],path[Max][Max];
	int i,j,k;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
		{
			A[i][j] = g.edges[i][j];
			if (i==j || g.edges[i][j] == 0)
				path[i][j] = -1;
			else
				path[i][j] = i;
		}
		
	for (k=0;k<g.n;k++)
	{
		for(i=0;i<g.n;i++)
			for(j=0;j<g.n;j++)
				if(A[i][j] >A[i][k]+A[k][j])
				{
					A[i][j] = A[i][k]+ A[k][j];
					path[i][j] = path[k][j];
				}
	}
	int least[g.n];
	int less[Max][Max];
	int x,y,u,v;
	for (x=0;x<g.n;x++)//把A矩阵同步到less矩阵 ，此后对least矩阵做操作 
		for(y=0;y<g.n;y++)
			less[x][y] = A[x][y];
	
	int p,q;
	int little;
	for(p=0;p<g.n;p++) //least数组存放less矩阵每行最大值 
	{	
		little = 0;
		for(q=0;q<g.n;q++)
		{
			
			if(less[p][q]>little)
				little = less[p][q];
			least[p] = little;
		}
	}
	
	cout<<mini(least,g.n);

}


int main()
{
	int i,j;
	graph g;
	int vill,value;
	cin>>vill;
	g.n = vill;
	g.e = vill;
	int V[vill][vill];

	for (int u=0;u<vill;u++)
		for(int v=0; v<vill;v++)
		{
			cin>>value;
			if(u!=v&&value==0)
				value = INF;
			V[u][v] = value;
		}
	for(i=0;i<g.n;i++)
		for(j=0;j<g.n;j++)
			g.edges[i][j] = V[i][j];
	cout<<endl; 
	Floyd(g);                                                                                                                                                                                           
}
