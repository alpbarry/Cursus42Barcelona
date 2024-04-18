/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:11:01 by alphbarr          #+#    #+#             */
/*   Updated: 2024/04/18 19:30:50 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

int	create_trgb(int p, int c, int mc)
{
	int	d;

	d = mc - c;
	c = c + d * p / 100;
	return (c);
}

int	create_color(int p, int c, int mc)
{
	int	nt;
	int	nr;
	int	ng;
	int	nb;
	int	nc;

	if (c == mc)
		return (c);
	nt = create_trgb(p, c >> 24 & 255, mc >> 24 & 255);
	nr = create_trgb(p, c >> 16 & 255, mc >> 16 & 255);
	ng = create_trgb(p, c >> 8 & 255, mc >> 8 & 255);
	nb = create_trgb(p, c & 255, mc & 255);
	nc = nt << 24 | nr << 16 | ng << 8 | nb;
		return (nc);
}
