# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 10:22:50 by alphbarr          #+#    #+#              #
#    Updated: 2024/02/28 09:24:34 by alphbarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar rcs
RM = rm -rf

CC = gcc
CCFLAGS = -g -Wall -Wextra -Werror

NAME = libftprintf.a
SRC = ft_basics.c ft_hexa.c ft_printf.c ft_puntero.c
OBJ = $(SRC:.c=.o)
LIB = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(AR) $(NAME) $(OBJ)
	echo "$(G)Library $(NAME) Done :)"

%.o: %.c Makefile $(LIB)
	$(CC) $(CCFLAGS) -c $< -o $@
	echo "$(ligth)$@ Compiled"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean re fclean
