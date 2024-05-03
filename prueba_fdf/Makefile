# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 12:29:05 by alphbarr          #+#    #+#              #
#    Updated: 2024/04/22 20:11:53 by alphbarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
RM = rm -rf

CC = gcc
CCFLAGS = -g -Wall -Wextra -Werror -Imlx

SOURCES_DIRECTORY = ./sources/

NAME = fdf

NPD = --no-print-directory

SRC_LIST = $(wildcard $(SOURCES_DIRECTORY)*.c)

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SRC_LIST))
OBJDIR = objects/
OBJS_LIST = $(patsubst %.c, %.o, $(notdir $(SRC_LIST)))
OBJS = $(addprefix $(OBJDIR), $(OBJS_LIST))

LIB = libft/libft.a\
	ft_printf/libftprintf.a \

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all:
	@make -C mlx $(NPD)
	@make -C libft $(NPD)
	@make -C ft_printf $(NPD)
	@make $(NAME) $(NPD)
#-Llibft -lft
$(NAME): $(OBJS) $(LIB)
	@$(CC) $(OBJS) $(LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -o $(NAME)
	@echo "Library $@ Done :)"

$(OBJDIR)%.o: $(SOURCES_DIRECTORY)%.c Makefile $(LIB)
	@mkdir -p $(@D)
	@echo "$(GREEN) Compiling... $<..."
	@$(CC) $(CCFLAGS) -Iincludes -MMD -c $< -o $@
	@echo "$(RED) $@ created!"

clean:
	@make clean -C libft/ $(NPD)
	make clean -C ft_printf/ $(NPD)
	@echo "Remove *.o"
	@${RM} -r $(OBJDIR)
	@echo "Done !"

fclean: clean
	@make clean -C mlx/ $(NPD)
	@make fclean -C libft $(NPD)
	@make fclean -C ft_printf $(NPD)
	@echo "Remove $(NAME)"
	@${RM} $(NAME)
	@echo "Done !"

re: fclean all
