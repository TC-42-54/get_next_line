#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 11:15:14 by tchezier          #+#    #+#              #
#    Updated: 2014/11/21 11:25:11 by tchezier         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = get_next_line

SRC = ./srcs/get_next_line.c

OBJ = get_next_line.o

HEADER = ./include/

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -L lib -lft -c $(SRC) -I $(HEADER)
		gcc -gtabs -L lib -lft $(OBJ) -I $(HEADER) 

clean:
		rm -f $(OBJ)

fclean:
		make clean
		rm -f $(NAME) 

re:
		make fclean
		make all

