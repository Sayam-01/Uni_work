#include <stdio.h>

int main() {
    int n, timeQuantum;
    int burstTime[20], remainingTime[20];
    int waitingTime[20], turnAroundTime[20];
    int completionTime[20];
    int totalWT = 0, totalTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    for (int i = 0; i < n; i++) {
        printf("Enter burst time of Process P%d: ", i + 1);
        scanf("%d", &burstTime[i]);
        remainingTime[i] = burstTime[i];
    }

    int time = 0;
    int done;

    while (1) {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                done = 0;
                if (remainingTime[i] > timeQuantum) {
                    time += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                } else {
                    time += remainingTime[i];
                    completionTime[i] = time;
                    remainingTime[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }

    // Turnaround and waiting time
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = completionTime[i]; // arrival time = 0
        waitingTime[i] = turnAroundTime[i] - burstTime[i];
        totalWT += waitingTime[i];
        totalTAT += turnAroundTime[i];
    }

    // Output
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n",
                i + 1, burstTime[i], waitingTime[i], turnAroundTime[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
            (float)totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n",
            (float)totalTAT / n);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}
