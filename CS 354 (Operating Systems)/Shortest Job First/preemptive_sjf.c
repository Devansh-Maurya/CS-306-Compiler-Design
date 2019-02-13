//
// Created by devansh on 13/2/19.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

struct Process {
    int pId;
    int burstTime;
    int waitingTime;
    int arrivalTime;
    int turnaroundTime;
    int completionTime;
    int remainingBurstTime;
};

typedef struct Process Process;

void applyPreemptiveSJF(Process*, int);
int processIdComparator(const void*, const void*);
void printProcessArray(const Process*, int);

int main() {

    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = malloc(sizeof(Process)*n);
    Process *ganttChart = malloc(sizeof(Process)*n);

    for (int i = 0; i < n; ++i) {
        processes[i].pId = i+1;

        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &processes[i].burstTime);

        printf("Enter arrival time for process %d: ", i+1);
        scanf("%d", &processes[i].arrivalTime);

        processes[i].remainingBurstTime = processes[i].burstTime;
    }

    applyPreemptiveSJF(processes, n);
    qsort(processes, n, sizeof(Process), processIdComparator);
    printProcessArray(processes, n);

    //Calculate average waiting time
    float wt = 0;
    for (int l = 0; l < n; ++l) {
        wt += processes[l].waitingTime;
    }
    wt /= n;
    printf("\nAverage waiting time: %f\n", wt);

    //Calculate average turnaround time
    float tat = 0;
    for (int m = 0; m < n; ++m) {
        tat += processes[m].turnaroundTime;
    }
    tat /= n;

    printf("Average turnaround time: %f\n", tat);

    free(processes);
    free(ganttChart);

    return 0;
}

void applyPreemptiveSJF(Process *processes, int n) {

    int completedProcesses = 0;
    int time = 0, minimumRemainingTime = INT_MAX;
    bool isProcessInExecution = false, processChanged;
    Process *currentProcess = NULL;

    printf("\n\nGantt Chart:\n\n");

    while (completedProcesses < n) {

        processChanged = false;

        for (int i = 0; i < n; ++i) {
            if (processes[i].arrivalTime <= time &&
                processes[i].remainingBurstTime < minimumRemainingTime &&
                processes[i].remainingBurstTime > 0) {

                minimumRemainingTime = processes[i].remainingBurstTime;
                currentProcess = processes + i;
                isProcessInExecution = true;
                processChanged = true;
            }
        }

        if (!isProcessInExecution) {
            printf("%d", time);
            printf(" //// ");
            time++;
            continue;
        }

        if (processChanged) {
            printf("%d", time);
            printf(" P%d ", currentProcess->pId);
        }

        currentProcess->remainingBurstTime--;
        minimumRemainingTime = currentProcess->remainingBurstTime;
        if (minimumRemainingTime == 0)
            minimumRemainingTime = INT_MAX;

        if (currentProcess->remainingBurstTime == 0) {

            isProcessInExecution = false;
            completedProcesses++;
            currentProcess->completionTime = time + 1;

            currentProcess->turnaroundTime =
                    currentProcess->completionTime - currentProcess->arrivalTime;

            currentProcess->waitingTime =
                    currentProcess->turnaroundTime - currentProcess->burstTime;

            if (currentProcess->waitingTime < 0)
                currentProcess->waitingTime = 0;
        }
        time++;
    }
    printf("%d\n\n", time);
}

int processIdComparator(const void *p, const void *q) {

    int a = (*(Process *) p).pId;
    int b = (*(Process *) q).pId;

    return (a - b);
}

void printProcessArray(const Process* processes, int n) {

    printf("\nProcess\tArrival time\t\tBurst time\t\tCompletion time\t\tTurnaround time\t\tWaiting time\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n",
               processes[i].pId, processes[i].arrivalTime, processes[i].burstTime,
               processes[i].completionTime, processes[i].turnaroundTime, processes[i].waitingTime);
    }
}