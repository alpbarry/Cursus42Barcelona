/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:19:57 by Nik               #+#    #+#             */
/*   Updated: 2024/05/08 14:56:33 by alphbarr         ###   ########.fr       */
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
	//int	i;

	points = ft_split(line, ' ');
	if (!points)
		return (-1);
	x = 0;
	/*matrix = (t_fdf **)malloc(sizeof(t_fdf *) * y);
	if (!matrix)
		return (-1);
	i = 0;
	while (i < y)
	{
		matrix[i] = (t_fdf *)malloc(sizeof(t_fdf) * x);
		if (!matrix[i])
		{
			while (i-- > 0)
				free(matrix[i]);
			free(matrix);
			return (-1);
		}
		i++;
	}*/
	ft_printf("y: %i\n", y);//DEBUG
	ft_printf("antes del while de get points \n");//DEBUG
	while (points[x])
	{
		if (ft_strcmp(points[x], "\n") == 0)
		{
			x++;
			continue;
		}
		ft_printf("x:%i\n", x);//DEBUG
		ft_printf("atoi\n");//DEBUG
		ft_atoi(points[x]);
		matrix[y][x].z = ft_atoi(points[x]);
		ft_printf("x\n");//DEBUG
		matrix[y][x].x = x;
		ft_printf("y\n");//DEBUG
		matrix[y][x].y = y;
		ft_printf("is last\n");//DEBUG
		//matrix[y][x].is_last = 0;
		free(points[x]);
		x++;
	}
	ft_printf("despues de while de get points \n");//DEBUG
	free(points);
	//free(line);
	//matrix[y][--x].is_last = 1;
	return (x);
}
/*
t_fdf	**memory_allocate(char *filename)
{
	t_fdf	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	ft_printf("antes de fd open\n");//DEBUG
	if ((fd = open(filename, O_RDONLY, 0)) <= 0)
	{
		ft_error("file does not exist");
		return (NULL);
	}
	ft_printf("despues de fd open\n");//DEBUG
	ft_printf("antes de gnl\n");//DEBUG
	if (get_next_line(fd) <= 0)
	{
		close(fd);
		return (NULL);
	}
	ft_printf("despues de  gnl\n");//DEBUG
	line = get_next_line(fd);	
	ft_printf("antes de  word \n");//DEBUG
	x = ft_wordcounter(line, ' ');
	ft_printf("despues de word \n");//DEBUG
	free(line);
	ft_printf("despuesd del primer free line \n");//DEBUG
	y = 0;
	while (get_next_line(fd) > 0)
		y++;
	new = (t_fdf **)malloc(sizeof(t_fdf *) * (++y + 1));
	if (new == NULL)
		ft_error("memory allocation failed");
	while (y > 0)
	{
		new[--y] = (t_fdf *)malloc(sizeof(t_fdf) * (x + 1));
		if (new[y] == NULL)
		{
		close(fd);
		ft_error("memory allocation failed");
		return (NULL);
		}
	}
	close(fd);
	return (new);
}*/

t_fdf	**read_file(char *filename)
{
	t_fdf	**matrix;
	int		y;
	int		fd;
	char	*line;
	int		cols;
	int		rows;
	int		i;
	int		fd2;

	ft_printf("antes de memory allocate\n");//DEBUG
	//matrix = memory_allocate(filename);
	ft_printf("despues de get_next_line\n");///DEBUG
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_error("file does not exist");
		return (NULL);
	}
	rows = 0;
	cols = 0;
	ft_printf("antes de get_dimensions\n");//DEBUG
	get_dimensions(fd, &rows, &cols);
	ft_printf("%i\n\n\n\n%d\n\n\n\n", rows, cols);
	close(fd);
	ft_printf("despues de get_dimensions\n");//DEBUG
	matrix = (t_fdf **)malloc(sizeof(t_fdf *) * rows);
	i = 0;
	while (i < rows)
	{
		matrix[i] = (t_fdf *)malloc(sizeof(t_fdf) * cols);
		i++;
	}
	y = 0;
	line = NULL;
	ft_printf("antes de get_next_line\n");//DEBUG
	fd2 = open(filename, O_RDONLY, 0);
	if (fd2 < 0)
	{
		ft_error("file does not exist");
		return (NULL);
	}
	line = get_next_line(fd);
	ft_printf("Despues de gnl \n");//DEBUG
	while (line != NULL)
		get_points(line, matrix, y++);
	ft_printf("despues de while de read file \n");//DEBUG
	free(line);
	matrix[y] = NULL;
	close(fd2);
	return (matrix);
}
