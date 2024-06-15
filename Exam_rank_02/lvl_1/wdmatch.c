#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int	wdmatch(char *f, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && f[j])
	{
		if (s[i] == f[j])
			j++;
		i++;
	}
	return  (f[j] == '\0');
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (wdmatch(av[1], av[2]))
			ft_putstr(av[1]);
	}
	ft_putchar('\n');
	return (0);
}
