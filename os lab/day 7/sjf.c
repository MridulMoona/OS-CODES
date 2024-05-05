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


void insertProcess(Process** head, Process* newProcess) {
    if (*head == NULL || (*head)->arrival_time > newProcess->arrival_time) {
        newProcess->next = *head;
        *head = newProcess;
    } else {
        Process* current = *head;
        while (current->next != NULL && current->next->arrival_time <= newProcess->arrival_time) {
            current = current->next;
        }
        newProcess->next = current->next;
        current->next = newProcess;
    }
}

void executeSJF(Process* head) {
    int time = 0;
    Process* current = head;
    printf("Process execution order:\n");
    while (current != NULL) {
        if (current->remaining_time > 0) {
            printf("Time %d: Running process %d\n", time, current->pid);
            current->remaining_time--;
            time++;
     
            if (current->remaining_time == 0) {
                printf("Time %d: Process %d completed\n", time, current->pid);
            }
        }
        current = current->next;
    }
}

int main() {

    Process* processes = NULL;
    insertProcess(&processes, createProcess(1, 0, 3));
    insertProcess(&processes, createProcess(2, 1, 5));
    insertProcess(&processes, createProcess(3, 2, 2));

    executeSJF(processes);

    return 0;
}