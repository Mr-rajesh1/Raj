#include <stdio.h>
int main()
{
    int a[10], n, key, i;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter key: ");
    scanf("%d", &key);
    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            printf("Found at index %d", i);
            return 0;
        }
    }
    printf("Not found");
    return 0;
}
