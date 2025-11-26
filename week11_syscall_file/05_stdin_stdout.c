#include <unistd.h>

int main (void){

    char buf[128];
    int n;
    
    while(1){

        n = read(0,buf,128);

        if(n == 0){
            break;
        }

        write(1,buf,n);
    }

    return 0;
}