#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[10];
    int tempBlock[10];
    int i, j;

    for(i = 0; i < m; i++)
        tempBlock[i] = blockSize[i];

    for(i = 0; i < n; i++) {
        allocation[i] = -1;

        for(j = 0; j < m; j++) {
            if(tempBlock[j] >= processSize[i]) {
                allocation[i] = j;
                tempBlock[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\n--- FIRST FIT ---\n");
    printf("Process No\tProcess Size\tBlock No\n");

    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[10];
    int tempBlock[10];
    int i, j, bestIdx;

    for(i = 0; i < m; i++)
        tempBlock[i] = blockSize[i];

    for(i = 0; i < n; i++) {
        allocation[i] = -1;
        bestIdx = -1;

        for(j = 0; j < m; j++) {
            if(tempBlock[j] >= processSize[i]) {

                if(bestIdx == -1 ||
                   tempBlock[j] < tempBlock[bestIdx]) {

                    bestIdx = j;
                }
            }
        }

        if(bestIdx != -1) {
            allocation[i] = bestIdx;
            tempBlock[bestIdx] -= processSize[i];
        }
    }

    printf("\n--- BEST FIT ---\n");
    printf("Process No\tProcess Size\tBlock No\n");

    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[10];
    int tempBlock[10];
    int i, j, worstIdx;

    for(i = 0; i < m; i++)
        tempBlock[i] = blockSize[i];

    for(i = 0; i < n; i++) {
        allocation[i] = -1;
        worstIdx = -1;

        for(j = 0; j < m; j++) {
            if(tempBlock[j] >= processSize[i]) {

                if(worstIdx == -1 ||
                   tempBlock[j] > tempBlock[worstIdx]) {

                    worstIdx = j;
                }
            }
        }

        if(worstIdx != -1) {
            allocation[i] = worstIdx;
            tempBlock[worstIdx] -= processSize[i];
        }
    }

    printf("\n--- WORST FIT ---\n");
    printf("Process No\tProcess Size\tBlock No\n");

    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {

    int blockSize[10], processSize[10];
    int m, n, i, choice;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter size of each block:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter size of each process:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    printf("\n1. First Fit");
    printf("\n2. Best Fit");
    printf("\n3. Worst Fit");
    printf("\n4. All Techniques");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            firstFit(blockSize, m, processSize, n);
            break;

        case 2:
            bestFit(blockSize, m, processSize, n);
            break;

        case 3:
            worstFit(blockSize, m, processSize, n);
            break;

        case 4:
            firstFit(blockSize, m, processSize, n);
            bestFit(blockSize, m, processSize, n);
            worstFit(blockSize, m, processSize, n);
            break;

        default:
            printf("Invalid Choice");
    }

    return 0;
}