#include <stdio.h>

int main(int argc, char const *argv[])
{
	char str[10];
	str[0]='a';
	str[2]='\0';
	printf("%s\n",str );
	return 0;
}