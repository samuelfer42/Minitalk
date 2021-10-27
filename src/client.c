/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:01:14 by safernan          #+#    #+#             */
/*   Updated: 2021/10/27 21:04:27 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	pass_char(int pid, unsigned char c)
{
	int	i;
	int	result;

	i = 0;
	while (i <= 7)
	{
		if (c & (1 << i))
			result = kill(pid, SIGUSR1);
		else
			result = kill(pid, SIGUSR2);
		if (result == -1)
		{
			write(STDERR_FILENO, "Erreur PID\n", 12);
			exit (1);
		}
		usleep(50);
		i++;
	}
}

static int	get_pnumber(char *argv)
{
	int	id;

	id = 0;
	while (*argv)
	{
		if (*argv >= '0' && *argv <= '9')
			id = (id * 10) + (*argv - '0');
		else
			return (0);
		 argv++;
	}
	return (id);
}

static void	msg_confirmation(int sig)
{
	if (sig == SIGUSR1)
		write(STDOUT_FILENO, "Message recu par le serveur !\n", 31);
	if (sig == SIGUSR2)
	{
	}
	usleep(50);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
		return (write(STDERR_FILENO, ERRARGC, 56), 0);
	signal(SIGUSR1, msg_confirmation);
	signal(SIGUSR2, msg_confirmation);
	pid = get_pnumber(argv[1]);
	if (!pid)
		return (write(STDERR_FILENO, ERRARGC, 56), 0);
	while (*argv[2])
	{
		pass_char(pid, *argv[2]);
		argv[2]++;
	}
	pass_char(pid, '\0');
}
