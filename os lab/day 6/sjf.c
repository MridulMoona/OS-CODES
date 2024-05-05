#include<stdio.h>


struct process {
    int pid;  
    int bt;   
    int at;   
};


void sjf_non_preemptive(struct process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    
 
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(proc[j].at > proc[j+1].at) {
                struct process temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(i == 0)
            wt[i] = 0;
        else
            wt[i] = wt[i-1] + proc[i-1].bt;
        
        tat[i] = wt[i] + proc[i].bt;
        
        total_wt += wt[i];
        total_tat += tat[i];
    }
    

    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, proc[i].at, wt[i], tat[i]);
    }
    

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct process proc[n];
    printf("Enter process details (Process ID, Burst Time, Arrival Time):\n");
    for(int i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d %d", &proc[i].pid, &proc[i].bt, &proc[i].at);
    }
  
    sjf_non_preemptive(proc, n);
    
    return 0;
}
