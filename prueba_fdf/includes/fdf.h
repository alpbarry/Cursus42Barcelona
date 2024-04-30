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

<<<<<<< HEAD
<<<<<<< HEAD
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

=======
>>>>>>> 878fb1619e3d25193414dac73806c571bc20daf1
=======
// Point
typedef struct s_point
{
    t_vector  		vector;
    struct s_point  *up;
    struct s_point  *down;
    struct s_point	*left;
    struct s_point  *right;
    t_vector  *front;
    t_vector  *back;
    int  color;
    struct s_point  *next;
}   t_point;
void    free_points(t_point **obj_points);

// Object
typedef struct s_object
{
	t_point	*points;
	int		rows;
	int		columns;
	int		slices;
	float	scale;
	t_point	*upleft;
	t_point	*upright;
	t_point	*downleft;
	t_point	*downright;
	int		only_points;
}	t_object;
void    create_point(char **line, t_object *object, int column);
int     get_points(char *line, t_object *object);
void    set_object(t_object *object);
t_object    make_object(char *f);
int set_object_height(t_point *point, int mode);
void    set_corners(t_point *point, t_object *object);
void    set_connections(t_point *point);
void  reset_colors(t_object *object, int *allow_flag, int stop);
void   set_color(t_object *object);
void    draw_object(t_object *object, t_vars *vars);

// File
typedef struct s_text
{
    char	*line;
    struct s_text	*next;
}	t_text;
int    c_format(char *f);
void    free_text(t_text **t);
void    add_line(t_text **t, char *l);
t_text    *get_file(int fd);
t_text    *read_file(char *f);

>>>>>>> 65cc2111aec9795b2af2146a05625f76302a12b9
#endif
