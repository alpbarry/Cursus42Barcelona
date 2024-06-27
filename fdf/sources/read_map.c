/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:19:57 by Nik               #+#    #+#             */
/*   Updated: 2024/06/27 22:07:35 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <sys/stat.h>

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
	int		j;
	t_fdf	**matrix;

	i = 0;
	matrix = (t_fdf **)malloc(sizeof(t_fdf *) * rows);
	if(!matrix)
	{
		ft_error("Failed to allocate memory for rows");
		return (NULL);
	}
	while (i < rows)
	{
		matrix[i] = (t_fdf *)malloc(sizeof(t_fdf) * cols);
		if (!matrix[i])
		{
			ft_error("Failed to allocate for columns");
			while (--i >= 0)
				free(matrix[i]);
			free(matrix);
			return (NULL);
		}
		j = 0;
		while (j < cols)
		{
			ft_memset(&matrix[i][j], 0, sizeof(t_fdf));
			j++;
		}
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
	check_file_status(fd);	
	get_dimensions(fd, &rows, &cols);
	matrix = initialize_matrix(rows, cols);
	return (fill_matrx(matrix, filename, rows, cols));
}
