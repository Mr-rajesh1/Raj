#include <stdio.h>
int main()
{
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d%d%d", &a, &b, &c);
    if(a > b)
    {
        if(a > c)
            printf("Maximum = %d", a);
        else
            printf("Maximum = %d", c);
    }
    else
    {
        if(b > c)
            printf("Maximum = %d", b);
        else
            printf("Maximum = %d", c);
    }
    return 0;
}
