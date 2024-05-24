/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:34:52 by alphbarr          #+#    #+#             */
/*   Updated: 2024/05/24 11:34:57 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	line(t_fdf a, t_fdf b, t_fdf *param)
{
	float	dx;
	float	dy;
	float	max;
	int		color;

	set_param(&a, &b, param);
	dx = b.x - a.x;
	dy = b.y - a.y;
	max = MAX(MOD(dx), MOD(dy));
	dx /= max;
	dy /= max;
	color = (b.z || a.z) ? 0xfc0345 : 0xBBFAFF;
	color = (b.z != a.z) ? 0xfc031c : color;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, color);
		a.x += dx;
		a.y += dy;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw_matrix(t_fdf **matrix, int rows, int cols)
{
	int		y;
	int		x;
	//int	color;

	print_menu(**matrix);
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			//color = matrix[y][x].color;
			printf("%f %f\n", matrix[y][x].x, matrix[y][x].y);//DEBUG
			if (y + 1 < rows)
				line(matrix[y][x], matrix[y + 1][x], *matrix/*,matrix[y][x].line*/);
			if (x + 1 < cols)
				line(matrix[y][x], matrix[y][x + 1], *matrix/*, matrix[y][x].line*/);
			x++;
		}
		y++;
	}
}
