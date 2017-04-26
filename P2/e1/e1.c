#include <stdio.h>
#include <sys/file.h>

void main(int argc, char const *argv[])
{
	int i;
	FILE * f = fopen("number.txt","r+");
	int fd = fileno(f);
	for (int i = 0; i < 1000; ++i)
	{
		int n;
		flock(fd,LOCK_EX);
		fscanf(f,"%d", &n);
		rewind(f);

		fprintf(f, "%d\n",++n);
		rewind(f);
		flock(fd,LOCK_UN);
	}
	fclose(f);
}