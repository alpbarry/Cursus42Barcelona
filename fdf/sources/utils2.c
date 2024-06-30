/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 22:20:39 by Nik               #+#    #+#             */
/*   Updated: 2024/06/30 13:46:09 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	default angle: 0.523599
**	make the figure 3d (isometric stile)
*/

#include "../includes/fdf.h"

void	isometric(t_fdf *fdf, double angle)
{
	fdf->x = (fdf->x - fdf->y) * cos(angle);
	fdf->y = (fdf->x + fdf->y) * sin(angle) - fdf->z;
}

void	check_file_status(int fd)
{
	struct stat	file_stat;

	if (fstat(fd, &file_stat) < 0)
	{
		close(fd);
		ft_error("could not get file status");
	}
	if (S_ISDIR(file_stat.st_mode))
	{
		close(fd);
		ft_error("attempted to read a directory");
	}
}
