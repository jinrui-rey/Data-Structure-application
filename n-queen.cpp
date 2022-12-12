/*���ݽṹ�ϻ�1*/
#include <iostream> 
#include <cmath>
using namespace std;
#define N 100
int q[N];		//��ʾ���̣���i�У���q[i]�� 
int count = 0;		//���ڼƽ������ 
void print(int n)		//���һ��� 
{
	count++;
	int i;
	cout<<"��"<<count<<"����";
	for(i=1; i<=n;i++)
		cout<<"("<<i<<","<<q[i]<<")";
	cout<<'\n'; 
}

bool place(int row, int col)	//�жϵ�row�У���col���Ƿ���Է���һ���ʺ� 
{
	int i = 1;
	while(i<row)
	{
		if (q[i]==col || (abs(q[i]-col)) == (abs(row-i)))	//�ж��г�ͻ��б�߳�ͻ 
			return false;
			i++;
	}
	return true;
}

void queen(int i, int n)	//���õ�i���ʺ�ֱ����n���ʺ� 
{
	int j;
	if(i>n)		 //������õ���n���ʺ����ҵ�һ���⣬��ӡ 
		print(n);
	else 
	{
		for(j=1;j<=n;j++)	//�ӵ�1�е���n�б������Ƿ����ܷ��ûʺ�ĵط� 
			if(place(i,j))
			{
				q[i] = j;
				queen(i+1,n);	//������Է��ûʺ󣬿�ʼѰ����һ���ʺ��λ�� 
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
