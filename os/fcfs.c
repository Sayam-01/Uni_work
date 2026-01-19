#include <stdio.h>

int main() {
    int n;
    int burstTime[20], waitingTime[20], turnAroundTime[20];
    int totalWT = 0, totalTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    // FCFS waiting time calculation
    waitingTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }

    // Turnaround time calculation
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
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
