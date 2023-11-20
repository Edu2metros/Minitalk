/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:24:26 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/11/18 15:18:23 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	string;
	static int				count;
	int						i;

	(void)context;
	i = 7;
	if (signal == SIGUSR1)
		string |= 1;
	i--;
	count++;
	if (count == 8)
	{
		count = 0;
		write(1, &string, 1);
		string = 0;
		i = 7;
	}
	string <<= 1;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sigact;
	sigset_t			set;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = receive_signal;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		;
}
