#include <stdio.h>


int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}


int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int C[n], D[n], P[n], r[n];

    printf("Enter capacities:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &C[i]);
        r[i] = 0;
    }

    printf("Enter deadlines:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &D[i]);

    printf("Enter time periods:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &P[i]);


    int hp = P[0];
    for (int i = 1; i < n; i++)
        hp = lcm(hp, P[i]);

    printf("\nLCM=%d\n\n", hp);

    printf("Earliest Deadline First Scheduling:\n");
    printf("PID   Capacity   Deadline   Period\n");
    for (int i = 0; i < n; i++)
        printf("%d     %d          %d          %d\n", i + 1, C[i], D[i], P[i]);


    float u = 0;
    for (int i = 0; i < n; i++)
        u += (float)C[i] / P[i];

    printf("\nUtilization = %.6f\n", u);
    if (u > 1.0)
        printf("Warning: Utilization > 1, schedule may be infeasible.\n");

    int time = 0, prev = -2;

    printf("\nScheduling:\n");

    while (time < hp) {

        for (int i = 0; i < n; i++) {
            if (time % P[i] == 0)
                r[i] = C[i];
        }


        int min_deadline = 1000000;
        int selected = -1;

        for (int i = 0; i < n; i++) {
            if (r[i] > 0) {

                int instances = time / P[i];
                int abs_deadline = instances * P[i] + D[i];
                if (abs_deadline < min_deadline) {
                    min_deadline = abs_deadline;
                    selected = i;
                }
            }
        }

        if (selected != prev) {
            if (selected == -1)
                printf("%dms onwards: CPU is idle\n", time);
            else
                printf("%dms onwards: Process %d running\n", time, selected + 1);
            prev = selected;
        }

        if (selected != -1)
            r[selected]--;

        time++;
    }

    printf("\nScheduling completed at %d ms\n", time);

    return 0;
}