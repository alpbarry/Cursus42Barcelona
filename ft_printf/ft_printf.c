/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:23:38 by alphbarr          #+#    #+#             */
/*   Updated: 2024/02/28 10:53:36 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_printf(const char *f, ...)
{
    va_list args;
    int len;
    int i;

    len = 0;
    i = 0;
    va_start(args, f);
    while (f[i])
    {
        if (f[i] == '%')
        {
            i++;
            if (f[i] == 'c')
                len += ft_print_char(va_arg(args, int));
            if (f[i] == 's')
                len += ft_print_str(va_arg(args, char *));
            if (f[i] == 'd' || f[i] == 'i')
                len += ft_print_nbr(va_arg(args, int));
            if (f[i] == 'u')
                len += ft_print_unsigned(va_arg(args, unsigned int));
            if (f[i] == 'x')
                len += ft_print_hexadecimal(va_arg(args, unsigned int), 'x');
            if (f[i] == 'X')
                len += ft_print_hexadecimal(va_arg(args, unsigned int), 'X');
            if (f[i] == 'p')
                len += ft_print_pointer(va_arg(args, unsigned long long));
        }
        else
            len += ft_print_char(f[i]);
        i++;
    }
    va_end(args);
    return (len);
}

int main()
{
    char *str = "Hello, World!";
    int num = 12345;
    unsigned int unum = 12345;
    unsigned long long ptr = (unsigned long long)&num;

    ft_printf(" %s\n ", NULL);
	printf(" %s\n ", NULL);
    ft_printf("Number: %d\n", num);
    ft_printf("Unsigned number: %u\n", unum);
    ft_printf("Hexadecimal number (lowercase): %x\n", unum);
    ft_printf("Hexadecimal number (uppercase): %X\n", unum);
    ft_printf("Pointer: %p\n", ptr);

    return (0);
}
