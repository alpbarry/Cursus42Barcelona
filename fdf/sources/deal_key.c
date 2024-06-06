/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 00:55:04 by Nik               #+#    #+#             */
/*   Updated: 2024/05/24 11:37:58 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	is_key(int key)
{
<<<<<<< HEAD
	return (key == 24 || key == 69 || key == 27 || key == 78 ||
			key == 91 || key == 28 || key == 84 || key == 19 ||
			key == '~' || key == '}' || key == '{' || key == '|' ||
			key == 87 || key == 23 || key == 86 || key == 21 ||
			key == 49 || key == 88 || key == 22);
=======
	return (key == 24 || key == 69 || key == 27 || key == 78 || key == 91
		|| key == 28 || key == 84 || key == 19 || key == '~' || key == '}'
		|| key == '{' || key == '|' || key == 87 || key == 23 || key == 86
		|| key == 21 || key == 49 || key == 88 || key == 22);
>>>>>>> 99cdbb3defb80f51e78b830ec375428cdc39f0c5
}

void	do_key(int key, t_fdf **matrix)
{
	handle_angle_keys(key, matrix);
	handle_scale_keys(key, matrix);
	handle_z_scale_keys(key, matrix);
	handle_shift_keys(key, matrix);
	handle_isometric_keys(key, matrix);
}

int	deal_key(int key, t_fdf **matrix)
{
	if (is_key(key))
	{
		mlx_clear_window((*matrix)->mlx_ptr, (*matrix)->win_ptr);
		do_key(key, matrix);
		draw_matrix(matrix, (*matrix)->rows, (*matrix)->cols);
		print_menu(**matrix);
	}
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
		new_window(key, matrix);
	if (key == '5')
	{
		mlx_destroy_window((*matrix)->mlx_ptr, (*matrix)->win_ptr);
		free(matrix);
		exit(0);
	}
	return (0);
}
