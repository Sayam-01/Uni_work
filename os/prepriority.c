#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    int arrivalTime[20], burstTime[20], remainingTime[20];
    int priority[20];
    int completionTime[20], waitingTime[20], turnAroundTime[20];
    int totalWT = 0, totalTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time of P%d: ", i + 1);
        scanf("%d", &arrivalTime[i]);

        printf("Enter burst time of P%d: ", i + 1);
        scanf("%d", &burstTime[i]);

        printf("Enter priority of P%d (lower number = higher priority): ", i + 1);
        scanf("%d", &priority[i]);

        remainingTime[i] = burstTime[i];
    }

    int time = 0, completed = 0;
    int minPriority, selected;

    while (completed < n) {
        minPriority = INT_MAX;
        selected = -1;

        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= time && remainingTime[i] > 0) {
                if (priority[i] < minPriority) {
                    minPriority = priority[i];
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            time++;
            continue;
        }

        remainingTime[selected]--;
        time++;

        if (remainingTime[selected] == 0) {
            completionTime[selected] = time;
            completed++;
        }
    }

    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnAroundTime[i] - burstTime[i];
        totalWT += waitingTime[i];
        totalTAT += turnAroundTime[i];
    }

    printf("\nProcess\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                i + 1, arrivalTime[i], burstTime[i],
                priority[i], waitingTime[i], turnAroundTime[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
            (float)totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n",
            (float)totalTAT / n);

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}
