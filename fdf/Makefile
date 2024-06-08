SRCS	= main.c \
			change_window_size.c \
			deal_key.c \
			draw.c \
			isometric.c \
			keys.c \
			print_menu.c \
			read_map.c \
			set_param.c \
			utils.c

OBJS	= ${addprefix objects/, ${SRCS:.c=.o}}

NAME	= fdf

RM		= rm -rf

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

LIBFT	= libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

MLXLIB	=	mlx_linux/libmlx.a -lXext -lX11 -lm -lz

all:		dir ${NAME}

${NAME}:	${OBJS} dir
				${CC} ${CFLAGS} ${OBJS} ${LIBFT} $(FT_PRINTF) ${MLXLIB} -o ${NAME}
dir:
				mkdir -p objects
				make -C libft
				make -C ft_printf
				make -C mlx_linux

# Ajuste para compilar los archivos en objects/
objects/%.o: sources/%.c Makefile

				${CC} ${CFLAGS} -c $< -MMD -o $@

clean:
				make clean -C libft/
				make clean -C ft_printf/
				make clean -C mlx_linux
				${RM} objects/

fclean:		clean
				make clean -C mlx_linux
				make fclean -C libft
				make fclean -C ft_printf
				${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all

