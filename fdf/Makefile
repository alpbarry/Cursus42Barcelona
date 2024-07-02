# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 14:10:47 by alphbarr          #+#    #+#              #
#    Updated: 2024/07/02 16:21:50 by alphbarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<--------------------------------->COLORS<----------------------------------->#
DEF_COLOR	=	\033[1;99m
WHITE_BOLD	=	\033[1m
BLACK		=	\033[1;90m
RED			=	\033[1;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[1;94m
PINK		=	\033[1;95m
CIAN		=	\033[1;96m

#<--------------------------------->NAME<------------------------------------>#
NAME		=	FdF

#<-------------------------------->LIBRARY<---------------------------------->#
LIBRARY		= libs/
LIB_A		=	libs/libft/libft.a libs/ft_printf/libftprintf.a
MLXLIB		=	libs/mlx_linux/libmlx.a -lXext -lX11 -lm -lz
LIB_SEARCH	=	-L./libs/libft -L./libs/ft_printf -L./libs/mlx_linux/ \
				-lft -lftprintf -lmlx -lm

#<-------------------------------->HEADERS<---------------------------------->#
HEADER		=	./includes/
PRINTF_H	=	./ft_printf/
LIBFT_H		=	./libft/sources/
MLX_H		=	./mlx_linux/

#<--------------------------------->DIRS<------------------------------------>#
SRC_DIR		=	sources/
OBJ_DIR		=	objects/

#<--------------------------------->FILES<---------------------------------->#
FILES		=	main.c \
				change_window_size.c \
				deal_key.c \
				draw.c \
				utils2.c \
				keys.c \
				print_menu.c \
				read_map.c \
				set_param.c \
				utils.c

#<--------------------------------->SRCS<----------------------------------->#
SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))

#<----------------------------->OBJS && DEPS<------------------------------->#
OBJS		=	$(addprefix $(OBJ_DIR), $(subst .c,.o,$(SRCS)))
DEPS		=	$(subst .o,.d,$(OBJS))

#<-------------------------------->COMANDS<---------------------------------->#
INCLUDE		=	-I$(HEADER) -I$(PRINTF_H) -I$(LIBFT_H) -I$(MLX_H)
RM			=	rm -rf
MKD			=	mkdir -p
MK			=	Makefile
CFLAGS		=	-Wall -Wextra -Werror -O3# -fsanitize=address
MKFLAGS		=	--no-print-directory

#<--------------------------------->RULES<----------------------------------->#
$(OBJ_DIR)%.o	:	%.c $(LIB_A) $(MK)
	@$(MKD) $(dir $@)
	@printf "$(PINK)       \rCompiling: $(YELLOW)$(notdir $<)...$(DEF_COLOR)       \r"
	@$(CC) -MT $@ $(CFLAGS) -MMD -MP $(INCLUDE) -c $< -o $@

	all				:
	@$(MAKE) $(MKFLAGS) -C libft/
	@$(MAKE) $(MKFLAGS) -C ft_printf/
	@$(MAKE) $(MKFLAGS) -C mlx_linux/
	@$(MAKE) $(MKFLAGS) $(NAME)


$(NAME)			:	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_SEARCH) $(MLXLIB) -o $@
	@echo "\n$(GREEN)FdF has been compiled$(DEF_COLOR)"

clean			:
	@$(MAKE) $(MKFLAGS) clean -C libft/
	@$(MAKE) $(MKFLAGS) clean -C ft_printf/
	@$(MAKE) $(MKFLAGS) clean -C mlx_linux/
	@$(RM) $(OBJ_DIR)
	@echo ""
	@echo "$(RED)All OBJS && DEPS has been removed$(DEF_COLOR)"
	@echo ""

fclean			:
	@$(MAKE) $(MKFLAGS) clean
	@$(MAKE) $(MKFLAGS) fclean -C libft/
	@$(MAKE) $(MKFLAGS) fclean -C ft_printf/
	# @$(MAKE) $(MKFLAGS) fclean -C mlx_linux/
	@$(RM) $(NAME)
	@echo ""
	@echo "$(RED)Program has been removed$(DEF_COLOR)"

re				:
	@$(MAKE) $(MKFLAGS) fclean
	@$(MAKE) $(MKFLAGS) all
	@echo ""
	@echo "$(CIAN)FdF has been recompiled$(DEF_COLOR)"

.PHONY			: all clean fclean re

-include		$(DEPS)
