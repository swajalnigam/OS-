#include <stdio.h>
#include <stdlib.h>

int main() {

    int req[100], used[100] = {0};
    int n, head, i, j, seek = 0, ch, temp, diskSize;
    printf("\nSwajal Nigam(1BF24CS312)");
    printf("\n1.FCFS");
    printf("\n2.SSTF");
    printf("\n3.SCAN");
    printf("\n4.C-LOOK");
    printf("\nEnter choice: ");

    scanf("%d", &ch);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");

    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {

            if (req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    switch (ch) {

        case 1:
            for (i = 0; i < n; i++) {
                seek += abs(req[i] - head);
                head = req[i];
            }

            printf("FCFS Seek Time = %d", seek);
            break;

        case 2:
            for (i = 0; i < n; i++) {

                int min = 100000, idx = -1;

                for (j = 0; j < n; j++) {

                    int d = abs(req[j] - head);

                    if (!used[j] && d < min) {
                        min = d;
                        idx = j;
                    }
                }

                used[idx] = 1;
                seek += min;
                head = req[idx];
            }

            printf("SSTF Seek Time = %d", seek);
            break;

        case 3:
            printf("Enter disk size: ");
            scanf("%d", &diskSize);

            for (i = 0; i < n; i++) {

                if (req[i] >= head) {
                    seek += abs(req[i] - head);
                    head = req[i];
                }
            }

            seek += abs((diskSize - 1) - head);

            printf("SCAN Seek Time = %d", seek);
            break;

        case 4:
            for (i = 0; i < n; i++) {
                seek += abs(req[i] - head);
                head = req[i];
            }

            printf("C-LOOK Seek Time = %d", seek);
            break;

        default:
            printf("Invalid Choice");
    }

    return 0;
}
