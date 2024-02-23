#include "ft_printf.h"

int ft_pointer(void *p)
{
    int len;
    unsigned long int num;
    char *base;

    base = "0123456789abcdef";
    len = 0;
    len += ft_print_str("0x");
    num = (unsigned long int)p;
    if (num == 0)
    {
        len += ft_print_car('0');
        return (len);
    }
    len += ft_print_hexadecimal(num, base);
    return (len);
}