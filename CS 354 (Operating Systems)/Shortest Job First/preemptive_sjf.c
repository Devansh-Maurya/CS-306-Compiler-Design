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
    int preemptedTime;
    int executedTime;
} ganttChart[100];

typedef struct Process Process;
int ganttChartIndex = 0;

void applyPreemptiveSJF(Process*, int);
int processIdComparator(const void*, const void*);
void printProcessArray(const Process*, int);
void printGanttChart(const Process*, int);

int main() {

    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[10];
    Process *fake;
    fake = ganttChart;
    if (fake)
        printf("aaa");

    for (int i = 0; i < n; ++i) {
        processes[i].pId = i+1;

        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &processes[i].burstTime);

        printf("Enter arrival time for process %d: ", i+1);
        scanf("%d", &processes[i].arrivalTime);

        processes[i].remainingBurstTime = processes[i].burstTime;
        processes[i].executedTime = 0;
    }

    applyPreemptiveSJF(processes, n);
    qsort(processes, n, sizeof(Process), processIdComparator);
    printProcessArray(processes, n);

    printf("\n\nGantt Chart:\n\n");
    printGanttChart(ganttChart, ganttChartIndex);

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

    return 0;
}

void applyPreemptiveSJF(Process *processes, int n) {

    int completedProcesses = 0;
    int time = 0, minimumRemainingTime = INT_MAX;
    bool isProcessInExecution = false;  //Used to check if CPU is idle
    bool processChanged;                //Used for proper output of Gantt chart
    Process *currentProcess = NULL;     //Current process that is being executed

    //Loop until all processes are completed
    while (completedProcesses < n) {

        processChanged = false;

        //Among all the processes that have arrived till 'time',
        //find processes with minimum remaining time
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrivalTime <= time &&
                processes[i].remainingBurstTime < minimumRemainingTime &&
                processes[i].remainingBurstTime > 0) {

                minimumRemainingTime = processes[i].remainingBurstTime;
                currentProcess = processes + i;
                isProcessInExecution = true;
                processChanged = true;      //A new process has started execution
            }
        }

        if (!isProcessInExecution) {
            //No process is being executed, so CPU is idle
            time++;
            continue;
        }

        if (processChanged) {
            //Process has changed. Print the new process in Gantt chart
            ganttChart[ganttChartIndex] = *currentProcess;
            //Calculate preempted time and executed time for previous process
            if (ganttChartIndex > 0)
                ganttChart[ganttChartIndex - 1].preemptedTime = time;

            if (ganttChartIndex > 1) {
                ganttChart[ganttChartIndex - 1].executedTime +=
                        ganttChart[ganttChartIndex - 1].preemptedTime - ganttChart[ganttChartIndex - 2].preemptedTime;
            }
            ganttChartIndex++;
        }

        currentProcess->remainingBurstTime--;

        minimumRemainingTime = currentProcess->remainingBurstTime;

        //Process has finished, so set min. time to INT_MAX
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
        ++time;
    }

    ganttChart[ganttChartIndex-1].preemptedTime = time;
    ganttChart[ganttChartIndex-1].executedTime = ganttChart[ganttChartIndex-1].preemptedTime - ganttChart[ganttChartIndex-2].preemptedTime;

    ganttChart[0].executedTime = ganttChart[1].preemptedTime - ganttChart[0].arrivalTime;

    //It has been assumed that only CPU is idle initially, if.
    //Ig CPU is idle, add an empty process at the beginning
    if (ganttChart[0].arrivalTime != 0) {
        for (int i = ganttChartIndex; i > 0 ; i--) {
            ganttChart[i] = ganttChart[i-1];
        }
        ganttChartIndex++;
        Process emptyProcess;
        emptyProcess.pId = -1;
        emptyProcess.preemptedTime = ganttChart[1].arrivalTime;
        emptyProcess.executedTime = ganttChart[1].arrivalTime;
        emptyProcess.arrivalTime = 0;
        ganttChart[0] = emptyProcess;
    }
}

int processIdComparator(const void *p, const void *q) {

    int a = (*(Process *) p).pId;
    int b = (*(Process *) q).pId;

    return (a - b);
}

void printProcessArray(const Process* processes, int n) {

    printf("\nProcess\tArrival time\t\tBurst time\t\tCompletion time\t\tTurnaround time\t\tWaiting time\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",
               processes[i].pId, processes[i].arrivalTime, processes[i].burstTime,
               processes[i].completionTime, processes[i].turnaroundTime, processes[i].waitingTime);
    }
}

void printGanttChart(const Process* p, int n)
{
    int i, j;

    // print top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].executedTime; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    // printing process id in the middle
    //-1 is done for proper alignment
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].executedTime-1; j++) printf(" ");
        if (p[i].pId > 0)
            printf("P%d", p[i].pId);
        else
            printf("  ");
        for(j=0; j<p[i].executedTime-1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].executedTime; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    // printing the time line
    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].executedTime; j++) printf("  ");
        if(p[i].preemptedTime > 9) printf("\b"); // backspace : remove 1 space
        printf("%d", p[i].preemptedTime);
    }
    printf("\n");

}