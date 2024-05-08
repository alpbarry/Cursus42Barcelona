/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 22:11:34 by Nik               #+#    #+#             */
/*   Updated: 2024/05/08 13:02:38 by alphbarr         ###   ########.fr       */
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

void	draw_matrix(t_fdf **matrix)
{
	int		y;
	int		x;

	//print_menu(*matrix);
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], *matrix);
			if (!matrix[y][x].is_last)
				line(matrix[y][x], matrix[y][x + 1], *matrix);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
