#include "minitalk.h"

void ft_string_delivery(int pid, char sym)
{
	int shift;
	int	bit;
	int res;
	
	shift = 0;
	while (shift < 8)
	{
		bit = (sym >> shift) & 1;
		if (bit == 0)
		{
			res = kill(pid, SIGUSR1);
		}
		else
		{		
			res = kill(pid, SIGUSR2);
		}
		shift++;
		usleep(200);
	}
	if (res == -1)
	{
		write(1, "Server PID is invalid\n", 23);
		return ;
	}
}

int main(int argc, char **argv)
{
	int pid;
	int i;

	i = 0;
	if (argc != 3)
	{
		write(1, "Invalid value, you must enter: [PID] [message]\n", 48);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_string_delivery(pid, argv[2][i]);
			return (0);
		i++;
	}
	return (0);
}