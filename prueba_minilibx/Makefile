# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 12:29:05 by alphbarr          #+#    #+#              #
#    Updated: 2024/04/16 16:02:53 by alphbarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
RM = rm -rf

CC = gcc
CCFLAGS = -g -Wall -Wextra -Werror -Imlx

SOURCES_DIRECTORY = ./sources/

NAME = fdf

SRC_LIST = $(wildcard $(SOURCES_DIRECTORY)*.c)

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SRC_LIST))
OBJDIR = objects/
OBJS_LIST = $(patsubst %.c, %.o, $(notdir $(SRC_LIST)))
OBJS = $(addprefix $(OBJDIR), $(OBJS_LIST))

LIB = includes/libft.h\
	includes/get_next_line.h

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(llibft) $(NAME)

$(libft):
	@make -C libft/

$(NAME): $(OBJS) $(LIB)
	@$(CC) $(OBJS) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Library $@ Done :)"

$(OBJDIR)%.o: $(SOURCES_DIRECTORY)%.c Makefile $(LIB)
	@mkdir -p $(@D)
	@echo "$(GREEN) Compiling... $<..."
	@$(CC) $(CCFLAGS) -Iincludes -MMD -c $< -o $@
	@echo "$(RED) $@ created!"

clean:
	@echo "Remove *.o"
	@${RM} -r $(OBJDIR)
	@echo "Done !"

fclean: clean
	@echo "Remove $(NAME)"
	@${RM} $(NAME)
	@echo "Done !"

re: fclean all
