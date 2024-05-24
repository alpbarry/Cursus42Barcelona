/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:19:57 by Nik               #+#    #+#             */
/*   Updated: 2024/05/09 13:15:01 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*save_line(char *line)
{
	char	*new;
	int		i;

	i = 0;
	while (line[i] != '\0')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (line[i] != '\0')
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	return (new);

}

void	get_dimensions(int fd, int *rows, int *cols)
{
	char	*line;
	int		i;
	char	**points;
	char	**saved_line;

	*rows = 0;
	*cols = 0;
	saved_line = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*rows == 0)
		{
			points = ft_split(line, ' ');
			i = 0;
			while (points[i])
			{
				i++;
				(*cols)++;
			}
			free(points);
		}
		(*rows)++;
		line = get_next_line(fd);
	}
}

int		ft_wordcounter(char *s, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
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
		/*if (ft_strcmp(points[x], "\n") == 0)
		{
			x++;
			continue;
		}*/
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

t_fdf	**read_file(char *filename)
{
	t_fdf	**matrix;
	int		y;
	int		fd;
	char	*line;
	int		cols;
	int		rows;
	int		i;

	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_error("file does not exist");
		return (NULL);
	}
	rows = 0;
	cols = 0;
	get_dimensions(fd, &rows, &cols);
	close(fd);
	matrix = (t_fdf **)malloc(sizeof(t_fdf *) * rows);
	i = 0;
	while (i < rows)
	{
		matrix[i] = (t_fdf *)malloc(sizeof(t_fdf) * cols);
		i++;
	}
	y = 0;
	line = NULL;
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
		line = get_next_line(fd);
	}

	free(line);
	// matrix[y] = NULL;
	(*matrix)->rows = rows;
	(*matrix)->cols = cols;
	close(fd);
	return (matrix);
}
