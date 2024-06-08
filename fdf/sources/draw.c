/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:34:52 by alphbarr          #+#    #+#             */
/*   Updated: 2024/06/08 13:41:25 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	line(t_fdf a, t_fdf b, t_fdf *param)
{
	float	dx;
	float	dy;
	float	maxim;
	int		color;

	set_param(&a, &b, param);
	dx = b.x - a.x;
	dy = b.y - a.y;
	maxim = max(mod(dx), mod(dy));
	dx /= maxim;
	dy /= maxim;
	if (b.z || a.z)
		color = 0xfc0345;
	else
		color = 0xBBFAFF;
	if (b.z != a.z)
		color = 0xfc031c;

	ft_printf("antes de while de line \n");
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{

		ft_printf("a.x = :%d\n", a.x); 
		ft_printf("a.y = :%d\n", a.y); 
		ft_printf("b.x = :%d\n", b.x); 
		ft_printf("b.y = :%d\n", b.y); 
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, color);
		ft_printf("despues mlx put de line \n");
		a.x += dx;
		a.y += dy;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw_matrix(t_fdf **matrix, int rows, int cols)
{
	int	y;
	int	x;

	print_menu(**matrix);
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (y + 1 < rows)
				line(matrix[y][x], matrix[y + 1][x], *matrix);
			if (x + 1 < cols)
				line(matrix[y][x], matrix[y][x + 1], *matrix);
			x++;
		}
		y++;
	}
}
