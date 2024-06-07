/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:19:57 by Nik               #+#    #+#             */
/*   Updated: 2024/05/28 19:58:46 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_dimensions(int fd, int *rows, int *cols)
{
	char	*line;
	int		i;
	char	**points;

	*rows = 0;
	*cols = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*rows == 0)
		{
			points = ft_split(line, ' ');
			i = 0;
			while (points[i])
			{
				free(points[i]);
				i++;
				(*cols)++;
			}
			free(points);
		}
		(*rows)++;
		free(line);
		line = get_next_line(fd);
	}
}

int	get_points(char *line, t_fdf **matrix, int y)
{
	char	**points;
	int		x;

	points = ft_split(line, ' ');
	if (!points)
		return (-1);
	x = 0;
	while (points[x])
	{
		if (ft_strcmp(points[x], "\n") == 0)
		{
			free(points[x]);
			x++;
			continue ;
		}
		ft_atoi(points[x]);
		matrix[y][x].z = ft_atoi(points[x]);
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		free(points[x]);
		x++;
	}
	free(points);
	return (x);
}

t_fdf	**initialize_matrix(int rows, int cols)
{
	int		i;
	t_fdf	**matrix;

	i = 0;
	matrix = (t_fdf **)malloc(sizeof(t_fdf *) * rows);
	while (i < rows)
	{
		matrix[i] = (t_fdf *)malloc(sizeof(t_fdf) * cols);
		i++;
	}
	return (matrix);
}

t_fdf	**fill_matrx(t_fdf **matrix, char *filename, int rows, int cols)
{
	int		y;
	char	*line;
	int		fd;

	y = 0;
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_error("file does not exist");
		return (NULL);
	}
	line = get_next_line(fd);
	while (line)
	{
		get_points(line, matrix, y++);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	(*matrix)->rows = rows;
	(*matrix)->cols = cols;
	close(fd);
	return (matrix);
}

t_fdf	**read_file(char *filename)
{
	int		fd;
	int		rows;
	int		cols;
	t_fdf	**matrix;

	rows = 0;
	cols = 0;
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_error("file does not exist");
		return (NULL);
	}
	get_dimensions(fd, &rows, &cols);
	matrix = initialize_matrix(rows, cols);
	return (fill_matrx(matrix, filename, rows, cols));
}
