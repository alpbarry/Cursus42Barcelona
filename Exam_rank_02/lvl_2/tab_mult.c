#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	n = (n % 10) + '0';
	ft_putchar(n);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

void	mult(int n)
{
	int	i;

	i = 1;
	while (i < 10 && n <= 238609183)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(i * n);
		ft_putchar('\n');
		i++;
	}
}

int	main(int ac, char **av)
{
	int	 n = ft_atoi(av[1]);
	
	if (ac == 2)
		mult(n);
	else
		ft_putchar('\n');
	return (0);
}
