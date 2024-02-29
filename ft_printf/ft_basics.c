/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:23:06 by alphbarr          #+#    #+#             */
/*   Updated: 2024/02/29 14:19:37 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_print_char(int c)
{
    write(1, &c, 1);
    return (1);
}

int ft_print_str(char *str)
{
    int len;

    len = 0;
    if (str == NULL)
        return (ft_print_str("(null)"));
    while (str[len])
    {
        len += ft_print_char(str[len]);
    }
    return (len);
}

int ft_print_nbr(int n)
{
    int len;

    len = 0;
    if (n == 0)
    {
        len += ft_print_char('0');
        return (len);
    }
    if (n == -2147483648)
    {
        len += ft_print_str("-2147483648");
        return (len);
    }
    if (n < 0)
    {
        len += ft_print_char('-');
        n = -n;
    }
    if (n > 0)
    {
        len += ft_print_unsigned(n);
    }
    return (len);
}

int ft_print_unsigned(unsigned int n)
{
    int len;

    len = 0;
    if (!n)
    {
        len += ft_print_char('0');
        return (len);
    }
    if (n / 10)
        ft_print_unsigned(n / 10);
    ft_print_char(n % 10 + '0');
    while (n)
    {
        n /= 10;
        len++;
    }
    return (len);
}
