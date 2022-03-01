#include "minitalk.h"

void function(char sym)
{
	int shift;
	int	bit;
	int res;
	
	shift = 0;
	while(shift < 8)
	{
		bit = (sym >> shift) & 1;
		if(bit == 0)
		{
			printf("0\n");
		}
		else		
			printf("1\n");
		shift++;
	}
}
void print(int signal)
{
	static char	sym;
	static int	bit;
	
	printf("sym at new\n");
	function(sym);

	if (signal == SIGUSR1)
	{
		sym = (sym << 1);
		bit++;
	}
	else if (signal == SIGUSR2)
	{
		sym = (sym << 1) | 1;
		bit++;
	}
	if (bit > 7)
	{
		printf("final\n");
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