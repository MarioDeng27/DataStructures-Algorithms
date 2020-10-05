#include<iostream>
using namespace std;

int* CountSort (int Arr[],int len);
int GetMax(int Arr[],int len);
int GetMin(int Arr[],int len);
void Show(int Arr[],int len);
int main()
{
	cout<<"s"<<endl;
	int a[10] = {
		95, 94, 91, 98, 99, 90, 99, 93, 91, 92
	};
	int* b = CountSort(a,10);
	Show(a,10);
	Show(b,10);
	return 0;
} 

int* CountSort(int Arr[],int len)
{
	int max = Arr[0];
	int min = Arr[0];
	for(int i =1; i<len; i++)
	{
		if(Arr[i]>max)
			max = Arr[i];
	}
	for(int i =1; i<len; i++)
	{
		if(Arr[i]<min)
			min = Arr[i];
	}
	
	int d = max - min;
	int * CountArr = new int[d + 1]();
	for (int i = 0; i < d + 1; i ++) 
	{
		CountArr[i] = 0;
	}
	for(int i = 0; i<len; i++)
	{
		CountArr[Arr[i]-min]+= 1;
	}
	int sum = 0;
	for(int i = 0; i<len; i++)
	{
		sum += CountArr[i];
		CountArr[i] = sum;	
	}	
	int * SortedArr= new int[len];
	int index = 0;
	for(int i = len-1; i>=0; i--)
	{
		index = CountArr[Arr[i]-min] - 1;
		SortedArr[index] = Arr[i];
		CountArr[Arr[i]-min]-= 1;
	}
	return SortedArr;
}

int GetMax(int Arr[],int len)
{
	int max = Arr[0];
	for(int i =1; i<len; i++)
	{
		if(Arr[i]>max)
			max = Arr[i];
	}
	return max;
}
int GetMin(int Arr[],int len)
{
	int min = Arr[0];
	for(int i =1; i<len; i++)
	{
		if(Arr[i]<min)
			min = Arr[i];
	}
	return min;
}

void Show(int Arr[],int len)
{
	for(int i = 0; i < len; i++)
	{
		cout<<Arr[i]<<" ";
	}
	cout<<endl;
}
