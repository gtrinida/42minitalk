#include "minitalk.h"

void print(int signal)
{
	static int bit;
	static char sym;
	
	if(signal == SIGUSR1)
		printf("0\n");
	if(signal == SIGUSR2)
		printf("1\n");
}

int main(int argc, char **argv)
{
	int pid;

	if (argc != 1)
	{
		write(1, "Incorrect server launch\n", 25);
		return (0);
	}
	pid = getpid();
	signal(SIGUSR1, &print);
	signal(SIGUSR2, &print);
	printf("Server PID: %d\n", pid);
	while(1)
		pause();
	
}