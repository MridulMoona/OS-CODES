#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid_a, pid_b, pid_c;

    printf("Parent process (PID=%d)\n", getpid());

  
    pid_a = fork();

    if (pid_a == 0) {
      
        printf("First child process (PID=%d), Parent PID=%d\n", getpid(), getppid());
    } else if (pid_a > 0) {
       
        pid_b = fork();

        if (pid_b == 0) {
           
            printf("Second child process (PID=%d), Parent PID=%d\n", getpid(), getppid());
        } else if (pid_b > 0) {
          
            pid_c = fork();

            if (pid_c == 0) {
              
                printf("Third child process (PID=%d), Parent PID=%d\n", getpid(), getppid());
            } else if (pid_c > 0) {
              
                printf("Parent process again (PID=%d), Parent PID=%d\n", getpid(), getppid());
            } else {
             
                perror("fork");
                return 1;
            }
        } else {
           
            perror("fork");
            return 1;
        }
    } else {
       
        perror("fork");
        return 1;
    }

    return 0;
}