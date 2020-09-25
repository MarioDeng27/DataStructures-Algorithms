#include <stdio.h>
#include <stdlib.h>

void SelectSort(int * a, int n);
void Show(int * a, int n);
int main(void)
{
    int a[15] = {4,2,5,1,6,3,9,3,12,4,1,41,2,412,5};
    SelectSort(a,15);

    Show(a,15);
    return 0;
}

void SelectSort(int * a, int n)
{
    for(int i = 0; i < n-1 ; i++) //需要选择几次,每次选出最小的数字
    {
        for(int j = i; j < n; j++) //各选择中需要进行几次比较
        {
            if(a[i] > a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}
void Show(int * a, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
}
