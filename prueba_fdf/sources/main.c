/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:13:25 by vinograd          #+#    #+#             */
/*   Updated: 2024/05/23 11:13:26 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_default(t_fdf *param)
{
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr =\
	mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
}

int		main(int ac, char **av)
{
	t_fdf	**matrix;
	int	fd;
	int	rows;
	int	cols;
	//int		color;

	if (ac != 2)
		ft_error("error of ./fdf map.fdf");
	matrix = read_file(av[1]);
	set_default(matrix[0]);
	fd = open(av[1], O_RDONLY, 0);
	if (fd < 0)
		ft_error("error opening file");
	get_dimensions(fd, &rows, &cols);
	close(fd);
	draw_matrix(matrix, rows, cols);
	mlx_key_hook((* matrix)->win_ptr, deal_key, matrix);
	mlx_loop((* matrix)->mlx_ptr);
}
