#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "operators.c"


/*
	Emulates 'cmd1 | cmd2'
*/
void 
pipecommands(char *cmd1, char *cmd2){
	int pipedesc[2];
	pipe(pipedesc);

	if (fork()==0) //First child writes to pipe
	{
		close(STDOUT_FILENO); //Close stdout (1)
		dup(pipedesc[1]); //Duplicate pipe write ends to 1
		close(pipedesc[0]); //Close unused read end
		close(pipedesc[1]);
		//Run command 1
		execl("/bin/bash","bash", "-c", cmd1, (char *)0);
		
		perror("execl failed");
		exit(1);
	}
	if (fork()==0) //Second child reads from pipe
	{
		close(STDIN_FILENO); //Close stdin (0)
		dup(pipedesc[0]); //Duplicate pipe reads ends to 0
		close(pipedesc[1]); //Close unused write end
		close(pipedesc[0]);
		//Run command 2
		execl("/bin/bash","bash", "-c", cmd2, (char *)0);
		
		perror("execl2 failed");
		exit(1);
	}

	close(pipedesc[0]); //Close read ends
	close(pipedesc[1]); //Close write ends
	wait(0); 	//Wait for first child
	wait(0);	//Wait for second child
}


/*
	Emulates 'cmd1 < in_file'
*/
void
redirect_in(char *cmd1, char *in_file){
	int fd;

	if (fork()==0)
	{
		close(0); //Close stdin
		fd = open (in_file, O_RDONLY);
		if (fd<0){
			perror("cannot open file");
			exit(1);
		}

		dup(fd); //Duplicate stdin in fd
		//Run cmd1
		execl("/bin/bash","bash", "-c", cmd1, (char *)0);
	}
	wait();
	write(STDOUT_FILENO,"\n",1);
}

int main(int argc, char const *argv[])
{
	if (argc!=4){
		printf("usage: %s 'cmd1' 'op' 'cmd2'\n",argv[0] );
		return -1;
	}
	switch (keyfromstring(argv[2])) {
		case O1: /* cmd1 | cmd2 */ pipecommands(argv[1],argv[3]); break;
		case O2: /* cmd1 < in_file */ redirect_in(argv[1],argv[3]); break;
		case O3: /* ... */ break;
		case O4: /* ... */ break;
		case O5: /* ... */ break;
		case O6: /* ... */ break;
		case O7: /* ... */ break;

		case BADKEY: printf("Unrecognized operator\n");
	}

	return 0;
}