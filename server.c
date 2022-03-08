#include "minitalk.h"

void	print(int signal)
{
	static char sym;
	static int bit;

	if (signal == SIGUSR1)
		signal = 0;
	else
		signal = 1;
	sym += signal << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &sym, 1);
		bit = 0;
		sym = 0;
	}

}

int	main(void)
{
	int pid;

	pid = getpid();
	ft_putstr_fd("Server PID is: ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR2, print);
	signal(SIGUSR1, print);
	while (1)
		pause();
}
