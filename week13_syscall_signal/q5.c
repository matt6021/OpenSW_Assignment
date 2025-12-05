#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

struct two_double {
    double a;
    double b;
};

struct two_double data;

void sigint_handler(int sig)
{
    printf("Ouch! I got SIGINT\n");
}

void sigquit_handler(int sig)
{
    printf("Good Bye\n");
    exit(0);
}

void sigalrm_handler(int sig)
{
    printf("%f, %f\n", data.a, data.b);
    alarm(1);              
}

int main(void)
{
    struct sigaction sa_int;
    struct sigaction sa_quit;
    struct sigaction sa_alrm;
    struct two_double zeros = {0.0, 0.0};
    struct two_double ones  = {1.0, 1.0};
    sigset_t blockset, oldset;

   
    sa_int.sa_handler = sigint_handler;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;
    sigaction(SIGINT, &sa_int, NULL);

   
    sa_quit.sa_handler = sigquit_handler;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = 0;
    sigaction(SIGQUIT, &sa_quit, NULL);

   
    sa_alrm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_alrm.sa_mask);
    sa_alrm.sa_flags = 0;
    sigaction(SIGALRM, &sa_alrm, NULL);

 
    sigemptyset(&blockset);
    sigaddset(&blockset, SIGALRM);

    alarm(1);

    while (1) {
      
        sigprocmask(SIG_BLOCK, &blockset, &oldset);
        data = ones;
      
        sigprocmask(SIG_SETMASK, &oldset, NULL);

      
        sigprocmask(SIG_BLOCK, &blockset, &oldset);
        data = zeros;
      
        sigprocmask(SIG_SETMASK, &oldset, NULL);
    }

    return 0;
}
