#include <stdio.h>

int main()
{
    double a[100];
    double g = 0;
    int n = 100,i=0;
    for (i = 0; i <= n;i++)
    {
        if(i==0)
            a[i]=1;
        else if(i==1)
            a[i] = 1;
        else{
            a[i] = a[i - 1] + a[i - 2];
        }
    }
    g = a[99] / a[100];
    printf("%.8f", g);
}