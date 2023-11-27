/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <pdelanno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:15:55 by pdelanno          #+#    #+#             */
/*   Updated: 2023/11/27 09:06:32 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>

int		ft_atoi(const char *str);
void	char_to_bin(char c, int pid);
void	bin_to_char(int sig, siginfo_t *info, void *context);
void	sig_handler(int sig);
int		ft_printf(const char *format, ...);

#endif
