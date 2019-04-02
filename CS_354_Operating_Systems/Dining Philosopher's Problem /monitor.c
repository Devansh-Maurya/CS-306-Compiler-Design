#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>

#define N 7
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N

sem_t mutex;
sem_t next;
int next_count = 0;

typedef struct {
    sem_t sem;
    int count;
} condition;

condition x[N];

int state[N];
int turn[N];

void wait(int i) {
    x[i].count++;
    if(next_count > 0) {
        sem_post(&next);
    }
    else {
        sem_post(&mutex);
    }
    sem_wait(&x[i].sem);
    x[i].count--;
}

void signal(int i) {
    if(x[i].count > 0) {
        next_count++;
        sem_post(&x[i].sem);
        sem_wait(&next);
        next_count--;
    }
}

void test(int i) {
    if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING && turn[i] == i && turn[LEFT] == i) {
        state[i] = EATING;

        signal(i);
    }
}

void take_chopsticks(int i) {
    sem_wait(&mutex);
    state[i] = HUNGRY;
    test(i);
    while(state[i] == HUNGRY) {
        wait(i);
    }
    if(next_count > 0) {
        sem_post(&next);
    }
    else {
        sem_post(&mutex);
    }
}

void put_chopsticks(int i) {
    sem_wait(&mutex);
    state[i] = THINKING;
    turn[i] = RIGHT;
    turn[LEFT] = LEFT;

    test(LEFT);
    test(RIGHT);

    if(next_count > 0) {
        sem_post(&next);
    }
    else {
        sem_post(&mutex);
    }
}

void initialization() {
    int i;
    sem_init(&mutex,0,1);
    sem_init(&next,0,0);
    for(i = 0;i < N;i++) {
        state[i] = THINKING;
        sem_init(&x[i].sem,0,0);
        x[i].count = 0;
        turn[i] = i;
    }
    turn[1] = 2;
    turn[3] = 4;
    turn[6] = 0;
}

void *philosopher(void *i)
{
    while(1) {
        int self = *(int *) i;
        int j,k;
        j = rand();
        j = j % 11;
        printf("\nPhilosopher %d is thinking for %d secs",self,j);
        sleep(j);
        take_chopsticks(self);
        k = rand();
        k = k % 4;
        printf("\nPhilosopher %d is eating for %d secs",self,k);
        sleep(k);
        put_chopsticks(self);
    }

}

int main() {
    int i, pos[N];
    pthread_t thread[N];
    pthread_attr_t attr;

    initialization();

    pthread_attr_init(&attr);

    for (i = 0; i < N; i++) {
        pos[i] = i;
        pthread_create(&thread[i], NULL,philosopher, &pos[i]);
    }
    for (i = 0; i < N; i++) {
        pthread_join(thread[i], NULL);
    }

    return 0;
}
