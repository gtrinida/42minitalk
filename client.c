#include "minitalk.h"

void	ft_string_delivery(int pid, char sym)
{
	int	shift;
	int	bit;
	int	res;

	shift = 0;
	while (shift < 8)
	{
		bit = (sym >> shift) & 1;
		if (bit == 0)
			res = kill(pid, SIGUSR1);
		else
			res = kill(pid, SIGUSR2);
		if (res == -1)
		{
			ft_putstr_fd("Invalid PID\n", 1);
			exit(1);
		}
		shift++;
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Invalid value, you must enter: [PID] [message]\n", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		ft_putstr_fd("Incorrect server PID\n", 1);
	ft_putstr_fd("In process...\n", 1);
	while (argv[2][i])
	{
		ft_string_delivery(pid, argv[2][i]);
		i++;
	}
	ft_putstr_fd("The delivery was successful.\n", 1);
	return (0);
}
