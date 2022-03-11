/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:16:21 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/11 20:36:51 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print(int signal, siginfo_t *info, void *nothing)
{
	static int				bit;
	static unsigned char	sym;

	(void)nothing;
	if (signal == SIGUSR1)
		signal = 0;
	else
		signal = 1;
	sym += signal << bit;
	bit++;
	if (bit == 8)
	{
		if (sym == 0)
			if (kill(info->si_pid, SIGUSR2))
			{
				ft_putstr_fd("\nError\n", 1);
				exit(1);
			}
		ft_putchar_fd(sym, 1);
		bit = 0;
		sym = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = print;
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
}
