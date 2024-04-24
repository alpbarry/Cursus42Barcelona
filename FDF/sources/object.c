/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:30:08 by alphbarr          #+#    #+#             */
/*   Updated: 2024/04/24 11:40:18 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

void	free_points(t_point	**obj_points)
{
	t_point	*aux;
	t_point	*tmp;

	if (!*obj_points)
		return ;
	aux = *obj_points;
	while (aux)
	{
		tmp = aux->next;
		free(aux);
		aux = tmp;
	}
	*obj_points = NULL;
}

void	create_point(char **line, t_object *object, int column)
{
	t_point	*point;
	t_point	*aux;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
	{
		free_points(&object->points);
		exit(1);
	}
	point->vector.x = column;
	point->vector.y = object->rows;
	point->vector.z = ft_atoi(line[column]);
	point->next = NULL;
	if (!object->points)
		object->points = point;
	else
	{
		aux = object->points;
		while (aux->next)
			aux = aux->next;
		aux->next = point;
	}
}

int	get_points(char *line, t_object *object)
{
	char	**points;
	int		column;

	points = ft_split(line, ' ');
	if (!points)
		return (0);
	column = 0;
	while (points[column])
	{
		create_point(points, object, column);
		column++;
	}
	free(points);
	return (column);
}

void	set_object(t_object *object)
{
	t_point	*point;
	int		min_z;
	int		max_z;

	min_z = 0;
	max_z = 0;
	point = object->points;
	object->upleft = point;
	while (point)
	{
		set_object_height(point, 0);
		set_corners(point, object);
		set_connections(point);
		point->vector.x = point->vector.x - (object->columns - 1) / 2;
		point->vector.y = point->vector.y - (object->rows - 1) / 2;
		if (!(object->columns % 2))
			point->vector.x -= 0.5;
		if (!(object->rows % 2))
			point->vector.y -= 0.5;
		point = point->next;
	}
	object->slices = set_object_height(NULL, 1);
	set_color(object);
}

t_object 		make_object(char *f)
{
	t_object	object;
	t_text		*text;
	t_text		*aux;

	object.points = NULL;
	object.rows = 0;
	object.columns = 0;
	object.scale = 1;
	object.only_points = 0;
	text = read_file(f);
	if (!text)
		exit(1);
	aux = text;
	while (aux)
	{
		if (!object.columns)
			object.columns = get_points(aux->line, &object);
		else if (object.columns != get_points(aux->line, &object))
		{
			free_text(&text);
			free_points(&object.points);
			exit(1);
		}
		object.rows++;
		aux = aux->next;
	}
	set_object(&object);
	free_text(&text);
	return (object);
}


int set_object_height(t_point *point, int done)
{
	static int	min_z;
	static int	max_z;

	if (done)
		return (max_z - min_z);
	if (point->vector.z > 0 && point->vector.z > max_z)
		max_z = point->vector.z;
	else if (point->vector.z < 0 && point->vector.z < min_z)
		min_z = point->vector.z;
	return (0);
}

void	set_corners(t_point *point, t_object *object)
{
	if (point->vector.x == object->columns - 1 && point->vector.y == 0)
		object->upright = point;
	if (point->vector.x == 0 && point->vector.y == object->rows - 1)
		object->downleft = point;
}

void	set_connections(t_point *point)
{
	static t_point	*above;
	static t_point	*tmp;
	static int		y;

	if (point->vector.y > y)
	{
		y += 1;
		above = tmp;
	}
	if (point->vector.x == 0)
		tmp = point;
	if (point->next && point->next->vector.y == y)
	{
		point->right = point->next;
		point->next->left = point;
	}
	if (above)
	{
		point->up = above;
		above->down = point;
		above = above->next;
	}
}
