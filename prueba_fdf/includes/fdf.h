#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <math.h>

// MACROS
# define WIDTH 1024
# define HEIGHT 1024
# ifndef ENDIANESS
#  define ENDIANESS 0 //0: little, 1: big

# define LENGHT 1920
# define HEIGTH 1080

// Keycodes

#  define KEY_ESC 53

# endif

// STRUCTURES

// FDF
typedef struct s_fdf
{
	int	width;
	int	height;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

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

>>>>>>> 65cc2111aec9795b2af2146a05625f76302a12b9
#endif
