#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 20

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

int queuePtr = 0;
Process *temp;

void roundRobin(Process*, int);
void enqueue(Process[20], Process*);
Process* dequeue(Process[20]);
int processIdComparator(const void*, const void*);
int arrivalTimeComparator(const void*, const void*);
void printGanttChart(const Process*, int);
void printProcessArray(const Process* processes, int n);

int main() {

    int n;


    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = malloc(sizeof(Process)*n);
    temp = malloc(sizeof(Process)*n);

    for (int i = 0; i < n; ++i) {
        processes[i].pId = i+1;

        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &processes[i].burstTime);

        printf("Enter arrival time for process %d: ", i+1);
        scanf("%d", &processes[i].arrivalTime);

        processes[i].remainingBurstTime = processes[i].burstTime;

        temp[i] = processes[i];
    }

    //Sort according to the arrival time to bring the earliest arriving processes at the top
    qsort((void*) processes, n, sizeof(Process), arrivalTimeComparator);

    roundRobin(processes, n);

    qsort((void*) processes, n, sizeof(Process), processIdComparator);

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

    return 0;
}

void roundRobin(Process *processes, int n) {

    Process queue[MAX_QUEUE_SIZE];
    int processTablePtr = 0;
    Process* currentProcess = &processes[0];
    int time = currentProcess->arrivalTime;
    int timeQuantum = 3;

    enqueue(queue, &processes[processTablePtr++]);

    while (true) {

        currentProcess = dequeue(queue);

        time += timeQuantum;

        for (int i = processTablePtr; i < n; ++i) {
            if (processes[processTablePtr].arrivalTime <= time) {
                enqueue(queue, &processes[processTablePtr++]);
            } else
                break;
        }

        if (currentProcess->burstTime < timeQuantum)
            currentProcess->remainingBurstTime = 0;
        else {
            currentProcess->remainingBurstTime = currentProcess->burstTime - timeQuantum;
            enqueue(queue, currentProcess);
        }

        if (currentProcess->remainingBurstTime == 0) {
            dequeue(queue);
            currentProcess->completionTime = time - timeQuantum;
            currentProcess->turnaroundTime = currentProcess->completionTime -
                    currentProcess->arrivalTime;
            currentProcess->waitingTime = currentProcess->turnaroundTime -
                                                       currentProcess->burstTime;

        }
    }
}

void printProcessArray(const Process* processes, int n) {

    printf("\nProcess\tArrival time\t\tBurst time\t\tCompletion time\t\tTurnaround time\t\tWaiting time\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n",
               processes[i].pId, processes[i].arrivalTime, processes[i].burstTime,
               processes[i].completionTime, processes[i].turnaroundTime, processes[i].waitingTime);
    }
}

void enqueue(Process queue[MAX_QUEUE_SIZE], Process *process) {

    int p = queuePtr;

    if (queuePtr == MAX_QUEUE_SIZE-1) {
        printf("\nQueue is full\n");
        exit(0);
    }

    queue[queuePtr] = *process;
    queuePtr = (queuePtr + 1)%MAX_QUEUE_SIZE;
}

Process* dequeue(Process queue[MAX_QUEUE_SIZE]) {

    int p = queuePtr;

    if (queuePtr == 0) {
        printf("\nQueue is empty\n");
        exit(0);
    }

    int currentPos = queuePtr;
    queuePtr = (queuePtr - 1)%MAX_QUEUE_SIZE;

    return &temp[queue[queuePtr].pId-1];
}

int processIdComparator(const void *p, const void *q) {

    int a = (*(Process *) p).pId;
    int b = (*(Process *) q).pId;

    return (a - b);
}

int arrivalTimeComparator(const void *p, const void *q) {

    int a = (*(Process *) p).arrivalTime;
    int b = (*(Process *) q).arrivalTime;

    return (a - b);
}

void printGanttChart(const Process* p, int n) {

    int i, j;

    Process *fake;
    fake = p;

    // print top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].executedTime; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    // printing process id in the middle
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].executedTime - 1; j++) printf(" ");
        if (p[i].pId > 0)
            printf("P%d", p[i].pId);
        else
            printf("  ");
        for(j=0; j<p[i].executedTime - 1; j++) printf(" ");
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