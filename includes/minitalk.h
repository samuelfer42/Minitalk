#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_RESET	"\x1b[0m"
void    ft_putstr_color_fd(char *color, char *s, int fd);
void	ft_putstr_fd(char const *s, int fd);
char	*ft_straddc(char *s, char c, char lr);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar_fd(char c, int fd);
#endif