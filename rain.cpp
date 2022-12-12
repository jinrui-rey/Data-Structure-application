#include <iostream>
#include <cmath>
using namespace std;
#define Maxsize 50

int Plus_ele(int a[],int n)	//���ڼ�������������Ԫ��֮�� 
{
	int result=0;
	for(int i=0;i<n;i++)
	{
		result = result +a[i];
	}
	return result;
}
int Cal_rain(int a[],int n)
{
	int j;
	int large;
	int left_larger[Maxsize];		//���ڱ���λ��i������ĸ߶� 
	for(int i=0;i<n;i++)
	{
		j=0;//ÿ�ζ���Ҫ�ӵ�һ��Ԫ�ؿ�ʼɨ�� 
		large = a[i]; //���ֵ��ʼ��Ϊheight[i]���� 
		while(j<i)//�ӵ�һ��Ԫ�ص���i��Ԫ�� 
		{
			if (a[j]>large) //��¼����Ԫ�� 
			large = a[j];
			j++;
		}
		left_larger[i] = large;//������Ԫ�ر���������left_larger[]�� 
	}
	int right_larger[Maxsize];		//���ڱ���λ��i�ұ����ĸ߶� 
	for(int i=0;i<n;i++)
	{
		j=i+1;	//ÿ�δӵ�i+1��Ԫ�ؿ�ʼɨ�� 
		large = a[i];//��ʼֵ��Ϊheight[i]���� 
		while(j<n)//�ӵ�i+1��Ԫ�ص����һ��Ԫ�� 
		{
			if (a[j]>large)//��¼����Ԫ�� 
			large = a[j];
			j++;
		}
		right_larger[i] = large;//������Ԫ�ر���������right_larger[]�� 
	}
	int minus[Maxsize];//���ڱ�������ÿ��λ���ܴ����ˮ�� 
	for(int k=0;k<n;k++)//ʵ��min(left_larger[i], right_larger[i])-height[i]
	{
		if (right_larger[k]<=left_larger[k])//ȡ�����������ұ�������еĽ�Сֵ 
		minus[k] =right_larger[k]-a[k];//�ý�Сֵ��ȥhieght[i]�����õ�ÿ��λ���ܴ����ˮ����������minus������ 
		else
		minus[k] =left_larger[k]-a[k];
	}
	
	int result;
	result = Plus_ele(minus,n);//������ˮ�������������ռ�����ˮ�� 
	return result;
}


int main()
{
	cout<<"input the number of bars";
	int n;
	cin>>n;
	int height[n];
	cout<<"input the height of each bar";
	for(int i=0;i<n;i++)
	{
		cin>>height[i];
	}
	cout<<"it can hold "<<Cal_rain(height,n)<<" volum of water";
}
