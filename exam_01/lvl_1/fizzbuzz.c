/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:31:56 by alphbarr          #+#    #+#             */
/*   Updated: 2024/03/27 21:46:28 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	n = n % 10 + '0';
	write (1, &n, 1);
}

void	fizzbuzz(int n)
{
	while (n <= 100)
    {
        if (n % 3 == 0 && n % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (n % 3 == 0)
            write(1, "fizz", 4);
        else if (n % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_putnbr(n);
        write(1, "\n", 1);
        n++;
    }
}

int	main(void)
{
	int	i = 1;
	fizzbuzz(i);
	return (0);
}
