#include <stdlib.h>
#include <stdio.h>
int main()
{
    char a[110]= "#include <stdio.h>\nint main()\n{\n    printf(\"Hello 120L021809-学渣\");\n    return 0;\n}";
    int i = 0;
    int flag = 0;
    while (a[i] != '\0')
    {
        if(flag==0)
        {
            if(a[i]=='\n')
            {
                printf("  \\n");
            }
            else{
                printf("%4c", a[i]);
            }
        }
        else if(flag==1)
        {
            printf("%4x", a[i]);

        }
        if((i+1)%16==0&&flag==0)
        {
            flag = 1;
            i = i - 16;
            printf("\n");
        }
        else if((i+1)%16==0&&flag==1)
        {
            flag = 0;
            printf("\n");
        }
        i++;
    }
    printf("\n%4x%4x%4x", ';', '\n', '}');
    return 0;
}
