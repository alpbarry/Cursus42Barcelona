#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <math.h>

// MACROS
# ifndef ENDIANESS
#  define ENDIANESS 0 //0: little, 1: big0

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
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

int	get_heigth(char *filename);
int	get_width(char *filename);
void	fill_matrix(int	*z_line, char *line);
void	read_file(char *filename, t_fdf *data);
int	deal_key(int key, void *data);
int	ft_wordcount(char *s, char c);

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
