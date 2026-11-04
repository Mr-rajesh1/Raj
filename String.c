#include <stdio.h>
#include <string.h>
void reverse(char s[])
{
    int i;
    for(i = strlen(s) - 1; i >= 0; i--)
        printf("%c", s[i]);
}
int main()
{
    char s[50];
    printf("Enter string: ");
    scanf("%s", s);
    printf("Reverse = ");
    reverse(s);
    return 0;
}
