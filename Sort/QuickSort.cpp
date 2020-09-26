#include <stdio.h>
#include <stdlib.h>

void QuickSort(int * a, int L, int R);
void QuickSort2(int * a, int L, int R);
int FindPos(int *a, int L, int R);
void Show(int * a, int n);
int main(void)
{


    int a[15] = {4,2,5,1,6,3,9,3,12,4,1,41,2,412,5};
    QuickSort2(a,0,14);

    /*
int a[7] = {4,2,5,1,6,3,9};
    QuickSort2(a,0,6);*/
/*
    int a[7] = {4,2,2,1,1,3,9};
    QuickSort2(a,0,6);*/

    Show(a,15);
    return 0;
}

void QuickSort(int * a, int L, int R)
{
	if(L<R)
	{
		int p = FindPos(a,L,R);
		QuickSort(a,L,p-1);
		QuickSort(a,p+1,R);
	}
}

int FindPos(int *a, int L, int R)
{
	int i = L; 
	int j = R;
	int val = a[i];
	while(i<j)
	{
		while(i<j && a[j] > val)
		{
			j--;
		}
		if(i<j)
		{
			a[i] = a[j];
		}
		while(i<j && a[i] < val)
		{
			i++;
		}
		if(i<j)
		{
			a[j] = a[i];
		}
	}
	a[i] = val;
	return i;
}

void QuickSort2(int * a, int L, int R)
{
	if(L<R)
	{
		int i = L;
		int j = R;
		int pivot = a[(L+R)/2];
		while(i <=j)
		{
			while(a[i]<pivot)
			{
				i++;
			}
			while(a[j]>pivot)
			{
				j--;
			}
			if(i<=j)
			{ 
				if(i!=j)
				{
					int t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
				i++;
				j--;		
			}
		}//直到i=j时退出
		QuickSort2(a,L,j);
		QuickSort2(a,i,R); 
	}	
}


void Show(int * a, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
}
