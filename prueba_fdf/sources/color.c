/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:38:24 by alphbarr          #+#    #+#             */
/*   Updated: 2024/05/12 20:57:28 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"


int	create_color(int c)
{
	int	r;
	int	g;
	int	b;
	int	nc;

	r = c >> 16 & 255;
	g = c >> 8 & 255;
	b = c & 255;
	nc  = r << 16 | g << 8 | b;
	return (nc);
}

int	parse_color(const char *s)
{
	int		color;
	int		i;
	int		value;
	char	c;

	color = 0;
	i = 2;
	while(s[i])
	{
		c = s[i];
		if (c >= '0' && c <= '9')
			value = c - '0';
		else if (c >= 'a' && c <= 'f')
			value = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			value = c - 'A' + 10;
		else
			return (-1);
		color = (color << 4) | value;
		i++;
	}
	return (create_color(color));
}

int	search_color(char	*point)
{
	int		i;
	int		color;

	i = 0;
	color = 0;
	if (ft_strchr(point, ','))
	{
		while (point[i] != ',')
			i++;
		if (point[i] == '\0')
			return (0xFFFFFF);
		color = parse_color(&point[i]);
	}
	i = 0;
	/*while (point[i])
	{
		free(point[i]);
		i++;
	}*/
	//free(point);
	return (color);
}
