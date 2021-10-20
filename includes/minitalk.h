/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:31:42 by safernan          #+#    #+#             */
/*   Updated: 2021/10/20 13:31:43 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void		ft_putstr_color_fd(char *color, char *s, int fd);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putchar_fd(char c, int fd);
char		*add_c_first(char c);
char		*add_c(char *str, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
long long	ft_atoi(const char *str);
int			ft_str_isnumeric(char *str);
int			ft_isdigit(int c);
int			ft_isspace(int c);
#endif