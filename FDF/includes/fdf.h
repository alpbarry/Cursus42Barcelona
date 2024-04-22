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

// Keycodes

#  define KEY_ESC 53

# endif
// STRUCTURES
// Vector
typedef struct s_vector
{
    float  x;
    float  y;
    float  z;
}   t_vector;

t_vector	create_vector(float x, float y, float z);

// Matrix
typedef struct s_matrix
{
    t_vector  vx;
    t_vector  vy;
    t_vector  vz;
}   t_matrix;

t_matrix	create_matrix(t_vector vx, t_vector vy, t_vector vz);


// Color
int	create_color(int c);

// Line

typedef struct s_line
{
	t_vector  *start;
	t_vector  *end;
	int  color;
}   t_line;

t_line	*create_line(t_vector *start, t_vector *end, int color);

// Mlx

typedef struct s_vars
{
    void  *mlx;
    void  *win;
}  t_vars;

typedef struct s_data
{
    void  *img;
    char  *addr;
    int  bits_per_pixel;
    int  line_length;
    int  endian;
}   t_data;

#endif
