#include <unistd.h>

int	ft_atoi(char *s)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (s[i])
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	n = (n % 10) + '0';
	ft_putchar(n);
}

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	add_prime(unsigned int	n)
{
	int	s;

	s = 0;
	while (n > 0)
	{
		if(ft_is_prime(n))
			s += n;
		n--;
	}
	ft_putnbr(s);
	ft_putchar('\n');
}

int	main(int ac, char **av)
{
	int n = ft_atoi(av[1]);
	if (ac == 2)
		add_prime(n);
	else
		ft_putchar('\n');
	return (0);
}
