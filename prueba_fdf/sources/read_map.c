/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:19:57 by Nik               #+#    #+#             */
/*   Updated: 2019/10/05 14:14:04 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_points(char *line, t_fdf **matrix, int y)
{
	char	**point;
	int		x;

	point = ft_strsplit(line, ' ');
	x = 0;
	while (point[x])
	{
		matrix[y][x].z = ft_atoi(point[x]);
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].is_last = 0;
		free(matrix[x++]);
	}
	free(point);
	free(line);
	matrix[y][--x].is_last = 1;
	return (x);
}

t_dot	**memory_allocate(char *filename)
{
	t_fdf	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
		ft_error("file does not exist");
	get_next_line(fd, &line);
	x = ft_wdcounter(line, ' ');
	free(line);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		free(line);
	}
	free(line);
	new = (t_fdf **)malloc(sizeof(t_fdf *) * (++y + 1));
	while (y > 0)
		new[--y] = (t_fdf *)malloc(sizeof(t_fdf) * (x + 1));
	close(fd);
	return (new);
}

t_fdf	**read_file(char *filename)
{
	t_fdf	**matrix;
	int		y;
	int		fd;
	char	*line;

	matrix = memory_allocate(filename);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	while (get_next_line(fd, &line) > 0)
		get_points(line, matrix, y++);
	free(line);
	matrix[y] = NULL;
	close(fd);
	return (matrix);
}
