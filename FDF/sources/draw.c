/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:04:51 by alphbarr          #+#    #+#             */
/*   Updated: 2024/04/22 20:02:13 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************* */
#include "../includes/fdf.h"

t_line    *create_line(t_vector *start, t_vector *end, int color)
{
    t_line	*line;

    line = malloc(sizeof(t_line));
    if (line == NULL)
    {
        ft_printf("%s", "Error: malloc failed\n");
        return (NULL);
    }
    line->start = start;
    line->end = end;
    line->color = color;
    return (line);
}

void draw_line(t_line *line, t_vars *vars)
{
    int dx, dy, p, x, y, x2, y2;

    dx = line->end->x - line->start->x;
    dy = line->end->y - line->start->y;
    p = 2 * dy - dx;
    if(line->start->x > line->end->x)
    {
        x = line->end->x;
        y = line->end->y;
        x2 = line->start->x;
    }
    else
    {
        x = line->start->x;
        y = line->start->y;
        x2 = line->end->x;
    }
    mlx_pixel_put(vars->mlx, vars->win, x, y, line->color);
    while(x < x2)
    {
        x++;
        if(p < 0)
            p = p + 2 * dy;
        else
        {
            y++;
            p = p + 2 * dy - 2 * dx;
        }
        mlx_pixel_put(vars->mlx, vars->win, x, y, line->color);
    }
}