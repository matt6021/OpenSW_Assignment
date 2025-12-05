#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void sigint_handler(int signum){

    printf("[SIGINT handler] ----------\n");

    pid_t pid = fork();
    if(pid == 0){
        char *argv[] = {"ls",NULL};
        execve("/usr/bin/ls",argv,NULL);
        _exit(1);
    }else{
        wait(NULL);
    }

}


void sigquit_handler(int signum){

    printf("[SIGQUIT handler] ---------\n");

    pid_t pid = fork();
    if(pid == 0){
        char *argv[] = {"date",NULL};
        execve("/usr/bin/date",argv,NULL);
        _exit(1);
    }else{
        wait(NULL);
    }

}

void sigalrm_handler(int signum){
    printf("[SIGALRM handler] ----------\n");

    pid_t pid = fork();

    if(pid == 0){
        char *argv[] = {"whoami",NULL};
        execve("/usr/bin/whoami",argv,NULL);
        _exit(1);
    }else{
        wait(NULL);
    }

    alarm(3);

}


int main (void){

    signal(SIGINT,sigint_handler);
    signal(SIGQUIT,sigquit_handler);
    signal(SIGALRM,sigalrm_handler);

    alarm(3);

    while(1){
        sleep(1);
    }

    return 0;
}
