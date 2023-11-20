/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:31:47 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/11/18 15:40:59 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile int	g_validate;

void	receive_signal(int signal, siginfo_t *info, void *context)
{
	int	pid;

	(void)context;
	pid = info->si_pid;
	if (signal == SIGUSR1 || signal == SIGUSR2)
		g_validate = 1;
}

void	ft_bits(char *argv, int pid)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 8;
		while (--j >= 0)
		{
			if ((argv[i] >> j) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (g_validate == 0)
				;
			g_validate = 0;
		}
		++i;
	}
}

void	ft_message(int id)
{
	static char	*message[1] = {
		"\n\nError! :( \n"
		"This function can only handle three parameters.\n"
		"Please write : ./client_bonus (pid) \"message\"\n"
	};

	ft_putstr_fd(message[id], 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sigact;
	sigset_t			set;
	int					pid;

	if (argc == 3 && ft_isalldigit(argv[1]))
	{
		pid = ft_atoi(argv[1]);
		sigemptyset(&set);
		sigact.sa_handler = NULL;
		sigact.sa_flags = 0;
		sigact.sa_sigaction = receive_signal;
		sigaction(SIGUSR1, &sigact, NULL);
		ft_bits(argv[2], pid);
		ft_bits("\n", pid);
		ft_printf("Message sent!\n");
		return (1);
	}
	else
		ft_message(0);
	return (0);
}
