#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int * a, int n);
void Show(int * a, int n);
int main(void)
{
    int a[15] = {4,2,5,1,6,3,9,3,12,4,1,41,2,412,5};
    BubbleSort(a,15);

    Show(a,15);
    return 0;
}

void BubbleSort(int * a, int n)
{
    for(int i = 0; i < n-1 ; i++) //需要冒几次泡
    {
        for(int j = 1; j < n-i; j++) //各冒泡任务中需要比较的次数
        {
            if(a[j-1] > a[j])
            {
                int t = a[j-1];
                a[j-1] = a[j];
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
