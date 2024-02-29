/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:57:10 by alphbarr          #+#    #+#             */
/*   Updated: 2024/02/29 14:11:13 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_is_hexadecimal(unsigned int num, char word)
{
    if (num >= 16)
    {
        ft_is_hexadecimal(num / 16, word);
        ft_is_hexadecimal(num % 16, word);
    }
    else
    {
        if (num < 10)
            ft_print_char(num + '0');
        else
        {
            if (word == 'x')
                ft_print_char(num - 10 + 'a');
            if (word == 'X')
                ft_print_char(num - 10 + 'A');
        }
    }
}

int ft_len_hexadecimal(unsigned int num)
{
    int len;

    len = 0;
    if (num == 0)
        return (1);
    while (num)
    {
        num = num / 16;
        len++;
    }
    return (len);
}

int ft_print_hexadecimal(unsigned int num, char word)
{
    if (num == 0)
    {
        return (ft_print_char('0'));
    }
    else
        ft_is_hexadecimal(num, word);
    return (ft_len_hexadecimal(num));

