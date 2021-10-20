# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: safernan <safernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 14:47:46 by safernan          #+#    #+#              #
#    Updated: 2021/10/20 13:29:07 by safernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

INCLUDES = includes/

CC = gcc
FLAG = -Wall -Wextra -Werror 

FILES_C = 	src/client.c \
			src/libft_1.c \
			src/libft_2.c  \
			src/libft_3.c 
FILES_S =	src/server.c \
			src/libft_1.c \
			src/libft_2.c \
			src/libft_3.c 


all: $(SERVER) $(CLIENT)

$(SERVER): 
	@$(CC) $(FLAG) $(FILES_S) -I $(INCLUDES) -o $(SERVER)
	@printf "$(_SUCCESS) server ready.\n"

$(CLIENT): 
	@$(CC) $(FLAG) $(FILES_C) -I $(INCLUDES) -o $(CLIENT)
	@printf "$(_SUCCESS) client ready.\n"
	
clean:
	@$(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"
	

fclean: clean
	@ $(RM) $(CLIENT) $(SERVER)



re : fclean all

.PHONY: clean fclean