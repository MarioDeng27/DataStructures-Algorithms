#include <stdio.h>
#include <stdlib.h>

void InsertSort(int * a, int n);
void InsertSort2(int * a, int n);

void Show(int * a, int n);
int main(void)
{
    int a[15] = {4,2,5,1,6,3,9,3,12,4,1,41,2,412,5};
    InsertSort2(a,15);

    Show(a,15);
    return 0;
}

void InsertSort(int * a, int n)
{
    for(int i = 1; i < n ; i++) //需要插入的进行排序的次数,每次将元素拍到合适的位置其他比它大的数字往后移动
    {
        int j = i-1;
        int val = a[i];
        while(j>=0 && val < a[j])
        {
            int t = a[j];
            a[j] = a[j+1];
            a[j+1] = t;
            j--;
        }
    }
}

void InsertSort2(int * a, int n)
{
    for(int i = 1; i < n ; i++) //需要插入的进行排序的次数,每次将元素拍到合适的位置其他比它大的数字往后移动
    {
        int j = i-1;
        int val = a[i];
        while(j>=0 && val < a[j])
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = val;
    }
}

void Show(int * a, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
}
