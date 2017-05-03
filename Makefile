# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 14:45:32 by ramichia          #+#    #+#              #
#    Updated: 2017/05/03 13:24:57 by ramichia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ramichia.filler
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = ./libft/libft.a

SRC =  src/read_map.c src/place_piece.c src/contact.c src/target.c src/free.c \
		src/shape_opponent.c src/shape_opponent2.c src/main.c

HEADER = filler.h

LIB_PATH = ./libft

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	@ $(CC) $(FLAGS) $(SRC) $(LIB) -o $(NAME)
	@ $(CC) $(FLAGS) src/visualizer.c $(LIB) -o visualizer
	@echo "make OK"

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@$(CC) $(FLAGS)  -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@echo "clean OK"

fclean: clean
	@rm -f $(NAME)
	@rm -f visualizer
	@make fclean -C ./libft
	@echo "LIBRARY DELETED"

re: fclean all
