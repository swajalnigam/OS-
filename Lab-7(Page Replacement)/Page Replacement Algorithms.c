#include <stdio.h>

void FIFO(int pages[], int n, int f) {

    int frame[10], i, j, k = 0;
    int faults = 0, flag;

    for(i = 0; i < f; i++)
        frame[i] = -1;

    printf("\n--- FIFO Page Replacement ---\n");

    for(i = 0; i < n; i++) {

        flag = 0;

        for(j = 0; j < f; j++) {

            if(frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            frame[k] = pages[i];
            k = (k + 1) % f;
            faults++;
        }

        printf("\n");

        for(j = 0; j < f; j++) {
            printf("%d\t", frame[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d\n", faults);
}

void LRU(int pages[], int n, int f) {

    int frame[10], time[10];
    int i, j, pos, faults = 0, count = 0;
    int flag1, flag2, minimum;

    for(i = 0; i < f; i++)
        frame[i] = -1;

    printf("\n--- LRU Page Replacement ---\n");

    for(i = 0; i < n; i++) {

        flag1 = flag2 = 0;

        for(j = 0; j < f; j++) {

            if(frame[j] == pages[i]) {
                count++;
                time[j] = count;
                flag1 = flag2 = 1;
                break;
            }
        }

        if(flag1 == 0) {

            for(j = 0; j < f; j++) {

                if(frame[j] == -1) {
                    count++;
                    faults++;
                    frame[j] = pages[i];
                    time[j] = count;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0) {

            minimum = time[0];
            pos = 0;

            for(j = 1; j < f; j++) {

                if(time[j] < minimum) {
                    minimum = time[j];
                    pos = j;
                }
            }

            count++;
            faults++;
            frame[pos] = pages[i];
            time[pos] = count;
        }

        printf("\n");

        for(j = 0; j < f; j++) {
            printf("%d\t", frame[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d\n", faults);
}

void Optimal(int pages[], int n, int f) {

    int frame[10];
    int i, j, k, pos, faults = 0;
    int flag1, flag2, farthest, index;

    for(i = 0; i < f; i++)
        frame[i] = -1;

    printf("\n--- Optimal Page Replacement ---\n");

    for(i = 0; i < n; i++) {

        flag1 = flag2 = 0;

        for(j = 0; j < f; j++) {

            if(frame[j] == pages[i]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        if(flag1 == 0) {

            for(j = 0; j < f; j++) {

                if(frame[j] == -1) {
                    faults++;
                    frame[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0) {

            farthest = -1;

            for(j = 0; j < f; j++) {

                index = -1;

                for(k = i + 1; k < n; k++) {

                    if(frame[j] == pages[k]) {
                        index = k;
                        break;
                    }
                }

                if(index == -1) {
                    pos = j;
                    break;
                }

                if(index > farthest) {
                    farthest = index;
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            faults++;
        }

        printf("\n");

        for(j = 0; j < f; j++) {
            printf("%d\t", frame[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d\n", faults);
}

int main() {

    int pages[50];
    int n, f, i, choice;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("\n1. FIFO");
    printf("\n2. LRU");
    printf("\n3. Optimal");
    printf("\n4. All Algorithms");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            FIFO(pages, n, f);
            break;

        case 2:
            LRU(pages, n, f);
            break;

        case 3:
            Optimal(pages, n, f);
            break;

        case 4:
            FIFO(pages, n, f);
            LRU(pages, n, f);
            Optimal(pages, n, f);
            break;

        default:
            printf("Invalid Choice");
    }

    return 0;
}