/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:19:57 by Nik               #+#    #+#             */
/*   Updated: 2024/05/07 21:44:15 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_wordcounter(char *s, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	ft_printf("while de fuera \n");
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	ft_printf("fuera del while \n");
	return (count);
}

int	get_points(char *line, t_fdf **matrix, int y)
{
	char	**point;
	int		x;
	//int	i;

	point = ft_split(line, ' ');
	if (!point)
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
	ft_printf("y: %i\n", y);
	ft_printf("antes del while de get points \n");
	while (point[x])
	{
		ft_printf("x:%i\n", x);
		ft_printf("atoi\n");
		ft_atoi(point[x]);
		matrix[y][x].z = ft_atoi(point[x]);
		ft_printf("x\n");
		matrix[y][x].x = x;
		ft_printf("y\n");
		matrix[y][x].y = y;
		ft_printf("is last\n");
		//matrix[y][x].is_last = 0;
		free(point[x]);
		x++;
	}
	ft_printf("despues de while de get points \n");
	free(point);
	//free(line);
	//matrix[y][--x].is_last = 1;
	return (x);
}

t_fdf	**memory_allocate(char *filename)
{
	t_fdf	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	ft_printf("antes de fd open\n");
	if ((fd = open(filename, O_RDONLY, 0)) <= 0)
	{
		ft_error("file does not exist");
		return (NULL);
	}
	ft_printf("despues de fd open\n");
	ft_printf("antes de gnl\n");
	if (get_next_line(fd) <= 0)
	{
		close(fd);
		return (NULL);
	}
	ft_printf("despues de  gnl\n");
	line = get_next_line(fd);	
	ft_printf("antes de  word \n");
	x = ft_wordcounter(line, ' ');
	ft_printf("despues de word \n");
	free(line);
	ft_printf("despuesd del primer free line \n");
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
}

t_fdf	**read_file(char *filename)
{
	t_fdf	**matrix;
	int		y;
	int		fd;
	char	*line;

	ft_printf("antes de memory allocate\n");
	matrix = memory_allocate(filename);
	ft_printf("despues de get_next_line\n");
	fd = open(filename, O_RDONLY, 0);
	y = 0;
	line = NULL;
	ft_printf("antes de get_next_line\n");
	line = get_next_line(fd);
	ft_printf("Despues de gnl \n");
	while (line != NULL)
		get_points(line, matrix, y++);
	ft_printf("despues de while de read file \n");
	free(line);
	matrix[y] = NULL;
	close(fd);
	return (matrix);
}
