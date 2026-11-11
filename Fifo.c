#include <stdio.h>

int main()
{
    int n, f, i, j, k = 0;
    int pages[50], frames[10];
    int faults = 0, hits = 0, found;
    printf("Enter number of frames: ");
    scanf("%d", &f);
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    for(i = 0; i < f; i++)
        frames[i] = -1;
    for(i = 0; i < n; i++)
    {
        found = 0;
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                hits++;
                break;
            }
        }
        if(found == 0)
        {
            frames[k] = pages[i];
            k = (k + 1) % f;
            faults++;
        }
        printf("\n");
        for(j = 0; j < f; j++)
        {
            if(frames[j] == -1)
                printf("_ ");
            else
                printf("%d ", frames[j]);
        }
    }
    printf("\n\nPage Hits = %d", hits);
    printf("\nPage Faults = %d", faults);
    return 0;
}
