#include "minitalk.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

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
	ft_putchar('\n');
	signal(SIGUSR2, print);
	signal(SIGUSR1, print);
	while (1)
		pause();
}