/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:22:33 by vinograd          #+#    #+#             */
/*   Updated: 2024/05/07 21:47:58 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(char *error)
{
	ft_printf("%s\n", error);
	exit(1);
}

int	MAX(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	MOD(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}
