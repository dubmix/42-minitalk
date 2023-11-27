/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <pdelanno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:14:55 by pdelanno          #+#    #+#             */
/*   Updated: 2023/11/27 09:07:00 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	if (str[i] == 7 || str[i] == 8)
		return (0);
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 7))
		i++;
	if (str[i] == '-')
		neg = neg * -1;
	if (str[i] == '+' || str [i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (neg * nb);
}

void	char_to_bin(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		usleep(50);
	}
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		printf("Message has been received by server!\n");
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			char_to_bin(argv[2][i], pid);
			i++;
		}
		signal(SIGUSR1, sig_handler);
		char_to_bin('\0', pid);
	}
	else
		printf("Error\n");
	return (0);
}
