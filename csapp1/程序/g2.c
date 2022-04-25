#include <stdio.h>

int main()
{
    long f1, f2, ff, f;
    double g = 0;
    int n = 100,i=0;
    float a, b;
    for (i = 0; i < n;i++)
    {
        if(i==0)
            f1= 1;
        else if(i==1)
            f2 = 1;
        else{
            f = f1 + f2;
            ff = f2 + f;
            f1 = f2;
            f2 = f;
        }
    }
    g = (float)f / (float)ff;
    printf("%f", g);
    printf("\n%ld,%ld", f, ff);
}