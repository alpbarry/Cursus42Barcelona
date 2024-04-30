/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:17:12 by alphbarr          #+#    #+#             */
/*   Updated: 2024/04/24 11:20:51 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../mlx/mlx.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include "../includes/fdf.h"
#include <math.h>
#define PI 3.1416

/*typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int start_x, int start_y, int size, int color)
{
    int	x;
    int	y;

    x = start_x;
    while (x < start_x + size)
    {
        y = start_y;
        while (y < start_y + size)
        {
            my_mlx_pixel_put(data, x, y, color);
            y++;
        }
        x++;
    }
}

void	draw_circle(t_data *data, float xc, float yc, float r, int color)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = r;
    d = 3 - 2 * r;
    while (y >= x)
    {
        my_mlx_pixel_put(data, xc+x, yc+y, color);
        my_mlx_pixel_put(data, xc-x, yc+y, color);
        my_mlx_pixel_put(data, xc+x, yc-y, color);
        my_mlx_pixel_put(data, xc-x, yc-y, color);
        my_mlx_pixel_put(data, xc+y, yc+x, color);
        my_mlx_pixel_put(data, xc-y, yc+x, color);
        my_mlx_pixel_put(data, xc+y, yc-x, color);
        my_mlx_pixel_put(data, xc-y, yc-x, color);
        x++;
        if (d > 0)
        {
            y--; 
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
    }
}
*/


int destroy_active_window(t_vars *vars)
{
    if (vars->win != NULL)
        mlx_destroy_window(vars->mlx, vars->win);
    vars->win = NULL;
    exit(0);
}

int create_key(int keycode, t_vars *vars)
{
    if (keycode == KEY_ESC)
        destroy_active_window(vars);
	return (0);
}

float	get_scale(int rows, int columns)
{
	float	row_scale;
	float	column_scale;

	row_scale = HEIGTH * 0.8 / rows;
	column_scale = LENGHT * 0.8 / columns;
	if (row_scale < column_scale)
		return (row_scale);
	else
		return (column_scale);
}

void draw_object(t_object *object, t_vars *vars) {
    t_point *point = object->points;
    while (point) {
        mlx_pixel_put(vars->mlx, vars->win, point->vector.x, point->vector.y, 0xFFFFFF); // 0xFFFFFF es el color blanco
        point = point->next;
    }
}  

int	main(int ac, char **av)
{
	t_vars		vars;
	t_object	object;

	if (ac != 2)
		return (0);
	object = make_object(av[1]);
	if(!object.points)
		return (1);
	object.only_points = 1;
	object.scale = get_scale(object.rows, object.columns);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "fdf");
	mlx_hook(vars.win, 2, 1L<<0, create_key, &vars);
	mlx_hook(vars.win, 17, 0, destroy_active_window, &vars);
    draw_object(&object, &vars);
	mlx_loop(vars.mlx);
	free_points(&object.points);
}