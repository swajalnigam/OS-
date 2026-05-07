#include <stdio.h>


struct Process {
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int type;
    int completed;
};

int main() {
    printf("Name : Urchintla Muhammed Muzammil Shaik\n");
    printf("USN : 1BF24CS324\n\n");
    int n, i;
    int completed_count = 0;
    int current_time = 0;
    float total_wt = 0, total_tat = 0;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);


    struct Process p[n];

    // Input process details
    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("\nProcess %d\n", p[i].id);
        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Enter Burst Time: ");
        scanf("%d", &p[i].bt);
        printf("Enter Process Type (1 for System, 2 for User): ");
        scanf("%d", &p[i].type);
        p[i].completed = 0;
    }


    while (completed_count < n) {
        int selected_process = -1;
        int highest_priority_type = 3; // 1 is highest, 2 is lower
        int earliest_arrival = 999999;


        for (i = 0; i < n; i++) {
            if (p[i].completed == 0 && p[i].at <= current_time) {

                if (p[i].type < highest_priority_type) {
                    highest_priority_type = p[i].type;
                    earliest_arrival = p[i].at;
                    selected_process = i;
                }

                else if (p[i].type == highest_priority_type && p[i].at < earliest_arrival) {
                    earliest_arrival = p[i].at;
                    selected_process = i;
                }
            }
        }


        if (selected_process != -1) {
            current_time += p[selected_process].bt;
            p[selected_process].ct = current_time;
            p[selected_process].tat = p[selected_process].ct - p[selected_process].at;
            p[selected_process].wt = p[selected_process].tat - p[selected_process].bt;
            p[selected_process].completed = 1;

            total_tat += p[selected_process].tat;
            total_wt += p[selected_process].wt;

            completed_count++;
        } else {
            current_time++;
        }
    }



    printf("\n--- Scheduling Results ---\n");
    printf("PID\tType\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id,
               (p[i].type == 1 ? "SYS" : "USR"),
               p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time: %.2f\n", total_wt / n);

    return 0;
}