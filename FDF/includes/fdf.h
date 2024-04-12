#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>

// MACROS
# define WIDTH 1024
# define HEIGHT 1024
# ifndef ENDIANESS
#  define ENDIANESS 0 //0: little, 1: big

# endif
// STRUCTURES

// 2D point Vector
typedef struct s_2d_point
{
    int x;
    int y;
}   t_2d_point;

// 3D point Vector
typedef struct s_3d_point
{
    double  x;
    double  y;
    double  z;
    int     color;
}   t_3d_point;


// 3D Matrix
typedef struct s_3d_matrix
{
    t_3d_point  x;
    t_3d_point  y;
    t_3d_point  z;
}   t_3d_matrix;


// Map
typedef struct s_map_element
{
    int     x;
    int     y;
    int     z;
    int     color;
    int     is_last;
}   t_map_element;

typedef struct s_map_border
{
    t_2d_point  min;
    t_2d_point  max;
}   t_map_border;

//Offset
typedef struct s_offset
{
	int	x;
	int	y;
}	t_offset;

//Line ploting
typedef struct s_plot_line_tools
{
	int	dx;
	int	dy;
	int	xi;
	int	yi;
	int	d;
}	t_plot_line_tools;

//Color
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}   t_color;

#endif