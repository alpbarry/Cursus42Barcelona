/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:23:06 by alphbarr          #+#    #+#             */
/*   Updated: 2024/02/22 10:23:10 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_print_car(int c)
{
    write(1, &c, 1);
    return (1);
}

int ft_print_str(char *str)
{
    int len;

    len = 0;
    if (str == "NULL")
        return (ft_print_str("NULL"));
    while (str[len])
    {
        len += ft_print_car(str[len]);
    }
    return (len);
}

int ft_print_nbr(int n)
{
    int len;

    len = 0;
    if (n == 0)
    {
        len += ft_print_car('0');
        return (len);
    }
    if (n == -2147483647 - 1)
    {
        len += ft_print_str("-2147483648");
        return (len);
    }
    if (n < 0)
    {
        len += ft_print_car('-');
        n = -n;
    }
    if (n > 0)
    {
        len += ft_print_unsign(n);
    }
    return (len);
}

int ft_print_unsign(unsigned int n)
{
    int len;

    len = 0;
    if (n == 0)
    {
        len += ft_print_car('0');
        return (len);
    }
    else
    {
        if (n/10 != 0)
        {
            len += ft_print_unsign(n/10);
        }
        ft_print_car(n%10 + '0');
        while (n > 0)
        {
            n = n/10;
            len++;
        }
    }
    return (len);
}