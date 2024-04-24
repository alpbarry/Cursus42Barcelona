/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:11:01 by alphbarr          #+#    #+#             */
/*   Updated: 2024/04/22 20:00:56 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

int	create_color(int c)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	nc;

	t = c >> 24 & 255;
	r = c >> 16 & 255;
	g = c >> 8 & 255;
	b = c & 255;
	nc = t << 24 | r << 16 | g << 8 | b;
		return (nc);
}

void	reset_colors(t_object *object, int *allow_flag, int stop)
{
	t_point	*point;
	int		i;

	point = object->points;
	*allow_flag = 0;
	i = 1;
	while (point && i < stop)
	{
		point->color = 0x00ffFFff;
		point = point->next;
		i++;
	}
}

void	set_color(t_object *object)
{
	t_point	*point;
	int		allow_flag;
	int		stop;

	point = object->points;
	allow_flag = 0;
	stop = object->columns * object->rows;
	while (point)
	{
		if (point->vector.z == 0)
			point->color = 0x00ffFFff;
		else if (point->vector.z > 0)
			point->color = 0x00ff00ff;
		else
			point->color = 0x0000ffFF;
		point = point->next;
	}
	reset_colors(object, &allow_flag, stop);
}
/*
int main() {
    int nc = 0xFF0000; 

    int new_color = create_color(nc);
    printf("Nuevo color: %X\n", new_color);

    return 0;
}*/
