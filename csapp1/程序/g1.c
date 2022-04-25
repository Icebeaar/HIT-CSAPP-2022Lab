#include <stdio.h>

int fibonacci(int n)
{
    if(n==1)
        return n;
    else if(n==2)
        return n - 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    double g = 0;
    g =(double) fibonacci(50) /(double) fibonacci(51);
    printf("%lf", g);
    return 0;
}
