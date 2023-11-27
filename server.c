/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <pdelanno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:15:08 by pdelanno          #+#    #+#             */
/*   Updated: 2023/11/27 09:07:21 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_to_char(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	c;

	(void)context;
	if (sig == SIGUSR2)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		printf("Error\n");
		return (1);
	}
	pid = getpid();
	printf("%d\n", pid);
	sa.sa_sigaction = bin_to_char;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
