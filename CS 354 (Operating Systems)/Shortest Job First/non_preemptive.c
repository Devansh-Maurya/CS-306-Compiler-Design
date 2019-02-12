
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Process {
    int pId;
    int burstTime;
    int waitingTime;
    int arrivalTime;
    int turnaroundTime;
    int completionTime;
    bool isLastProcessInGroup;
};

typedef struct Process Process;

void applyNonPreemptiveSJF(Process*, Process*, int);
int arrivalTimeComparator(const void*, const void*);
int burstTimeComparator(const void*, const void*);
int processIdComparator(const void*, const void*);
void printProcessArray(const Process*, int);
void printGanttChart(const Process*, int);

int main() {

    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = malloc(sizeof(Process)*n);
    Process *ganttChart = malloc(sizeof(Process)*n);

    for (int i = 0; i < n; ++i) {
        processes[i].pId = i+1;
        processes[i].isLastProcessInGroup = false;

        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &processes[i].burstTime);

        printf("Enter arrival time for process %d: ", i+1);
        scanf("%d", &processes[i].arrivalTime);
    }

    //Sort according to the arrival time to bring the earliest arriving processes at the top
    qsort((void*) processes, n, sizeof(Process), arrivalTimeComparator);

    //Set a flag to keep a track when the group the group of processes having earliest arrival time finishes
    for (int j = 1; j < n; ++j) {
        if (processes[j-1].arrivalTime != processes[j].arrivalTime)
            processes[j-1].isLastProcessInGroup = true;
    }

    //Get the count where the last process of the group having earliest arrival time is in the array of processes
    int k = 0;
    for (; k < n; ++k) {
        if (processes[k].isLastProcessInGroup)
            break;
    }

    //Sort again if two or more processes have earliest arrival time, this time according to burst times
    //Sorting is done only for the processes having earliest arrival times
    qsort((void*) processes, k+1, sizeof(Process), burstTimeComparator);

    applyNonPreemptiveSJF(processes, ganttChart, n);
    //Sort to print in proper order of process id
    qsort(processes, n, sizeof(Process), processIdComparator);

    printProcessArray(processes, n);
    printGanttChart(ganttChart, n);

    //Calculate average waiting time
    float wt = 0;
    for (int l = 0; l < n; ++l) {
        wt += processes[l].waitingTime;
    }
    wt /= n;
    printf("Average waiting time: %f\n", wt);

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

void applyNonPreemptiveSJF(Process *processes, Process *ganttChart, int n) {

    processes[0].completionTime = processes[0].arrivalTime + processes[0].burstTime;
    processes[0].turnaroundTime = processes[0].burstTime;
    processes[0].waitingTime = 0;

    ganttChart[0] = processes[0];

    //Keeps a count of processes that have arrived till the time a process completes
    int arrivedProcessesCount = 0;

    int j;
    //The loop will stop if the processes are over or all the processes have arrived
    for (j = 1; (j < n) && (arrivedProcessesCount < n-1); j++) {

        for (int i = n-1; i >= 0; i--) {
            if (processes[i].arrivalTime <= processes[j-1].completionTime) {
                arrivedProcessesCount = i;
                break;
            }
        }
        Process *processPtr = processes + j;
        //Sort all the processes that have arrrived according to there burst times
        qsort(processPtr, arrivedProcessesCount, sizeof(Process), burstTimeComparator);

        processes[j].completionTime = processes[j-1].completionTime + processes[j].burstTime;
        processes[j].turnaroundTime = processes[j].completionTime - processes[j].arrivalTime;
        processes[j].waitingTime = processes[j].turnaroundTime - processes[j].burstTime;
        ganttChart[j] = processes[j];
    }

    //Now either all the processes have arrived or all the process have been completed,
    //If processes are remaining, this loop will execute
    for (int k = j; k < n; ++k) {
        processes[k].completionTime = processes[k-1].completionTime + processes[k].burstTime;
        processes[k].turnaroundTime = processes[k].completionTime - processes[k].arrivalTime;
        processes[k].waitingTime = processes[k].turnaroundTime - processes[k].burstTime;
        ganttChart[k] = processes[k];
    }
}

int arrivalTimeComparator(const void *p, const void *q) {

    int a = (*(Process *) p).arrivalTime;
    int b = (*(Process *) q).arrivalTime;

    return (a - b);
}

int burstTimeComparator(const void *p, const void *q) {

    int a = (*(Process *) p).burstTime;
    int b = (*(Process *) q).burstTime;

    return (a - b);
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

void printGanttChart(const Process* ganttChart, int n) {

    printf("\n\nGantt Chart:\n");
    if (ganttChart[0].arrivalTime > 0) {
        printf("0 //// %d  P%d  %d", ganttChart[0].arrivalTime, ganttChart[0].pId,
                ganttChart[0].completionTime);
    } else {
        printf("%d  P%d  %d", ganttChart[0].arrivalTime, ganttChart[0].pId,
                ganttChart[0].completionTime);
    }

    for (int i = 1; i < n; ++i) {
        printf("  P%d  %d", ganttChart[i].pId, ganttChart[i].completionTime);
    }
    printf("\n\n");
}