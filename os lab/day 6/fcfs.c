#include <stdio.h>
#include <stdlib.h>

struct node{
    int id;
    int at;
    int bt;
    struct node* next;
}node;

struct node* createNode(int id, int at,int bt){
    struct node* new =(struct node*)malloc(sizeof(node));
    if(new == NULL){
        printf("memory allocation failed");
        return 0;
    }
    new->id= id;
    new->at =at;
    new->bt =bt;
    new->next =NULL;
    return new; 
}

void insertProcess(struct node** head,struct node* new) {
    if (*head == NULL) {
        *head = new;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}

void FCFS(struct node* head) {
    if (head == NULL) {
        printf("No processes to execute\n");
        return;
    }

    printf("Process Execution Order:\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\n");
    
    struct node* current = head;
    int Time = 0;
    while (current != NULL) {
        if (current->at > Time){
            Time = current->at;
        }        
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", current->id, current->at, current->bt, Time + current->bt,Time + current->bt - current->at);
        Time += current->bt;
        current = current->next;
    }
}

int main(){
    struct node* head = NULL;

    insertProcess(&head, createNode(1, 0, 5));
    insertProcess(&head, createNode(2, 2, 3));
    insertProcess(&head, createNode(3, 4, 1));
    insertProcess(&head, createNode(4, 6, 4));

    FCFS(head);

}