#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *strrev(char *str){
  char *p1, *p2;

  if (! str || ! *str)
        return str;
  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
  {
        //XOR bitwise swapping
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
  }
  return str;
}

int main(int argc, char *argv[]) {
    int pipefd[2], pipefd2[2];
    pid_t cpid;
    char buf;
    if (argc != 2) {
    fprintf(stderr, "Usage: %s <string>\n", argv[0]);
    exit(EXIT_FAILURE);
    }
    if (pipe(pipefd) == -1 || pipe(pipefd2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (cpid == 0) {    /* Child reads from pipe */
        char str[256];
        int i=0;
        close(pipefd[1]);          /* Close unused write end */
        close(pipefd2[0]);          /* Close unused read end */
        //Build String
        while (read(pipefd[0], &buf, 1) > 0){
            str[i]=buf;
            i++;
        }
        str[i]='\0';
        printf("I'm the child process, my father send me:\n\t'%s'\n",str );
        close(pipefd[0]);

        write(pipefd2[1], strrev(str), strlen(str));
        close(pipefd2[1]);
        
        _exit(EXIT_SUCCESS);
    } else {            /* Parent writes argv[1] to pipe */
        close(pipefd[0]);          /* Close unused read end */
        close(pipefd2[1]);          /* Close unused write end */
        write(pipefd[1], argv[1], strlen(argv[1]));
        close(pipefd[1]);          /* Reader will see EOF */
        wait(NULL);                /* Wait for child */

        printf("I'm the father process, my son (PID:%d) send me:\n",cpid );
         write(STDOUT_FILENO, "\t'", 2);
        while (read(pipefd2[0], &buf, 1) > 0)
            write(STDOUT_FILENO, &buf, 1);
        write(STDOUT_FILENO, "'\n", 2);
        close(pipefd2[0]);

        exit(EXIT_SUCCESS);
    }
}