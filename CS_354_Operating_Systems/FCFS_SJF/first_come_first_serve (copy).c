#include <stdio.h>

#define MAX_PROCESSES 4

struct Process {
    int pId;
    int burstTime;
    int waitingTime;
    int arrivalTime;
};

typedef struct Process Process;

float calculateWaitingTime(Process*);
float calculateWaitingTimeWithArrivalTime(Process*);

int main() {

    Process processes[MAX_PROCESSES];

    for (int i = 0; i < MAX_PROCESSES; ++i) {
        processes[i].pId = i;
    }

    processes[0].burstTime = 5;
    processes[1].burstTime = 3;
    processes[2].burstTime = 25;
    processes[3].burstTime = 17;

    processes[0].arrivalTime = 0;
    processes[1].arrivalTime = 10;
    processes[2].arrivalTime = 15;
    processes[3].arrivalTime = 20;

    float averageWaitingTime = calculateWaitingTime(processes);

    printf("Process\t\tBurst Time\t\tWaiting Time\t\tArrival Time\n\n");

    for (int j = 0; j < MAX_PROCESSES; ++j) {
        printf("%d\t\t\t%d\t\t\t\t%d\t\t\t\t\t%d\n", processes[j].pId, processes[j].burstTime,
                processes[j].waitingTime, processes[j].arrivalTime);
    }

    printf("\n\nAverage waiting time: %f", averageWaitingTime);

    return 0;
}

//Returns average waiting time
float calculateWaitingTime(Process* processes) {

    int totalTime = 0, wTime = 0;

    for (int i = 0; i < MAX_PROCESSES; ++i) {
        processes[i].waitingTime = totalTime;
        totalTime += processes[i].burstTime;
        wTime += processes[i].waitingTime;
    }

    return ((float)wTime)/MAX_PROCESSES;
}

//Error pr
float calculateWaitingTimeWithArrivalTime(Process* processes) {

    int passedTime = processes[0].arrivalTime + processes[0].burstTime;
    int wTime = 0;

    processes[0].waitingTime = 0;

    for (int i = 1; i < MAX_PROCESSES; ++i) {
        if (processes[i].arrivalTime <= passedTime) {
            processes[i].waitingTime = passedTime - processes[i].arrivalTime;
            passedTime += processes[i].burstTime;
        } else {
            processes[i].waitingTime = processes[i].arrivalTime - passedTime;
            passedTime = processes[i].arrivalTime + processes[i].burstTime;
        }
        wTime += processes[i].waitingTime;
    }

    return ((float)wTime)/MAX_PROCESSES;
}