/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:01:39 by safernan          #+#    #+#             */
/*   Updated: 2021/10/27 21:04:25 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_and_send(siginfo_t *sa)
{
	write(STDOUT_FILENO, "\n", 1);
	kill(sa->si_pid, SIGUSR1);
}

void	handler(int sig, siginfo_t *sa, void *context)
{
	static unsigned int		count;
	static unsigned char	c;
	char					mask;

	(void)context;
	if (count > 7)
	{
		count = 0;
		c = 0;
	}
	mask = 1 << count;
	if (sig == SIGUSR1)
		c = c | mask;
	if (sig == SIGUSR2)
		c = c & ~mask;
	count++;
	if (count == 8)
	{
		if (c == 0)
			print_and_send(sa);
		ft_putchar(c);
	}
	kill(sa->si_pid, SIGUSR2);
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	if (argc > 1 || !argv)
		return (write(1, "Un seul parametre est autorise\n", 32), 0);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
