#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	hiden(char *f, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (f[i] && s[j])
	{
		if (s[j] == f[i])
			i++;
		j++;
	}
	if (f[i] == '\0')
		ft_putchar('1');
	else
		ft_putchar('0');
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		hiden(av[1], av[2]);
		ft_putchar('\n');
	}
	else
		ft_putchar('\n');
	return (0);
}
