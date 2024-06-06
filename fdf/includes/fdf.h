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


// Keycodes


# endif
# define KEY_ESC 53
# define KEY_8 91
# define KEY_8T 28
# define KEY_2 84
# define KEY_2T 19
# define KEY_4 86
# define KEY_4T 21
# define KEY_6 88
# define KEY_6T 22
# define KEY_P 24
# define KEY_PT 69
# define KEY_M 27
# define KEY_MT 78
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_5 87
# define KEY_5T 23
# define KEY_SPACE 49


// STRUCTURES


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
	void		*img_ptr;
	char		*line;
	int			rows;
	int			cols;
}				t_fdf;


void	new_window(int key, t_fdf **matrix);
int		deal_key(int key, t_fdf **matrix);
void	draw_matrix(t_fdf **matrix, int rows, int cols);
void	ft_error(char *error);
void	isometric(t_fdf *fdf, double angle);
void	print_menu(t_fdf param);
t_fdf	**read_file(char *filename);
void	set_param(t_fdf *a, t_fdf *b, t_fdf *param);
int		max(int a, int b);
int		mod(int a);
int		ft_strcmp(const char *s1, const char *s2);
void	get_dimensions(int fd, int *rows, int *cols);

//KEYS
void	handle_angle_keys(int key, t_fdf **matrix);
void	handle_scale_keys(int key, t_fdf **matrix);
void	handle_shift_keys(int key, t_fdf **matrix);
void	handle_z_scale_keys(int key, t_fdf **matrix);
void	handle_isometric_keys(int key, t_fdf **matrix);

#endif
