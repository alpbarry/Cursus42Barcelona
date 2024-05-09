/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 00:55:04 by Nik               #+#    #+#             */
/*   Updated: 2024/05/07 14:57:53 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		is_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 ||\
	key == 91 || key == 28 || key == 84 || key == 19 ||\
	key == '~' || key == '}' || key == '{' || key == '|' ||\
	key == 87 || key == 23 || key == 86 || key == 21 ||\
	key == 49 || key == 88 || key == 22);
}

void	do_key(int key, t_fdf **matrix)
{
	if (key == 24 || key == 69)
		(* matrix)->scale += 3;
	if (key == 27 || key == 78)
		(* matrix)->scale -= 3;
	if (key == 91 || key == 28)
		(* matrix)->z_scale += 1;
	if (key == 84 || key == 19)
		(* matrix)->z_scale -= 1;
	if (key == '~')
		(* matrix)->shift_y -= 10;
	if (key == '}')
		(* matrix)->shift_y += 10;
	if (key == '{')
		(* matrix)->shift_x -= 10;
	if (key == '|')
		(* matrix)->shift_x += 10;
	if (key == 49 || key == 87 || key == 23)
	{
		if ((*matrix)->is_isometric) 
       		(*matrix)->is_isometric = 0;
   		else
       		(*matrix)->is_isometric = 1;
	}
	if (key == 86 || key == 21)
		(* matrix)->angle += 0.05;
	if (key == 88 || key == 22)
		(* matrix)->angle -= 0.05;
}

int		deal_key(int key, t_fdf **matrix)
{
	if (is_key(key))
	{
		mlx_clear_window((* matrix)->mlx_ptr, (* matrix)->win_ptr);
		do_key(key, matrix);
		print_menu(**matrix);
		draw_matrix(matrix);
	}
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
		new_window(key, matrix);
	if (key == '5')
	{
		mlx_destroy_window((* matrix)->mlx_ptr, (* matrix)->win_ptr);
		free(matrix);
		exit(0);
	}
	return (0);
}
