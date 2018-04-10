# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 12:45:24 by mtrudel           #+#    #+#              #
#    Updated: 2016/12/14 12:49:24 by mtrudel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
HEADER = fct.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = ft_check_tetri.o ft_verif_tetriminos.o check_map.o functions.o ft_map.o ft_top_left_indic.o ft_affichage.o main.o
SRCS = ft_check_tetri.c ft_verif_tetriminos.c check_map.c functions.c ft_map.c ft_top_left_indic.c ft_affichage.c main.c

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -c -I $(SRCS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
all: $(NAME)
.PHONY: clean fclean re all
