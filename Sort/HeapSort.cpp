#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//堆排序 
void HeapSort(int *a, int len);
//构建大顶堆 
void BuildMaxHeap(int *a,int len);
//对某个非叶节点和它对应的子节点符合大顶堆的性质 
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
	//索引：i是非叶子节点，left和right分别是两个左右子节点，默认当前i对应的节点（父节点）是最大值 
	int left = 2*i+1;
	int right = 2*i+2;
	int largestIndex = i;
	// 如果有左节点，并且左节点的值更大，更新最大值的索引
	if(left<len && a[left]>a[largestIndex])
		largestIndex = left; 
	// 如果有右节点，并且右节点的值更大，更新最大值的索引
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
