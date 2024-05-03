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

// FDF
typedef struct s_fdf
{
	int	width;
	int	height;
	int	**z_matrix;
	int	zoom;
	int	shift_x;
	int	shift_y;
	int	color;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

int	get_heigth(char *filename);
int	get_width(char *filename);
void	fill_matrix(int	*z_line, char *line);
void	read_file(char *filename, t_fdf *data);
int	deal_key(int key, t_fdf *data);
int	ft_wordcount(char *s, char c);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);
void	isometric(float *x, float *y, int z);

// POINT
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_floatpoint
{
	float	x;
	float	y;
}	t_floatpoint;

// IMAGE
typedef struct s_img
{
	void	*img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}	t_img;

//Color
typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}   t_color;

// COORDE
typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

// MLX
typedef struct s_gen
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_point	**points;
	int	WIDTH;
	int	HEIGHT;
	int	x_max;
	int	y_max;
	int	z_max;
	int	x_min;
	int	y_min;
	int	z_min;
}	t_gen;

#endif
