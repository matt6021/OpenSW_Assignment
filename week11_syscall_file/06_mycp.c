#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc,char *argv[]){

    int i;
    int src_fd;

    if(argc < 3){
        printf("Usage : %s [source file] [destination file1] [destination file2]. . .", argv[0]);
        return 1;
    }

    src_fd = open(argv[1],O_RDONLY);

    if(src_fd == -1){
        perror(argv[1]);
        return 1;
    }

    int dest_cnt = argc - 2;
    int dest_fd[dest_cnt];

    for(i = 0;i < dest_cnt;i++){
        dest_fd[i] = open(argv[i+2],O_WRONLY|O_CREAT|O_TRUNC,0644);

        if(dest_fd[i] == -1){
            perror(argv[i+2]);
        }
    }

    char buf[32];
    int n;

    while(1){
        n = read(src_fd ,buf,sizeof(buf));

        if(n == 0){
            break;
        }
        if(n < 0){
            perror("read");
            break;
        }

        write(1,buf,n);

        for(i = 0;i < dest_cnt;i++){
            if(dest_fd[i] != -1){
                write(dest_fd[i],buf,n);
            }
        }
    }

    close(src_fd);

    for(i = 0;i < dest_cnt;i++){
        if(dest_fd[i] != -1){
        close(dest_fd[i]);
        }
    }

    return 0;
}