/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:16:47 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/11 20:39:28 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void signal_sent(int signal, siginfo_t *info, void *null)
{
	(void)null;
	(void)info;
	(void)signal;

	ft_putstr_fd("Signal delivered\n", 1);
	exit(1);
}

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
		usleep(150);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	struct sigaction sa;
	
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_sent;
	if(sigaction(SIGUSR2, &sa, 0) == -1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
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
	int len = ft_strlen(argv[2]);
	while (i <= len)
	{
		ft_string_delivery(pid, argv[2][i]);
		i++;
	}
	while (1)
		pause();
	return (0);
}
