/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:41:08 by alphbarr          #+#    #+#             */
/*   Updated: 2024/04/22 20:04:21 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector	create_vector(float x, float y, float z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_matrix	create_matrix(t_vector vx, t_vector vy, t_vector vz)
{
	t_matrix	matrix;

	matrix.vx = vx;
	matrix.vy = vy;
	matrix.vz = vz;
	return (matrix);
}

t_vector	vector_x_matrix(t_vector v, t_matrix m)
{
	t_vector	n_v;

	n_v.x = v.x * m.vx.x + v.y * m.vy.x + v.z * m.vz.x;
	n_v.y = v.x * m.vx.y + v.y * m.vy.y + v.z * m.vz.y;
	n_v.z = v.x * m.vx.z + v.y * m.vy.z + v.z * m.vz.z;
	return (n_v);
}
