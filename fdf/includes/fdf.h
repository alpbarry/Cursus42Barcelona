/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:34:35 by alphbarr          #+#    #+#             */
/*   Updated: 2024/06/08 13:48:51 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>

// MACROS
# ifndef ENDIANESS
#  define ENDIANESS 0 // 0: little, 1: big0

// Keycodes

# endif
# define KEY_ESC 65307
# define KEY_8 65421
# define KEY_8T 65296
# define KEY_2 65433
# define KEY_2T 65300
# define KEY_4 65430
# define KEY_4T 65323
# define KEY_6 65432
# define KEY_6T 65324
# define KEY_P 65300
# define KEY_PT 65431
# define KEY_M 65421
# define KEY_MT 65453
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_5 65437
# define KEY_5T 65305
# define KEY_SPACE 32

// STRUCTURES

typedef struct s_fdf
{
	float	x;
	float	y;
	float	z;
	int		is_last;
	int		color;
	int		scale;
	int		z_scale;
	int		shift_x;
	int		shift_y;
	int		is_isometric;
	double	angle;
	int		win_x;
	int		win_y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int	size_line;
	int	bpp;
	int	endian;
	char	*line;
	int		rows;
	int		cols;
}			t_fdf;

void		new_window(int key, t_fdf **matrix);
int			deal_key(int key, t_fdf **matrix);
void		draw_matrix(t_fdf **matrix, int rows, int cols);
void		ft_error(char *error);
void		isometric(t_fdf *fdf, double angle);
void		print_menu(t_fdf param);
t_fdf		**read_file(char *filename);
void		set_param(t_fdf *a, t_fdf *b, t_fdf *param);
int			max(int a, int b);
int			mod(int a);
int			ft_strcmp(const char *s1, const char *s2);
void		get_dimensions(int fd, int *rows, int *cols);
void		free_matrix(t_fdf **matrix, int rows);

// KEYS
void		handle_angle_keys(int key, t_fdf **matrix);
void		handle_scale_keys(int key, t_fdf **matrix);
void		handle_shift_keys(int key, t_fdf **matrix);
void		handle_z_scale_keys(int key, t_fdf **matrix);
void		handle_isometric_keys(int key, t_fdf **matrix);

#endif
