#include "minitalk.h"

void function(char sym)
{
	int shift;
	int	bit;
	
	shift = 0;
	while(shift < 8)
	{
		bit = (sym >> shift) & 1;
		if(bit == 0)
		{
			printf("0");
		}
		else		
			printf("1");
		shift++;
	}
	printf("\n");
}

void print(int signal)
{
	static char	sym;
	static int	bit;
	printf("Sym is:\n");
	function(sym);
	sym |= (signal == SIGUSR2);
	sym <<= 1;
	if (++bit == 8)
	{
		printf("finish\n");
		function(sym);
		write(1, &sym, 1);
		sym = 0;
		bit = 0;
	}
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
