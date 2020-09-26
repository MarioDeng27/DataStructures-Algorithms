#include <stdio.h>
#include <stdlib.h>

//����������a[]��b[]�ϲ���c[]�У�n��a����ĳ��ȣ�m��b����ĳ��� ����Ҫ�������ô�������������и��ϲ��� 
void MemeryArray(int *a, int n, int *b, int m, int *c);
void mergearray(int *a, int first, int mid, int last, int *temp); 
void mergesort(int *a, int first, int last, int *temp);
bool MergeSort(int *a, int n);
void Show(int *a, int n);

int main(void)
{
	int a[15] = {4,2,5,1,6,3,9,3,12,4,1,41,2,412,5};
	int *b;
	Show(a,15);
    MergeSort(a,15);
    Show(a,15);
    return 0;
}

void mergearray(int *a, int first, int mid, int last, int *temp)
{
	int i = first;
	int j = mid + 1;
	int k = 0;
	while(i<=mid && j<=last)
	{
		if(a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	while(j<=last)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = 0; i < k; i++)
        a[first + i] = temp[i];
}
void mergesort(int *a, int first, int last, int *temp)
{
	if(first<last)
	{
		int mid = (first+last)/2;
		mergesort(a,first,mid,temp);
		mergesort(a,mid+1,last,temp);
		mergearray(a,first,mid,last,temp);	
	}
}

bool MergeSort(int * a, int n)
{
	int * p = (int*) malloc(sizeof(int)*n);
/*
	int * p;*/
	if(p == NULL)
	{
		printf("��̬�����ڴ�ʧ�ܣ�");
		return false;	
	}
	mergesort(a,0,n-1,p);
	free(p);
	return true;
}


void Show(int * a, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void MemeryArray(int *a, int n, int *b, int m, int *c)
{
	int i = 0; //for a
	int j = 0; //for b
	int k = 0; //for c
	while(i<n && j<m)
	{
		if(a[i]<b[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = b[j];
			k++;
			j++;
		}
	}
	while(i<n)
	{
		c[k] = a[i];
		k++;
		i++;
	}
	while(j<m)
	{
		c[k] = b[j];
		k++;
		j++;
	}	
}