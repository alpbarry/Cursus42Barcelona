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

# Ajuste de OBJS para que apunten al directorio correcto
OBJS	= ${addprefix objects/, ${SRCS:.c=.o}}

# BOBJS y BDEPS no parecen necesarios sin definir BSRCS en el contexto dado
# BOBJS	= ${addprefix obj/, ${BSRCS:.c=.o}}
# DEPS y BDEPS tampoco son utilizados en este contexto
# DEPS	= ${addprefix obj/, ${SRCS:.c=.d}}
# BDEPS	= ${addprefix obj/, ${BSRCS:.c=.d}}

NAME	= fdf

RM		= rm -rf

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

#MXFLAGS	= -Llibs/mlx -lmlx -framework OpenGL -framework AppKit -lm

LIBFT	= libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

MLXLIB	= mlx

all:		dir ${NAME}

${NAME}:	${OBJS} dir
				${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MXFLAGS} -o ${NAME}

linux:
				make LINUX=1 MLXLIB=mlx_linux MXFLAGS="libs/mlx_linux/libmlx.a -lXext -lX11 -lm -lz" all

dir:
				mkdir -p objects
				make -C libft
				make -C ft_printf
				make -C mlx_linux

# Ajuste para compilar los archivos en objects/
objects/%.o: src/%.c Makefile

				${CC} ${CFLAGS} -c $< -MMD -o $@ -D LINUX=1

clean:
				make clean -C libft/
				make clean -C ft_printf/
				make clean -C mlx_linux
				${RM} objects/

lclean:
				make MLXLIB=mlx_linux fclean

fclean:		clean
				make clean -C mlx_linux
				make fclean -C libft
				make fclean -C ft_printf
				${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all linux bonus lbonus lclean

