/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:16:07 by gtrinida          #+#    #+#             */
/*   Updated: 2022/03/11 18:19:02 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_nlen(int n)
{
	long long int	number;
	int				count;

	count = 0;
	number = n;
	if (number < 0)
	{
		number = number * (-1);
		count++;
	}
	if (number == 0)
		count++;
	while (number > 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	int				len;
	char			num[10000];
	long long int	number;

	number = n;
	i = 0;
	len = ft_nlen(n);
	num[len--] = '\0';
	if (number < 0)
	{
		num[0] = '-';
		number = number * (-1);
	}
	else if (number == 0)
		num[0] = '0';
	while (number > 0)
	{
		num[len--] = '0' + (number % 10);
		number = number / 10;
	}
	while (num[i] != '\0')
	{
		write(fd, &num[i++], 1);
	}
}
