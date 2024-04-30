/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:17:12 by alphbarr          #+#    #+#             */
/*   Updated: 2024/04/22 20:03:56 by alphbarr         ###   ########.fr       */
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

void draw_lines(t_list *lines, t_vars *vars)
{
    t_list *current = lines;
    while (current != NULL)
    {
        draw_line((t_line *)current->content, vars);
        current = current->next;
    }
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "fdf");
	mlx_hook(vars.win, 2, 1L<<0, create_key, &vars);
	mlx_hook(vars.win, 17, 0, destroy_active_window, &vars);
	mlx_loop(vars.mlx);
}
