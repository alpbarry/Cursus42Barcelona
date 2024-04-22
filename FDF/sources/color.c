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
/*
int main() {
    int nc = 0xFF0000; 

    int new_color = create_color(nc);
    printf("Nuevo color: %X\n", new_color);

    return 0;
}*/
