#include "minitalk.h"

void print(int flag)
{
	if (flag = 1)
		write(1, "Signal received\n", 17);
}
int main(int argc, char **argv)
{
	int pid;
	int flag;

	flag = 1;
	pid = getpid();
	printf("PID is: %d\n", pid);
	signal(SIGUSR1, print);
	while(1)
		pause();
	return(0);
}