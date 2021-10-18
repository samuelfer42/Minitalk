/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:01:14 by safernan          #+#    #+#             */
/*   Updated: 2021/10/18 14:34:48 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	send_signals(char *message, int pid)
{
   int	i;
   int	shift;

   shift = -1;
   i = 0;
   while (message[i])
   {
   	while (++shift < 8)
   	{
   		if (message[i] & (0x80 >> shift))
   		{
   			if (kill(pid, SIGUSR2) == -1)
   				exit(1);
   		}
   		else
   		{
   			if (kill(pid, SIGUSR1) == -1)
   				exit (1);
   		}
   		usleep(3);
   	}
   	i++;
   }
}

int	main(int argc, char *argv[])
{
   int		pid;

   if (argc != 3)
   {
   	printf("client: invalid arguments\n");
   	printf("\tcorrect format [./%s SERVER_PID MESSAGE\n]", argv[0]);
   	exit(EXIT_FAILURE);
   }
   pid = atoi(argv[1]);
   send_signals(argv[2], pid);
   return (0);
}