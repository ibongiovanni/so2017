#include <stdio.h>
#include <unistd.h>

int my_system (const char *cmd){
	if( fork() == 0){
		//Child
		printf("executing command: %s\n",cmd );
		execl("/bin/bash","bash", "-c", cmd, (char *)0);
		printf("Failed Execution\n" );
		exit(-1);
	}
	else{
		//father
		int exit_status;
		int child_pid;
		child_pid=wait(&exit_status);
		printf("\n child (%d) finishied with exit statatus: %d\n",child_pid,exit_status);
	}
}

int main(int argc, char const *argv[])
{
	my_system(argv[1]);
	return 0;
}