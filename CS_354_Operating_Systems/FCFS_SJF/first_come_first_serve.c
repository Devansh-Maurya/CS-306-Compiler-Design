#include <stdio.h>

#define MAX_PROCESSES 4

struct Process {
    int pId;
    int burstTime;
    int waitingTime;
    int arrivalTime;
};

typedef struct Process Process;

float calculateWaitingTime(Process*, int);

int main() {

    Process processes[MAX_PROCESSES];
    
    int n;
    
    printf("Enter total processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        processes[i].pId = i;
    }
    
    for(int i = 0; i < n; ++i) {
    	printf("Enter burst time for process %d: ", i);
    	scanf("%d", &processes[i].burstTime);
    }

    float averageWaitingTime = calculateWaitingTime(processes, n);

    printf("Process\t\tBurst Time\t\tWaiting Time\n\n");

    for (int j = 0; j < n; ++j) {
        printf("%d\t\t\t%d\t\t\t\t%d\n", processes[j].pId, processes[j].burstTime,
                processes[j].waitingTime);
    }

    printf("\n\nAverage waiting time: %f\n", averageWaitingTime);

    return 0;
}

//Returns average waiting time
float calculateWaitingTime(Process* processes, int n) {

    int totalTime = 0, wTime = 0;

    for (int i = 0; i < n; ++i) {
        processes[i].waitingTime = totalTime;
        totalTime += processes[i].burstTime;
        wTime += processes[i].waitingTime;
    }

    return ((float)wTime)/n;
}
