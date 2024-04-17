/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:17:12 by alphbarr          #+#    #+#             */
/*   Updated: 2024/04/17 20:02:57 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../mlx/mlx.h"
#include "../includes/libft.h"
#include <math.h>
#define PI 3.1416

typedef struct	s_data {
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

int	main(void)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1840, 1160, "Hello world!");
	img.img = mlx_new_image(mlx, 1840, 1160);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length
			, &img.endian);
	draw_square(&img, 500, 500, 100, 0x00FFFFFF);
	draw_circle(&img, 100, 100, 100, 0x0080FFFF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
