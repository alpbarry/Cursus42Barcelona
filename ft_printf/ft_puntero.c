/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puntero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:40:33 by alphbarr          #+#    #+#             */
/*   Updated: 2024/02/28 10:07:39 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_is_pointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_is_pointer(ptr / 16);
		ft_is_pointer(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_print_char(ptr + '0');
		else
			ft_print_char(ptr - 10 + 'a');
	}
}

int	ft_len_pointer(unsigned long long ptr)
{
	int	l;

	l = 0;
	while (ptr > 0)
	{
		ptr /= 16;
		l++;
	}
	return (l);
}

int ft_print_pointer(unsigned long long ptr)
{
	int	l;

	l = ft_print_str("0x");
	if (ptr == 0)
		l += ft_print_char('0');
	else
	{
		ft_is_pointer(ptr);
		l += ft_len_pointer(ptr);
	}
	return (l);
}
