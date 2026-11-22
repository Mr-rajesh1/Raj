#include <stdio.h>
int main()
{
    int a[50],n,i,k;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    scanf("%d",&k);

    for(i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            printf("Found at index %d",i);
            return 0;
        }
    }

    printf("Not Found");
    return 0;
}
