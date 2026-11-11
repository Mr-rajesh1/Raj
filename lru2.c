#include <stdio.h>
#include <limits.h>
#define MAX_FRAMES 20
#define MAX_REFS   200
static int frames[MAX_FRAMES];
static int lastUsed[MAX_FRAMES];
static int numFrames;
static int findFrameOf(int page, int filled) {
    for (int i = 0; i < filled; i++)
        if (frames[i] == page) return i;
    return -1;
}
static int findLRUSlot(int filled) {
    int victim = 0;
    for (int i = 1; i < filled; i++)
        if (lastUsed[i] < lastUsed[victim]) victim = i;
    return victim;
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
    for (int i = 0; i < numFrames; i++) { frames[i] = -1; lastUsed[i] = INT_MIN; }
    int filled = 0;
    int faults = 0, hits = 0;
    int clock = 0;            
    printf("\nRef\tAction\tFrames\n");
    for (int i = 0; i < n; i++) {
        int page = refs[i];
        clock++;
        printf("%d\t", page);
        printf slot = findFrameOf(page, filled);
        if (slot != -1) {
            hits++;
            lastUsed[slot] = clock;          
            printf("HIT\t");
            printFrames(filled);
        } else {
            faults++;
            if (filled < numFrames) {
                frames[filled] = page;
                lastUsed[filled] = clock;
                filled++;
                printf("FAULT\t");
                printFrames(filled);
            } else {
                int victim = findLRUSlot(filled);
                printf("FAULT\t(evict %d)\t", frames[victim]);
                frames[victim] = page;
                lastUsed[victim] = clock;
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
