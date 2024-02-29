/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:23:38 by alphbarr          #+#    #+#             */
/*   Updated: 2024/02/29 14:05:57 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_print_arg(const char *f, int i, va_list args)
{
    int len;

    len = 0;
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
    if (f[i] == '%')
        len += ft_print_char('%');

    return len;
}

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
            len += ft_print_arg(f, i, args);
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
    int a;
    int b;
    char *str = "Hello, World!";
    int num = 12345;
    unsigned int unum = 12345;
    unsigned long long ptr = (unsigned long long)&num;

    ft_printf("%s\n", (char *)NULL);
	b = printf(" %d ", -10);
    printf("\n");
    a = ft_printf(" %d ", -10);
    printf("\n");
    printf("mi printf devuelve: %d\n", a);
    printf("printf original devuelve: %d\n", b);
    ft_printf("Unsigned number: %u\n", unum);
    ft_printf("Hexadecimal number (lowercase): %x\n", unum);
    ft_printf("Hexadecimal number (uppercase): %X\n", unum);
    ft_printf("Pointer: %p\n", ptr);

    return (0);
}
