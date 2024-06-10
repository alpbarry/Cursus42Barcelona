#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (*s);
}

void	sar(char *f, char *s, char *t)
{
	int	i;

	i = 0;
	while (f[i])
	{
		if (f[i] == s[0])
		{
			f[i] = t[0];
			i++;
		}
		else
			i++;
	}
	ft_putstr(f);
	ft_putchar('\n');
}

int	main(int ac, char **av)
{
	if (ac == 4)
		sar(av[1], av[2], av[3]);
	else
		ft_putchar('\n');
	return (0);
}
