#include <stdio.h>
#include <math.h>

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
    printf("Name : Urchintla Muhammed Muzammil Shaik\n");
    printf("USN : 1BF24CS324\n\n");
    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);

    int C[n], P[n];

    printf("Enter the CPU burst times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &C[i]);

    printf("Enter the time periods:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &P[i]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (P[i] > P[j]) {
                int t;
                t = P[i]; P[i] = P[j]; P[j] = t;
                t = C[i]; C[i] = C[j]; C[j] = t;
            }
        }
    }

    int hp = P[0];
    for (int i = 1; i < n; i++)
        hp = lcm(hp, P[i]);

    printf("LCM=%d\n\n", hp);

    printf("Rate Monotone Scheduling:\n");
    printf("PID   Burst   Period\n");
    for (int i = 0; i < n; i++)
        printf("%d     %d       %d\n", i + 1, C[i], P[i]);

    float u = 0;
    for (int i = 0; i < n; i++)
        u += (float)C[i] / P[i];

    float b = n * (pow(2, 1.0/n) - 1);

    printf("\n%f <= %f =>%s\n", u, b, (u <= b) ? "true" : "false");
    printf("Scheduling occurs for %d ms\n\n", hp);

    int r[n];
    for (int i = 0; i < n; i++)
        r[i] = 0;

    int prev = -2;

    for (int t = 0; t < hp; t++) {

        for (int i = 0; i < n; i++)
            if (t % P[i] == 0)
                r[i] = C[i];

        int f = -1;
        for (int i = 0; i < n; i++)
            if (r[i] > 0) {
                f = i;
                break;
            }

        if (f != prev) {
            if (f == -1)
                printf("%dms onwards: CPU is idle\n", t);
            else
                printf("%dms onwards: Process %d running\n", t, f + 1);
            prev = f;
        }

        if (f != -1)
            r[f]--;
    }

    return 0;
}