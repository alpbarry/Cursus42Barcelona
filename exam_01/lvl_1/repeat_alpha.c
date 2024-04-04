/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:30:53 by alphbarr          #+#    #+#             */
/*   Updated: 2024/03/28 11:38:58 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void    ft_putchar_n(char c, int i)
{
    while (i > 0)
    {
        write(1, &c, 1);
        --i;
    }
}

void    repeat_alpha(char *str)
{
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
            ft_putchar_n(*str, *str + 1 - 'a');
        else if (*str >= 'A' && *str <= 'Z')
            ft_putchar_n(*str, *str + 1 - 'A');
        else
            write(1, str, 1);
        ++str;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        repeat_alpha(av[1]);
    
    write(1, "\n", 1);
    return (0);
}
