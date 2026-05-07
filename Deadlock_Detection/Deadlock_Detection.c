#include <stdio.h>

int main() {
    int n, m, i, j, k = 0, found;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], request[n][m], avail[m];
    int finish[n], safe[n], work[m];

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i);
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }

    printf("Enter Request Matrix:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i);
        for(j = 0; j < m; j++)
            scanf("%d", &request[i][j]);
    }

    printf("Enter Available Resources: ");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for(i = 0; i < n; i++)
        finish[i] = 0;

    for(i = 0; i < m; i++)
        work[i] = avail[i];

    while(k < n) {
        found = 0;

        for(i = 0; i < n; i++) {
            if(!finish[i]) {

                for(j = 0; j < m; j++) {
                    if(request[i][j] > work[j])
                        break;
                }

                if(j == m) {
                    for(j = 0; j < m; j++)
                        work[j] += alloc[i][j];

                    safe[k++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(!found)
            break;
    }

    if(k == n) {
        printf("System is in safe state.\n");
        printf("Safe Sequence is: ");

        for(i = 0; i < n; i++)
            printf("P%d ", safe[i]);
    }
    else {
        printf("Deadlock detected!\n");
    }

    return 0;
}