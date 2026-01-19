#include <stdio.h>

int main() {
    int n;
    int process[20], burstTime[20], priority[20];
    int waitingTime[20], turnAroundTime[20];
    int totalWT = 0, totalTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter burst time of Process P%d: ", i + 1);
        scanf("%d", &burstTime[i]);
        printf("Enter priority of Process P%d (lower number = higher priority): ", i + 1);
        scanf("%d", &priority[i]);
    }

    // Sorting by priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                int temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    // Waiting time
    waitingTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }

    // Turnaround time
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
        totalWT += waitingTime[i];
        totalTAT += turnAroundTime[i];
    }

    // Output
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                process[i], priority[i], burstTime[i],
                waitingTime[i], turnAroundTime[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
            (float)totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n",
            (float)totalTAT / n);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}
