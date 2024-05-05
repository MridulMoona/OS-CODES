#include <stdio.h>
#include <stdlib.h>


typedef struct Process {
    int pid;            
    int arrival_time;   
    int burst_time;     
    int remaining_time; 
    struct Process *next; 
} Process;


Process* createProcess(int pid, int arrival_time, int burst_time) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    if (newProcess == NULL) {
        perror("Error creating new process");
        exit(EXIT_FAILURE);
    }
    newProcess->pid = pid;
    newProcess->arrival_time = arrival_time;
    newProcess->burst_time = burst_time;
    newProcess->remaining_time = burst_time;
    newProcess->next = NULL;
    return newProcess;
}


void enqueue(Process** head, Process** tail, Process* newProcess) {
    if (*head == NULL) {
        *head = newProcess;
    } else {
        (*tail)->next = newProcess;
    }
    *tail = newProcess;
}

Process* dequeue(Process** head) {
    if (*head == NULL) {
        return NULL;
    }
    Process* temp = *head;
    *head = (*head)->next;
    return temp;
}


void executeRoundRobin(Process* head, int time_quantum) {
    int time = 0;
    Process* current = head;
    printf("Process execution order:\n");
    while (current != NULL) {
        if (current->remaining_time > 0) {
            printf("Time %d: Running process %d\n", time, current->pid);
            if (current->remaining_time > time_quantum) {
    
                time += time_quantum;
                current->remaining_time -= time_quantum;
                printf("Time %d: Process %d interrupted\n", time, current->pid);
              
                enqueue(&head, &current, dequeue(&head));
            } else {
           
                time += current->remaining_time;
                current->remaining_time = 0;
                printf("Time %d: Process %d completed\n", time, current->pid);
               
                dequeue(&head);
            }
        }
        current = current->next;
    }
}

int main() {
 
    Process* processes = NULL;
    enqueue(&processes, &processes, createProcess(1, 0, 5));
    enqueue(&processes, &processes, createProcess(2, 1, 4));
    enqueue(&processes, &processes, createProcess(3, 2, 2));
    enqueue(&processes, &processes, createProcess(4, 3, 1));


    int time_quantum = 2;

    executeRoundRobin(processes, time_quantum);

    return 0;
}