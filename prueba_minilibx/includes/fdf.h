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

// Map
typedef struct s_map_element
{
    int     x;
    int     y;
    int     z;
    int     color;
    int     is_last;
}   t_map_element;

// Color
int	create_trgb(int p, int c, int mc);
int	create_color(int p, int c, int mc);

// Matrix

#endif
