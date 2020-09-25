#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ShellSort(int * a, int n);
void Show(int * a, int n);
void Swap(int * a, int * b);
int main(void)
{
    int a[15] = {4,2,5,1,6,3,9,3,12,4,1,41,2,412,5};
    ShellSort(a,15);
    printf("ShellSort完成排序,最终结果如下\n");
    Show(a,15);
/*     int a = 5,b=6;
    Swap(&a,&b);
    printf("%d %d",a,b); */
    return 0;
}

void ShellSort(int * a, int n)
{
    for(int h = floor(n/2); h>0; h=floor(h/2))
    {
        for(int i=h; i<n; i++)
        {
            for(int j=i-h; j>=0 && a[j]>a[j+h];j=j-h)
            {
                Swap(&a[j],&a[j+h]);
            }
        }
        printf("h=%d :",h);
        Show(a,n);
        printf("\n");
    }


}
void Show(int * a, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
}

void Swap(int * a, int * b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
