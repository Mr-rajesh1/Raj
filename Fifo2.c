#include <stdio.h>
#define MAX_FRAMES 20
#define MAX_REFS   200
static int frames[MAX_FRAMES];
static int numFrames;
static int isPresent(int page, int filled) {
    for (int i = 0; i < filled; i++)
        if (frames[i] == page) return 1;
    return 0;
}
static void printFrames(int filled) {
    printf("[ ");
    for (int i = 0; i < numFrames; i++) {
        if (i < filled) printf("%d ", frames[i]);
        else printf("_ ");
    }
    printf("]");
}
int main() {
    int n;
    printf("Enter number of frames: ");
    if (scanf("%d", &numFrames) != 1 || numFrames <= 0 || numFrames > MAX_FRAMES) {
        printf("Invalid number of frames.\n");
        return 1;
    }
    printf("Enter length of reference string: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_REFS) {
        printf("Invalid length.\n");
        return 1;
    }
    int refs[MAX_REFS];
    printf("Enter the %d page references: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &refs[i]);
    for (int i = 0; i < numFrames; i++) frames[i] = -1;
    int filled = 0;          
    int nextVictim = 0;      
    int faults = 0, hits = 0;
    printf("\nRef\tAction\tFrames\n");
    for (int i = 0; i < n; i++) {
        int page = refs[i];
        printf("%d\t", page);
        if (isPresent(page, filled)) {
            hits++;
            printf("HIT\t");
            printFrames(filled);
        } else {
            faults++;
            if (filled < numFrames) {
                frames[filled] = page;
                filled++;
                printf("FAULT\t");
                printFrames(filled);
            } else {
                printf("FAULT\t(evict %d)\t", frames[nextVictim]);
                frames[nextVictim] = page;
                nextVictim = (nextVictim + 1) % numFrames;   /* advance FIFO queue */
                printFrames(filled);
            }
        }
        printf("\n");
    }
    printf("\nTotal references : %d\n", n);
    printf("Page hits         : %d\n", hits);
    printf("Page faults       : %d\n", faults);
    printf("Hit ratio         : %.2f%%\n", 100.0 * hits / n);
    return 0;
}
