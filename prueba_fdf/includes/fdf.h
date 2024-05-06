#ifndef FDF_H
# define FDF_H

#include "../mlx/mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <math.h>

// MACROS
# ifndef ENDIANESS
#  define ENDIANESS 0 //0: little, 1: big0
#define MAX1(a, b) (a > b ? a : b)
#define MOD(a) (a < 0 ? -a : a)

// Keycodes

#  define KEY_ESC 53

# endif

// STRUCTURES

# define PRM matrix[0][0]

typedef struct	s_fdf
{
	float		x;
	float		y;
	float		z;
	int			is_last;
	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

void	new_window(int key, t_fdf **matrix);
int	deal_key(int key, t_fdf **matrix);
void	draw_matrix(t_fdf **matrix);
void	ft_error(char *error);
void	isometric(t_fdf *fdf, double angle);
void	print_menu(t_fdf param);
t_fdf	**read_file(char *filename);

#endif
