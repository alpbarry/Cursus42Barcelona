#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char w)
{
	write (1, &w, 1);
}

void	print_bits(unsigned char octet)
{
	int	i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1);
		ft_putchar(bit + '0');
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		// Convertir el argumento de línea de comandos a un entero
		int n = atoi(av[1]);
		// Asegurarse de que el entero está dentro del rango de un unsigned char
		if (n >= 0 && n <= 255)
			print_bits((unsigned char)n);
		else
			write(1, "Input out of range\n", 19);
	}
	else
	{
		write(1, "Usage: ./a.out <number>\n", 24);
	}
	return (0);
}
