#include <stdio.h>
int main()
{
    int n, f, i, j, k;
    int pages[50], frames[10], time[10];
    int faults = 0, hits = 0, found, min;
    printf("Enter number of frames: ");
    scanf("%d", &f);
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }
    for(i = 0; i < n; i++)
    {
        found = 0;
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                hits++;
                found = 1;
                time[j] = i + 1;
                break;
            }
        }
        if(found == 0)
        {
            faults++;
            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                    break;
            }
            if(j == f)
            {
                min = 0;
                for(k = 1; k < f; k++)
                {
                    if(time[k] < time[min])
                        min = k;
                }
                j = min;
            }
            frames[j] = pages[i];
            time[j] = i + 1;
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
    printf("\nHit Ratio = %.2f%%", (float)hits / n * 100);
    return 0;
}
