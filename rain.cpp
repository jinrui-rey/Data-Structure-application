#include <iostream>
#include <cmath>
using namespace std;
#define Maxsize 50

int Plus_ele(int a[],int n)	//用于计算数组内所有元素之和 
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
	int left_larger[Maxsize];		//用于保存位置i左边最大的高度 
	for(int i=0;i<n;i++)
	{
		j=0;//每次都需要从第一个元素开始扫描 
		large = a[i]; //最大值初始设为height[i]本身 
		while(j<i)//从第一个元素到第i个元素 
		{
			if (a[j]>large) //记录最大的元素 
			large = a[j];
			j++;
		}
		left_larger[i] = large;//将最大的元素保存在数组left_larger[]内 
	}
	int right_larger[Maxsize];		//用于保存位置i右边最大的高度 
	for(int i=0;i<n;i++)
	{
		j=i+1;	//每次从第i+1个元素开始扫描 
		large = a[i];//初始值设为height[i]本身 
		while(j<n)//从第i+1个元素到最后一个元素 
		{
			if (a[j]>large)//记录最大的元素 
			large = a[j];
			j++;
		}
		right_larger[i] = large;//将最大的元素保存在数组right_larger[]内 
	}
	int minus[Maxsize];//用于保存最终每个位置能储存的水量 
	for(int k=0;k<n;k++)//实现min(left_larger[i], right_larger[i])-height[i]
	{
		if (right_larger[k]<=left_larger[k])//取左边最高柱和右边最高柱中的较小值 
		minus[k] =right_larger[k]-a[k];//用较小值减去hieght[i]自身，得到每个位置能储存的水量，保存在minus数组中 
		else
		minus[k] =left_larger[k]-a[k];
	}
	
	int result;
	result = Plus_ele(minus,n);//将所有水量加起来即能收集的雨水量 
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
