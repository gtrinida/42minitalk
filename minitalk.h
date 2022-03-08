#ifndef MINITOLK_H
# define MINITOLK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif