/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 00:55:04 by Nik               #+#    #+#             */
/*   Updated: 2024/06/11 14:29:48 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	is_key(int key)
{
	return (key == KEY_P || key == KEY_PT || key == KEY_M || key == KEY_MT
		|| key == KEY_8 || key == KEY_8T || key == KEY_2 || key == KEY_2T
		|| key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT
		|| key == KEY_RIGHT || key == KEY_5 || key == KEY_5T || key == KEY_4
		|| key == KEY_4T || key == KEY_SPACE || key == KEY_6 || key == KEY_6T);
}

void	do_key(int key, t_fdf **matrix)
{
	handle_angle_keys(key, matrix);
	handle_scale_keys(key, matrix);
	handle_z_scale_keys(key, matrix);
	handle_shift_keys(key, matrix);
	handle_isometric_keys(key, matrix);
}

void	new_image(t_fdf *mlx, t_fdf *img)
{
	//int		i;

	//i = 0;
	if (mlx->img_ptr == img)
		mlx_destroy_image(mlx->mlx_ptr, img->img_ptr);
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);

	/*while (i < (*matrix)->size_line * (*matrix)->win_y)
	{
		(*matrix)->addr[i] = 0;
		i++;
	}*/
}

int	deal_key(int key, t_fdf **matrix)
{
	if (is_key(key))
	{
		new_image((*matrix)->mlx_ptr, (*matrix)->win_ptr);
		do_key(key, matrix);
		draw_matrix(matrix, (*matrix)->rows, (*matrix)->cols);
		mlx_put_image_to_window((*matrix)->mlx_ptr, (*matrix)->win_ptr, (*matrix)->img_ptr, 0, 0);
		print_menu(**matrix);
	}
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
		new_window(key, matrix);
	if (key == KEY_ESC)
	{
		mlx_destroy_window((*matrix)->mlx_ptr, (*matrix)->win_ptr);
		free_matrix(matrix, (*matrix)->rows);
		exit(0);
	}
	return (0);
}
