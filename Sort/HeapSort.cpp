#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//������ 
void HeapSort(int *a, int len);
//�����󶥶� 
void BuildMaxHeap(int *a,int len);
//��ĳ����Ҷ�ڵ������Ӧ���ӽڵ���ϴ󶥶ѵ����� 
void heapify(int *a, int i,int len); 
void Show(int *a, int n);
void Swap(int * a, int * b);

int main(void)
{
	int a[9] = {
		4,2,6,1,7,3,9,0,3 
	};
	HeapSort(a,9);
	Show(a,9);
	return 0;
}

void HeapSort(int *a, int len)
{
	if(a == NULL)
		return;
	BuildMaxHeap(a,len);
	
	for(int i = len-1; i > 0; i--)
	{
		Swap(&a[0],&a[i]);
		len--;
		heapify(a,0,len);
	}
}

void BuildMaxHeap(int *a,int len)
{
	for(int i = floor(len/2)-1; i>=0; i--)
		heapify(a,i,len);
}

void heapify(int *a, int i,int len)
{
	//������i�Ƿ�Ҷ�ӽڵ㣬left��right�ֱ������������ӽڵ㣬Ĭ�ϵ�ǰi��Ӧ�Ľڵ㣨���ڵ㣩�����ֵ 
	int left = 2*i+1;
	int right = 2*i+2;
	int largestIndex = i;
	// �������ڵ㣬������ڵ��ֵ���󣬸������ֵ������
	if(left<len && a[left]>a[largestIndex])
		largestIndex = left; 
	// ������ҽڵ㣬�����ҽڵ��ֵ���󣬸������ֵ������
 	if(right<len && a[right]>a[largestIndex])
	 	largestIndex = right;
	 	
 	if(largestIndex != i)
 	{
	 	Swap(&a[i],&a[largestIndex]);
	 	heapify(a,largestIndex,len);
 	}	
} 

void Swap(int * a, int * b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void Show(int * a, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
