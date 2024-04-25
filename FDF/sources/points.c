#include "../includes/fdf.h"

int	is_separator(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

t_point	*create_point(int *points, t_object *object, int column)
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
	point->vector.z = points[column];
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

int	get_points(char *line, t_object *object)
{
	char	*points;
	int		column;

	printf("get points\n");
	points = ft_split(line, ' ');
	printf("points = %s\n", points[0]);
	if (!points || !object)
		return (0);
	column = 0;
	printf("while get\n");
	while (points[column])
	{
		create_point(points, object, column);
		column++;
	}
	free(points);
	return (column);
}

void	make_point(char **line, t_object *object, int column)
{
	t_point	*point;
	int		z;

	point = create_point(line, object, column);
	if (!point)
		return (free_points(&object->points));
	z = ft_atoi(*line);
	point->vector.x = column;
	point->vector.y = object->rows;
	point->vector.z = z;
	if (**line == ',')
	{
		*line += 1;
		point->color = ft_atoi(line);
	}
	if (!object->points)
		object->points = point;
	else
		object->downright->next = point;
	object->downright = point;
}

int	get_points_in_row(char *line, t_object *object)
{
	int	count;

	count = 0;
	while (*line && count != object->columns)
	{
		while (is_separator(*line))
			line++;
		if (*line)
		{
			make_point(&line, object, count);
			count += 1;
		}
		if (!object->points)
			return (0);
		while (*line && !is_separator(*line))
			line++;
	}
	return (count);
}

void	get_points(t_text *text, t_object *object)
{
	t_text	*line;
	int		counted_columns;

	line = text;
	if (!object->columns)
		object->columns = -1;
	while (line)
	{
		counted_columns = get_points_in_row(line->line, object);
		if (!object->points)
			return ;
		if (counted_columns == 0 || counted_columns < object->columns)
			return (free_points(&object->points));
		object->columns = counted_columns;
		object->rows += 1;
		line = line->next;
	}
}